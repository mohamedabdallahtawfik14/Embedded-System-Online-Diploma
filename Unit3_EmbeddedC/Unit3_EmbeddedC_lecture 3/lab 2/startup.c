/*
	startup.c
	Mohamed Abdallah
*/
#include "platform_Types.h"
#define stack_pointer 0x20001000
//prototypes
void Reset_Handler();
void Default_Handler()
{
	Reset_Handler();
}
//weak to allow overriding, alias to make all take one defination untill we overwrite it.
void NMI_Handler() __attribute__((weak, alias("Default_Handler")));
void H_Fault_Handler() __attribute__((weak, alias("Default_Handler")));
void MM_Fault_Handler() __attribute__((weak, alias("Default_Handler")));
void Bus_Fault() __attribute__((weak, alias("Default_Handler")));
void Usage_Fault_Handler() __attribute__((weak, alias("Default_Handler")));

extern uint32 _stack_top;

uint32 vectors[] __attribute__((section(".vectors"))) =
{
	(uint32) &_stack_top,
	(uint32) &Reset_Handler,
	(uint32) &NMI_Handler,
	(uint32) &H_Fault_Handler,
	(uint32) &MM_Fault_Handler,
	(uint32) &Bus_Fault,
	(uint32) &Usage_Fault_Handler,
};
//symbols
extern uint32 _E_text;
extern uint32 _S_data;
extern uint32 _E_data;
extern uint32 _S_bss;
extern uint32 _E_bss;

void Reset_Handler()
{
	uint32 i;
	//copy data from flash to sram
	uint32 DATA_size = (uint8*)&_E_data - (uint8*)&_S_data;
	uint8 *p_src = (uint8*)&_E_text;
	uint8 *p_dst = (uint8*)&_S_data;
	for (i = 0; i < DATA_size; ++i)
	{
		/* copying */
		*((uint8*)p_dst++) = *((uint8*)p_src++);
	}
	//init bss section in sram with 0
	uint32 BSS_size = (uint8*)&_E_bss - (uint8*)&_S_bss;
	p_src = (uint8*)&_S_bss;
	for (i = 0; i < DATA_size; ++i)
	{
		/* intialize with 0 */
		*((uint8*)p_dst++) = (uint8)0;
	}
	//branch to main
	main();
}
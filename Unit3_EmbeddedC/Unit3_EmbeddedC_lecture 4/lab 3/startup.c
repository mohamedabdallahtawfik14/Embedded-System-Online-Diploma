/*
	startup.c
	Mohamed Abdallah
*/
#include "platform_Types.h"
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

//reserve stack size 1024B
static uint32 stack_top[256]; //256 * 4 = 1024B;

void (* const g_p_f_vectors[])() __attribute__((section(".vectors"))) =
{
	(void(*)()) (uint32)stack_top + sizeof(stack_top),
	&Reset_Handler,
	&NMI_Handler,
	&H_Fault_Handler,
	&MM_Fault_Handler,
	&Bus_Fault,
	&Usage_Fault_Handler,
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
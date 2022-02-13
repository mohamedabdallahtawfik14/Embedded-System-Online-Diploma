#include "platform_Types.h"

#define CTL_BASE 	0x400FE000
#define GPIOF_BASE 	0x40025000
#define SYSCTL_RCGC2_R 		*(vuint32_t*)(CTL_BASE + 0x108)
#define GPIO_PORTF_DIR_R 	*(vuint32_t*)(GPIOF_BASE + 0x400)
#define GPIO_PORTF_DEN_R 	*(vuint32_t*)(GPIOF_BASE + 0x51C)
#define GPIO_PORTF_DATA_R 	*(vuint32_t*)(GPIOF_BASE + 0x3FC)

int main(void)
{
	vuint32_t delay_count;
	SYSCTL_RCGC2_R = 0x20;

	//delay for (GPIO upping and running)
	for (delay_count = 0; delay_count < 200; ++delay_count)
	{
		/* delay */
	}
	GPIO_PORTF_DIR_R |= 1<<3; //set 1 to set it as output direction
	GPIO_PORTF_DEN_R |= 1<<3; //enable portf
	while(1)
	{
		GPIO_PORTF_DATA_R |= 1<<3; // write 1 on pin3 //led on
		for (delay_count = 0; delay_count < 200; ++delay_count); //delay
		GPIO_PORTF_DATA_R &= ~(1<<3); //write 0 on pin3 //led off
		for (delay_count = 0; delay_count < 200; ++delay_count); //delay
	}
	return 0;
}
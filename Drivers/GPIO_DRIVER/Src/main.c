/**
 ******************************************************************************
 * @file           : main.c
 * @author         : mohamed
 * @brief          : Application program body
 ******************************************************************************
 */
//incs
#include "Stm32F103C6_GPIO_Driver.h"
#include "Stm32F103x6.h"

void clock_init(void)
{
	//enable clock for GPIOA
	GPIOA_CLOCK_EN();
	//enable clock for GPIOB
	GPIOB_CLOCK_EN();

}
void gpio_init()
{
	GPIO_PinConfig_t pinConfig;

	//PinA1 input floating (highZ)
	pinConfig.GPIO_MODE = GPIO_MODE_INPUT_FLO;
	pinConfig.GPIO_PinNumber = GPIO_PIN_1;
	MCAL_GPIO_Init(GPIOA, &pinConfig);

	//PinB1 output push-pull mode
	pinConfig.GPIO_MODE = GPIO_MODE_OUTPUT_PP;
	pinConfig.GPIO_PinNumber = GPIO_PIN_1;
	pinConfig.GPIO_Output_Speed = GPIO_SPEED_10M;
	MCAL_GPIO_Init(GPIOB, &pinConfig);

	//PinA13 input floating (highZ)
	pinConfig.GPIO_MODE = GPIO_MODE_INPUT_FLO;
	pinConfig.GPIO_PinNumber = GPIO_PIN_13;
	MCAL_GPIO_Init(GPIOA, &pinConfig);

	//PinB13 output push-pull mode
	pinConfig.GPIO_MODE = GPIO_MODE_OUTPUT_PP;
	pinConfig.GPIO_PinNumber = GPIO_PIN_13;
	pinConfig.GPIO_Output_Speed = GPIO_SPEED_10M;
	MCAL_GPIO_Init(GPIOB, &pinConfig);
}
void wait(vuint32_t x)
{
	vuint32_t i, j;
	for (i = 0; i < x; ++i)
		for (j = 0; j < 255; ++j);
}
int main(void)
{
	clock_init();
	gpio_init();
	while(1)
	{
		// push button on PinA1

		if(MCAL_GPIO_ReadPin(GPIOA, GPIO_PIN_1)== GPIO_PIN_RESET) //pressed
		{
			//toggle led on PinB1
			MCAL_GPIO_TogglePin(GPIOB, GPIO_PIN_1);
			//single press
			while(MCAL_GPIO_ReadPin(GPIOA, GPIO_PIN_1)== GPIO_PIN_RESET);
		}
		// push button on PinA13
		if(MCAL_GPIO_ReadPin(GPIOA, GPIO_PIN_13)== GPIO_PIN_SET) // pressed
		{
			//toggle led on PinB13
			MCAL_GPIO_TogglePin(GPIOB, GPIO_PIN_13);
		}
		wait(1);
	}
}

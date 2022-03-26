/*
 * Stm32F103C6_GPIO.c
 *
 *  Created on: Mar 25, 2022
 *      Author: Mohamed
 */
#include "Stm32F103C6_GPIO_Driver.h"
#include "Stm32F103x6.h"
#include "platform_Types.h"

uint8 Get_CRLH_Position(uint16 PinNumber)
{
	switch(PinNumber)
	{
	case GPIO_PIN_0:
	{
		return 0;
	}
	break;
	case GPIO_PIN_1:
	{
		return 4;
	}
	break;
	case GPIO_PIN_2:
	{
		return 8;
	}
	break;
	case GPIO_PIN_3:
	{
		return 12;
	}
	break;
	case GPIO_PIN_4:
	{
		return 16;
	}
	break;
	case GPIO_PIN_5:
	{
		return 20;
	}
	break;
	case GPIO_PIN_6:
	{
		return 24;
	}
	break;
	case GPIO_PIN_7:
	{
		return 28;
	}
	break;
	case GPIO_PIN_8:
	{
		return 0;
	}
	break;
	case GPIO_PIN_9:
	{
		return 4;
	}
	break;
	case GPIO_PIN_10:
	{
		return 8;
	}
	break;
	case GPIO_PIN_11:
	{
		return 12;
	}
	break;
	case GPIO_PIN_12:
	{
		return 16;
	}
	break;
	case GPIO_PIN_13:
	{
		return 20;
	}
	break;
	case GPIO_PIN_14:
	{
		return 24;
	}
	break;
	case GPIO_PIN_15:
	{
		return 28;
	}
	break;
	default:
	{
		return 30;
	}
	break;
	}
}
/**================================================================
 * @Fn              -MCAL_GPIO_Init
 * @brief           -Initializes the GPIOx PINy according to the specified parameters in the PinConfig
 * @param [in]      -GPIOx: where x can be (A..E depending on device used) to select the GPIO peripheral
 * @param [in]      -PinConfig: pointer to GPIO_PinConfig_t structure that contains the configuration
 *                   information for the specified  GPIO PIN
 * @retval          -none
 * Note             -STM32F103C6 MCU has GPIO A, B, C, D, E Modules
 *                   But LQFP48 package has only GPIO A, B, PART of C&D exported as external PINS from the MCU
 */
void MCAL_GPIO_Init(GPIO_TypeDef* GPIOx, GPIO_PinConfig_t* PinConfig)
{
	uint32 pinConfig = 0;
	//Port configuration register low (GPIOx_CRL) configure PINS from 0 >> 7
	//Port configuration register high (GPIOx_CRH) configure PINS from 8 >> 15
	vuint32_t* configReg = NULL;
	configReg = (PinConfig->GPIO_PinNumber < GPIO_PIN_8)? &GPIOx-> CRL : &GPIOx-> CRH;

	//clear CNF8[1:0] MODE[1:0]
	(*configReg) &= ~ (0x0F << Get_CRLH_Position(PinConfig->GPIO_PinNumber));

	//if pin is output
	switch(PinConfig->GPIO_MODE)
	{
	case GPIO_MODE_OUTPUT_AF_OD:
	case GPIO_MODE_OUTPUT_AF_PP:
	case GPIO_MODE_OUTPUT_OD:
	case GPIO_MODE_OUTPUT_PP:
	{
		pinConfig = ((((PinConfig->GPIO_MODE - 4) << 2) | (PinConfig->GPIO_Output_Speed)) & 0x0F);
	}
	break;
	default: // not output (input) //MODE = 00: Input mode (reset state)
		switch(PinConfig->GPIO_MODE)
		{
		case GPIO_MODE_INPUT_FLO:
		case GPIO_MODE_Analog:
		{
			pinConfig = ((PinConfig->GPIO_MODE << 2) & 0x0F);
		}
		break;
		case GPIO_MODE_AF_INPUT:
		{
			pinConfig = ((GPIO_MODE_INPUT_FLO << 2) & 0x0F); //treated as input floating
		}
		break;
		case GPIO_MODE_INPUT_PD:
		case GPIO_MODE_INPUT_PU:
		{
			pinConfig = ((GPIO_MODE_INPUT_PU << 2) & 0x0F);
			switch(PinConfig->GPIO_MODE) //PU PD Input
			{
			case GPIO_MODE_INPUT_PU:
			{
				//PxODR = 1 Input Pull-Up, Table 20. Port bit configuration table
				GPIOx->ODR |= PinConfig->GPIO_PinNumber;
			}
			break;
			case GPIO_MODE_INPUT_PD:
			{
				//PxODR = 0 Input Pull-Down, Table 20. Port bit configuration table
				GPIOx->ODR &= ~(PinConfig->GPIO_PinNumber);
			}
			break;
			}
		}
		break;
		}
	}
	//Write on the CRL or CRH
	(*configReg) |= (pinConfig << Get_CRLH_Position(PinConfig->GPIO_PinNumber));
}

/**================================================================
 * @Fn              -MCAL_GPIO_DeInit
 * @brief           -reset all the GPIO Registers
 * @param [in]      -GPIOx: where x can be (A..E depending on device used) to select the GPIO peripheral
 * @retval          -none
 * Note             -none
 */
void MCAL_GPIO_DeInit(GPIO_TypeDef* GPIOx)
{
	if(GPIOx == GPIOA)
	{
		//		Set and cleared by software.
		//		0: No effect
		//		1: Reset GPIOA
		RCC->APB2RSTR |= (1<<2);
		RCC->APB2RSTR &= ~(1<<2);
	}
	else if(GPIOx == GPIOB)
	{
		//		Set and cleared by software.
		//		0: No effect
		//		1: Reset GPIOB
		RCC->APB2RSTR |= (1<<3);
		RCC->APB2RSTR &= ~(1<<3);
	}
	else if(GPIOx == GPIOC)
	{
		//		Set and cleared by software.
		//		0: No effect
		//		1: Reset GPIOC
		RCC->APB2RSTR |= (1<<4);
		RCC->APB2RSTR &= ~(1<<4);
	}
	else if(GPIOx == GPIOD)
	{
		//		Set and cleared by software.
		//		0: No effect
		//		1: Reset GPIOD
		RCC->APB2RSTR |= (1<<5);
		RCC->APB2RSTR &= ~(1<<5);
	}
	else if(GPIOx == GPIOE)
	{
		//		Set and cleared by software.
		//		0: No effect
		//		1: Reset GPIOE
		RCC->APB2RSTR |= (1<<6);
		RCC->APB2RSTR &= ~(1<<6);
	}
}

/**================================================================
 * @Fn              -MCAL_GPIO_ReadPin
 * @brief           -read specific PIN
 * @param [in]      -GPIOx: where x can be (A..E depending on device used) to select the GPIO peripheral
 * @param [in]      -PinNumber: set pin Number according @ref GPIO_PINS_define
 * @retval          -the input pin value (Two values based on @ref GPIO_PINS_state)
 * Note             -none
 */
uint8 MCAL_GPIO_ReadPin(GPIO_TypeDef* GPIOx, uint16 PinNumber)
{
	return (GPIOx->IDR & PinNumber)? (uint8)GPIO_PIN_SET : (uint8)GPIO_PIN_RESET;
}

/**================================================================
 * @Fn              -MCAL_GPIO_ReadPort
 * @brief           -read specific PORT
 * @param [in]      -GPIOx: where x can be (A..E depending on device used) to select the GPIO peripheral
 * @param [in]      -PinNumber: set pin Number according @ref GPIO_PINS_define
 * @retval          -the input port value
 * Note             -none
 */
uint16 MCAL_GPIO_ReadPort(GPIO_TypeDef* GPIOx)
{
	return (uint16)GPIOx->IDR;
}

/**================================================================
 * @Fn              -MCAL_GPIO_WritePin
 * @brief           -write specific input PIN
 * @param [in]      -GPIOx: where x can be (A..E depending on device used) to select the GPIO peripheral
 * @param [in]      -PinNumber: specifies the port bit to read @ref GPIO_PINS_define
 * @param [in]      -Value: pin Value
 * @retval          -none
 * Note             -none
 */
void MCAL_GPIO_WritePin(GPIO_TypeDef* GPIOx, uint16 PinNumber, uint8 value)
{
//	Bits 15:0 BSy: Port x Set bit y (y= 0 .. 15)
//	These bits are write-only and can be accessed in Word mode only.
//	0: No action on the corresponding ODRx bit
//	1: Set the corresponding ODRx bit

//	Bits 15:0 BRy: Port x Reset bit y (y= 0 .. 15)
//	These bits are write-only and can be accessed in Word mode only.
//	0: No action on the corresponding ODRx bit
//	1: Reset the corresponding ODRx bit
	(value == GPIO_PIN_SET)? (GPIOx->BSRR = (uint32)PinNumber):(GPIOx->BRR = (uint32)PinNumber);
}

/**================================================================
 * @Fn              -MCAL_GPIO_WritePort
 * @brief           -write on output PORT
 * @param [in]      -GPIOx: where x can be (A..E depending on device used) to select the GPIO peripheral
 * @retval          -none
 * Note             -none
 */
void MCAL_GPIO_WritePort(GPIO_TypeDef* GPIOx, uint16 value)
{
	GPIOx->ODR = (uint32)value;
}

/**================================================================
 * @Fn              -MCAL_GPIO_TogglePin
 * @brief           -Toggles the specified GPIO pin
 * @param [in]      -GPIOx: where x can be (A..E depending on device used) to select the GPIO peripheral
 * @param [in]      -PinNumber: specifies the port bit to read, according @ref GPIO_PINS_define
 * @retval          -none
 * Note             -none
 */
void MCAL_GPIO_TogglePin(GPIO_TypeDef* GPIOx, uint16 PinNumber)
{
	GPIOx->ODR ^= (uint32)PinNumber;
}

/**================================================================
 * @Fn              -MCAL_GPIO_LockPin
 * @brief           -the locking mechanism allows the IO configuration to be frozen
 * @param [in]      -GPIOx: where x can be (A..E depending on device used) to select the GPIO peripheral
 * @param [in]      -PinNumber: specifies the port bit to read, according @ref GPIO_PINS_define
 * @retval          -(OK)>> if pin Config is locked, or (ERROR)>> if pin is not locked, defined @ref GPIO_RETURN_LOCK
 * Note             -none
 */
uint8 MCAL_GPIO_LockPin(GPIO_TypeDef* GPIOx, uint16 PinNumber)
{
//	Bit 16 LCKK[16]: Lock key
//	This bit can be read anytime. It can only be modified using the Lock Key Writing Sequence.
//	0: Port configuration lock key not active
//	1: Port configuration lock key active. GPIOx_LCKR register is locked until the next reset.
//	LOCK key writing sequence:
//	Write 1
//	Write 0
//	Write 1
//	Read 0
//	Read 1 (this read is optional but confirms that the lock is active)
//	Note: During the LOCK Key Writing sequence, the value of LCK[15:0] must not change.
	vuint16_t seq = PinNumber | 0x10;
	//write 1
	GPIOx->LCKR |= seq;
	//write 0
	GPIOx->LCKR |= PinNumber;
	//write 1
	GPIOx->LCKR |= seq;
	//read
	seq = GPIOx->LCKR;
	return ((uint32)GPIOx->LCKR & (1<<16))? (uint8)GPIO_RETURN_LOCK_ENABLED : (uint8)GPIO_RETURN_LOCK_ERROR;


}

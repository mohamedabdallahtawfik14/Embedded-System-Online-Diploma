/*
 * Stm32F103C6_GPIO_DRIVER.h
 *
 *  Created on: Mar 25, 2022
 *      Author: Mohamed
 */

#ifndef INC_STM32F103C6_GPIO_DRIVER_H_
#define INC_STM32F103C6_GPIO_DRIVER_H_

//-----------------------------
//Includes
//-----------------------------
#include "Stm32F103x6.h"

//GPIO PIN Configuration Structure
typedef struct
{
	uint16 GPIO_PinNumber;		 //specifies the GPIO pins to be configured
	                         	 //This parameter must be set based on a value of @ref GPIO_PINS_define

	uint8 GPIO_MODE;       		//specifies the GPIO operation mode for the selected pin
		                     	//This parameter must be set based on a value of @ref GPIO_MODE_define

	uint8 GPIO_Output_Speed;    //specifies the speed for the selected pin
   			                    //This parameter can be a value of @ref GPIO_SPEED_define


}GPIO_PinConfig_t;

//@ref GPIO_PINS_state
#define GPIO_PIN_SET     1
#define GPIO_PIN_RESET   0

//@ref GPIO_RETURN_LOCK
#define GPIO_RETURN_LOCK_ENABLED     1
#define GPIO_RETURN_LOCK_ERROR       0
//===============================
//Macros Configuration References
//===============================

//@ref GPIO_PINS_define
#define GPIO_PIN_0            ((uint16)0x0001) /* Pin 0   selected */
#define GPIO_PIN_1            ((uint16)0x0002) /* Pin 1   selected  10 */
#define GPIO_PIN_2            ((uint16)0x0004) /* Pin 2   selected  100*/
#define GPIO_PIN_3            ((uint16)0x0008) /* Pin 3   selected  1000*/
#define GPIO_PIN_4            ((uint16)0x0010) /* Pin 4   selected  10000*/
#define GPIO_PIN_5            ((uint16)0x0020) /* Pin 5   selected */
#define GPIO_PIN_6            ((uint16)0x0040) /* Pin 6   selected */
#define GPIO_PIN_7            ((uint16)0x0080) /* Pin 7   selected */
#define GPIO_PIN_8            ((uint16)0x0100) /* Pin 8   selected */
#define GPIO_PIN_9            ((uint16)0x0200) /* Pin 9   selected */
#define GPIO_PIN_10           ((uint16)0x0400) /* Pin 10  selected */
#define GPIO_PIN_11           ((uint16)0x0800) /* Pin 11  selected */
#define GPIO_PIN_12           ((uint16)0x1000) /* Pin 12  selected */
#define GPIO_PIN_13           ((uint16)0x2000) /* Pin 13  selected */
#define GPIO_PIN_14           ((uint16)0x4000) /* Pin 14  selected */
#define GPIO_PIN_15           ((uint16)0x8000) /* Pin 15  selected */
#define GPIO_PIN_All          ((uint16)0xFFFF) /* Pin All selected */

#define GPIO_PIN_MASK          0x0000FFFFu       /*PIN mask for assert test*/

//@ref GPIO_MODE_define
//In Input mode:
//0: Analog mode
//1: Floating input (reset state)
//2: Input with pull-up
//3: Input with pull-down
//In output mode:
//4: General purpose output push-pull
//5: General purpose output Open-drain
//6: Alternate function output Push-pull
//7: Alternate function output Open-drain
//8: Alternate function INPUT
#define GPIO_MODE_Analog              0x00000000u //Analog mode
#define GPIO_MODE_INPUT_FLO           0x00000001u //Floating input
#define GPIO_MODE_INPUT_PU            0x00000002u //Input with pull-up
#define GPIO_MODE_INPUT_PD            0x00000003u //Input with pull-down
#define GPIO_MODE_OUTPUT_PP           0x00000004u //General purpose output push-pull
#define GPIO_MODE_OUTPUT_OD           0x00000005u //General purpose output Open-drain
#define GPIO_MODE_OUTPUT_AF_PP        0x00000006u //Alternate function output Push-pull
#define GPIO_MODE_OUTPUT_AF_OD        0x00000007u //Alternate function output Open-drain
#define GPIO_MODE_AF_INPUT            0x00000008u //Alternate function INPUT

//@ref GPIO_SPEED_define
//1: Output mode, max speed 10 MHz.
//2: Output mode, max speed 2 MHz.
//3: Output mode, max speed 50 MHz.
#define GPIO_SPEED_10M     0x00000001u   //Output mode, max speed 10 MHz
#define GPIO_SPEED_20M     0x00000002u   //Output mode, max speed 2 MHz
#define GPIO_SPEED_50M     0x00000003u   //Output mode, max speed 50 MHz

/* * ===============================================
* APIs Supported by "MCAL GPIO DRIVER"
*  * ===============================================
*/

void MCAL_GPIO_Init(GPIO_TypeDef* GPIOx, GPIO_PinConfig_t* PinConfig);
void MCAL_GPIO_DeInit(GPIO_TypeDef* GPIOx);
uint8 MCAL_GPIO_ReadPin(GPIO_TypeDef* GPIOx, uint16 PinNumber);
uint16 MCAL_GPIO_ReadPort(GPIO_TypeDef* GPIOx);
void MCAL_GPIO_WritePin(GPIO_TypeDef* GPIOx, uint16 PinNumber, uint8 value);
void MCAL_GPIO_WritePort(GPIO_TypeDef* GPIOx, uint16 value);
void MCAL_GPIO_TogglePin(GPIO_TypeDef* GPIOx, uint16 PinNumber);
uint8 MCAL_GPIO_LockPin(GPIO_TypeDef* GPIOx, uint16 PinNumber);

#endif /* INC_STM32F103C6_GPIO_DRIVER_H_ */

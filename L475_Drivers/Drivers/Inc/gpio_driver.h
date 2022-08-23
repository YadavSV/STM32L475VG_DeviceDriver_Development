/*
 * gpio_driver.h
 *
 *  Created on: 17-Aug-2022
 *      Author: Yadav SV
 */

#ifndef INC_GPIO_DRIVER_H_
#define INC_GPIO_DRIVER_H_


#include "l475dh.h"

typedef struct
{

	uint8_t GPIO_PinNumber;
	uint8_t GPIO_PinMode;
	uint8_t GPIO_PinSpeed;
	uint8_t GPIO_PinPuPd_cont;
	uint8_t GPIO_PinOPtype;
	uint8_t GPIO_PinAltFunMode;

}GPIO_PinConfig_t;


/*
 * This is a handle structure for GPIO pin
 */

typedef struct
{
	// Pointer is required to hold the base address of the GPIO Peripheral
	GPIO_RegDef_t *pGPIOx;   				// This holds the base address of the GPIO port to which the pin belongs
	GPIO_PinConfig_t GPIO_PinConfig;		// this holds the GPIO pin configuration settings

}GPIO_Handle_t;

/*
 * GPIO Pin Possible modes
 */
#define GPIO_MODE_IN	 	0
#define GPIO_MODE_OUT		1
#define GPIO_MODE_ALTFN		2
#define GPIO_MODE_ANALOG 	3
#define GPIO_MODE_IT_FT		4
#define GPIO_MODE_IT_RT		5
#define GPIO_MODE_IT_RFT	6

/*
 * GPIO Pin Possible output types
 */

#define GPIO_OP_TYPE_PP 	0
#define GPIO_OP_TYPE_OD 	1


/*
 * GPIO Pin Possible Output speeds
 */
#define GPIO_SPEED_LOW		0
#define GPIO_SPEED_MEDIUM	1
#define GPIO_SPEED_FAST		2
#define GPIO_SPEED_HIHG		3


/*
 * GPIO Pin Pull Up & Pull Down Configuration macros
 */

#define GPIO_NO_PUPD		0
#define GPIO_PIN_PU			1
#define GPIO_PIN_PD			2

/*
 * GPIO Possible PIN Number
 */
#define GPIO_PIN_0			0
#define GPIO_PIN_1			1
#define GPIO_PIN_2			2
#define GPIO_PIN_3			3
#define GPIO_PIN_4			4
#define GPIO_PIN_5			5
#define GPIO_PIN_6			6
#define GPIO_PIN_7			7
#define GPIO_PIN_8			8
#define GPIO_PIN_9			9
#define GPIO_PIN_10			10
#define GPIO_PIN_11			11
#define GPIO_PIN_12			12
#define GPIO_PIN_13			13
#define GPIO_PIN_14			14
#define GPIO_PIN_15			15


/*************************************************************************************************************
 *									API's Supported by this driver
 *					For more information about the API's Check the function definitions
 *************************************************************************************************************/

/*
 * Clock Setup
 */

void GPIO_PeriClkCont(GPIO_RegDef_t *pGPIOx, uint8_t EnorDI);

/*
 * Init and DeInit
 */
void GPIO_Init(GPIO_Handle_t *pGPIOHandle);

void GPIO_DeInit(GPIO_RegDef_t *pGPIOx);

/*
 * Read and Write
 */
uint8_t GPIO_ReadInputPin(GPIO_RegDef_t *pGPIOx, uint8_t PinNumber);

uint16_t GPIO_ReadInputPort(GPIO_RegDef_t *pGPIOx);

void GPIO_WriteOutputPin(GPIO_RegDef_t *pGPIOx, uint8_t PinNumber, uint8_t Value);

void GPIO_WriteOutputPort(GPIO_RegDef_t *pGPIOx, uint16_t Value);

void GPIO_ToggleOutputPin(GPIO_RegDef_t *pGPIOx, uint8_t PinNumber);

/*
 * IRQ Configuration and Handling
 */

void GPIO_IRQConfig(uint8_t IRQNumber, uint8_t IRQPriority, uint8_t EnorDi);

void GPIO_IRQHandling(uint8_t PinNumber);

#endif /* INC_GPIO_DRIVER_H_ */

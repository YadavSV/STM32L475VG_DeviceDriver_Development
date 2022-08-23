/*
 * gpio_driver.c
 *
 *  Created on: 17-Aug-2022
 *      Author: Yadav SV
 */

#include "gpio_driver.h"


/****************************************************************************************************
 * @fn				- GPIO_PeriClkCont
 *
 * @brief			- This function enables or disables the clock for given GPIO port
 *
 * @parameter[in]	- Base Address of the GPIO Peripherals
 * @parameter[in]	- Enable or Disable MACROs
 * @parameter[in]	-
 *
 * @return			- None
 *
 * @Note			- None
 *
 */

RCC_RegDef_t *rcc = (RCC_RegDef_t *)RCC_BASE;
void GPIO_PeriClkCont(GPIO_RegDef_t *pGPIOx, uint8_t EnorDI)
{
	if (EnorDI == ENABLE)
	{
		if (pGPIOx == GPIOA)
		{
//			rcc->AHB2ENR |= (1 << 0);
//			RCC->AHB2ENR |= (1 << 0);
			GPIOA_PCLK_EN();
		}
		else if (pGPIOx == GPIOB)
		{
			GPIOB_PCLK_EN();
		}
		else if (pGPIOx == GPIOC)
		{
			GPIOC_PCLK_EN();
		}
		else if (pGPIOx == GPIOD)
		{
			GPIOD_PCLK_EN();
		}
		else if (pGPIOx == GPIOE)
		{
			GPIOE_PCLK_EN();
		}
		else if (pGPIOx == GPIOF)
		{
			GPIOF_PCLK_EN();
		}
		else if (pGPIOx == GPIOG)
		{
			GPIOG_PCLK_EN();
		}
		else if (pGPIOx == GPIOH)
		{
			GPIOH_PCLK_EN();
		}
		else if (pGPIOx == GPIOI)
		{
			GPIOI_PCLK_EN();
		}
	}
	else
	{
		if (pGPIOx == GPIOA)
		{
			GPIOA_PCLK_DI();
		}
		else if (pGPIOx == GPIOB)
		{
			GPIOB_PCLK_DI();
		}
		else if (pGPIOx == GPIOC)
		{
			GPIOC_PCLK_DI();
		}
		else if (pGPIOx == GPIOD)
		{
			GPIOD_PCLK_DI();
		}
		else if (pGPIOx == GPIOE)
		{
			GPIOE_PCLK_DI();
		}
		else if (pGPIOx == GPIOF)
		{
			GPIOF_PCLK_DI();
		}
		else if (pGPIOx == GPIOG)
		{
			GPIOG_PCLK_DI();
		}
		else if (pGPIOx == GPIOH)
		{
			GPIOH_PCLK_DI();
		}
		else if (pGPIOx == GPIOI)
		{
			GPIOI_PCLK_DI();
		}
	}
}


/****************************************************************************************************
 * @fn				- GPIO_Init
 *
 * @brief			- This function Initialize the given GPIO port
 *
 * @parameter[in]	- GPIOx is given which is required to initialize
 * @parameter[in]	-
 *
 * @return			- None
 *
 * @Note			- None
 *
 */

void GPIO_Init(GPIO_Handle_t *pGPIOHandle)
{

	if(pGPIOHandle->GPIO_PinConfig.GPIO_PinMode <= GPIO_MODE_ANALOG)     // this checks the entered mode is non-interrupt mode
	{

		// This take care of the MODE Register
		pGPIOHandle->pGPIOx->MODER &= ~(0x3 << (2*pGPIOHandle->GPIO_PinConfig.GPIO_PinNumber));
		//		pGPIOHandle->pGPIOx->MODER |= temp;
		pGPIOHandle->pGPIOx->MODER |= (pGPIOHandle->GPIO_PinConfig.GPIO_PinMode << (2*pGPIOHandle->GPIO_PinConfig.GPIO_PinNumber));

		// This take care of the Output Type Register
//		temp = (pGPIOHandle->GPIO_PinConfig.GPIO_PinOPtype <<(pGPIOHandle->GPIO_PinConfig.GPIO_PinNumber));
		pGPIOHandle->pGPIOx->OTYPER &= ~(0x1 << pGPIOHandle->GPIO_PinConfig.GPIO_PinNumber);
		pGPIOHandle->pGPIOx->OTYPER |= (pGPIOHandle->GPIO_PinConfig.GPIO_PinOPtype <<(pGPIOHandle->GPIO_PinConfig.GPIO_PinNumber));

		// This take care of the Output Speed Register
//		temp = (pGPIOHandle->GPIO_PinConfig.GPIO_PinSpeed << (2* pGPIOHandle->GPIO_PinConfig.GPIO_PinNumber));
		pGPIOHandle->pGPIOx->OSPEEDR &= ~(0x3 << (2*pGPIOHandle->GPIO_PinConfig.GPIO_PinNumber));
		pGPIOHandle->pGPIOx->OSPEEDR |= (pGPIOHandle->GPIO_PinConfig.GPIO_PinSpeed << (2* pGPIOHandle->GPIO_PinConfig.GPIO_PinNumber));

		// This take care of the Pull-Up and Pull-Down Register
//		temp = (pGPIOHandle->GPIO_PinConfig.GPIO_PinPuPd_cont << (2* pGPIOHandle->GPIO_PinConfig.GPIO_PinNumber));
		pGPIOHandle->pGPIOx->PUPDR &= ~(0x3 << (2* pGPIOHandle->GPIO_PinConfig.GPIO_PinNumber));
		pGPIOHandle->pGPIOx->PUPDR |= (pGPIOHandle->GPIO_PinConfig.GPIO_PinPuPd_cont << (2* pGPIOHandle->GPIO_PinConfig.GPIO_PinNumber));


		if (pGPIOHandle->GPIO_PinConfig.GPIO_PinMode == GPIO_MODE_ALTFN)
			{

				uint32_t temp1,temp2;

				temp1 = (pGPIOHandle->GPIO_PinConfig.GPIO_PinNumber / 8);
				temp2 = (pGPIOHandle->GPIO_PinConfig.GPIO_PinNumber % 8);
				pGPIOHandle->pGPIOx->AFR[temp1] &= ~(0xf << pGPIOHandle->GPIO_PinConfig.GPIO_PinAltFunMode);
				pGPIOHandle->pGPIOx->AFR[temp1] |= (pGPIOHandle->GPIO_PinConfig.GPIO_PinAltFunMode << (4 * temp2));
			}
	}
	else
	{
		// This is interrupt mode
		if(pGPIOHandle->GPIO_PinConfig->GPIO_PinMode == GPIO_MODE_IT_FT)
		{
			//Configure Falledge trigger Register
		}
		else if (pGPIOHandle->GPIO_PinConfig->GPIO_PinMode == GPIO_MODE_IT_RT)
		{
			//Configure Raisingedge trigger Register
		}
		else if (pGPIOHandle->GPIO_PinConfig->GPIO_PinMode == GPIO_MODE_IT_RFT)
		{
			//Configure Both trigger Register
		}
	}

	}



/****************************************************************************************************
 * @fn				- GPIO_DeInit
 *
 * @brief			- This function De-Initialize the given GPIO port
 *
 * @parameter[in]	- GPIOx is given which is required to Reset
 * @parameter[in]	-
 *
 * @return			- None
 *
 * @Note			- None
 *
 */
void GPIO_DeInit(GPIO_RegDef_t *pGPIOx)
{
	if (pGPIOx == GPIOA)
	{
		GPIOA_REG_RESET();
	}
	else if (pGPIOx == GPIOB)
	{
		GPIOB_REG_RESET();
	}
	else if (pGPIOx == GPIOC)
	{
		GPIOC_REG_RESET();
	}
	else if (pGPIOx == GPIOD)
	{
		GPIOD_REG_RESET();
	}
	else if (pGPIOx == GPIOE)
	{
		GPIOE_REG_RESET();
	}
	else if (pGPIOx == GPIOF)
	{
		GPIOF_REG_RESET();
	}
	else if (pGPIOx == GPIOG)
	{
		GPIOG_REG_RESET();
	}
	else if (pGPIOx == GPIOH)
	{
		GPIOH_REG_RESET();
	}
	else if (pGPIOx == GPIOI)
	{
		GPIOI_REG_RESET();
	}

}


/****************************************************************************************************
 * @fn				- GPIO_ReadInputPin
 *
 * @brief			- This function Reads the Data from the given GPIO Pin
 *
 * @parameter[in]	- GPIOx name through which the Data is required to read
 * @parameter[in]	- GPIO's Pin Number through which the Data is required to read
 *
 * @return			- Unsigned Int of 8 bits
 *
 * @Note			- None
 *
 */
uint8_t GPIO_ReadInputPin(GPIO_RegDef_t *pGPIOx, uint8_t PinNumber)
{
	uint8_t value;

	value = (uint8_t)((pGPIOx->IDR >> PinNumber) & 0x00000001);

	return value;
}

/****************************************************************************************************
 * @fn				- GPIO_ReadInputPort
 *
 * @brief			- This function Reads the Data from the given GPIO's entire Port
 *
 * @parameter[in]	- GPIOx Port name through which the Data is required to read
 * @parameter[in]	-
 *
 * @return			- Unsigned Int of 16 bits
 *
 * @Note			- None
 *
 */
uint16_t GPIO_ReadInputPort(GPIO_RegDef_t *pGPIOx)
{
	uint16_t value;

	value = (uint16_t)pGPIOx->IDR;

	return value;
}

/****************************************************************************************************
 * @fn				- GPIO_WriteOutputPin
 *
 * @brief			- This function Writes the Data from the given GPIO Pin
 *
 * @parameter[in]	- GPIOx name through which the Data is required to send
 * @parameter[in]	- GPIO's Pin Number through which the Data is required to send
 *
 * @return			- None
 *
 * @Note			- None
 *
 */
void GPIO_WriteOutputPin(GPIO_RegDef_t *pGPIOx, uint8_t PinNumber, uint8_t Value)
{
	if(Value == SET)
	{
		pGPIOx->ODR |= (1 << PinNumber);
	}
	else
	{
		pGPIOx->ODR &= ~(1 << PinNumber);
	}
}

/****************************************************************************************************
 * @fn				- GPIO_WriteOutputPort
 *
 * @brief			- This function Write the Data from the given GPIO's entire Port
 *
 * @parameter[in]	- GPIOx Port name through which the Data is required to Write
 * @parameter[in]	- Value which is required  to send
 *
 * @return			- None
 *
 * @Note			- None
 *
 */
void GPIO_WriteOutputPort(GPIO_RegDef_t *pGPIOx, uint16_t Value)
{
	pGPIOx->ODR = Value;
}

void GPIO_ToggleOutputPin(GPIO_RegDef_t *pGPIOx, uint8_t PinNumber)
{
	pGPIOx->ODR ^= (1 << PinNumber);
}

/*
 * IRQ Configuration and Handling
 */

void GPIO_IRQConfig(uint8_t IRQNumber, uint8_t IRQPriority, uint8_t EnorDi)
{

}

void GPIO_IRQHandling(uint8_t PinNumber)
{


}

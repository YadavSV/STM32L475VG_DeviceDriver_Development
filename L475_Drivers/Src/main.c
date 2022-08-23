/*
 * main.c
 *
 *  Created on: 18-Aug-2022
 *      Author: Yadav SV
 */

#include "l475dh.h"
#include "gpio_driver.h"

int Delay(void)
{
	for(uint32_t i = 0; i < 50000 ; i++ );
	return 0;
}


int main(void)
{
	GPIO_Handle_t GPIO_Led; //Created a GPIO_Led structure
	GPIO_Led.pGPIOx = GPIOB; //
	GPIO_Led.GPIO_PinConfig.GPIO_PinNumber = GPIO_PIN_14;

	GPIO_Led.GPIO_PinConfig.GPIO_PinMode = GPIO_MODE_OUT;
	GPIO_Led.GPIO_PinConfig.GPIO_PinSpeed = GPIO_SPEED_MEDIUM;
	GPIO_Led.GPIO_PinConfig.GPIO_PinOPtype = GPIO_OP_TYPE_PP;
	GPIO_Led.GPIO_PinConfig.GPIO_PinPuPd_cont= GPIO_NO_PUPD;

	GPIO_Handle_t GPIO_Switch; //Created a GPIO_Led structure
	GPIO_Switch.pGPIOx = GPIOC; //
	GPIO_Switch.GPIO_PinConfig.GPIO_PinNumber = GPIO_PIN_13;

	GPIO_Switch.GPIO_PinConfig.GPIO_PinMode = GPIO_MODE_IN;
//	GPIO_Switch.GPIO_PinConfig.GPIO_PinSpeed = GPIO_SPEED_MEDIUM;
//	GPIO_Switch.GPIO_PinConfig.GPIO_PinPuPd_cont= GPIO_NO_PUPD;

	GPIO_PeriClkCont(GPIOC, ENABLE);
	GPIO_PeriClkCont(GPIOB, ENABLE);

	GPIO_Init(&GPIO_Led);
	GPIO_Init(&GPIO_Switch);

	while(1)
	{
		uint32_t in_sw = GPIO_ReadInputPin(GPIOC, GPIO_PIN_13);
		if(in_sw==0)
		{
			Delay();  // To overcome the problem of switch debouncing
			GPIO_ToggleOutputPin(GPIOB, GPIO_PIN_14);
		}

//		else
//		{
//			GPIO_WriteOutputPin(GPIOB, GPIO_PIN_14, 0);
//		}
//		GPIO_ToggleOutputPin(GPIOB, GPIO_PIN_14);

//		Delay(); // Software Delay
	}
	return 0;
}


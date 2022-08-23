/*
 * l475dh.h
 *
 *  Created on: Aug 16, 2022
 *      Author: Yadav SV
 *
 *
 *   l475dh.h This file is a device specific header file for STM32L475VG
 *	 Which includes all the register (addresses) mapped with the MACROS.
 *	 To avoid the complexity of programming with register addresses.
 *
 */


#include "stdint.h"
#define __vo volatile

#ifndef INC_L475DH_H_
#define INC_L475DH_H_

// Generic MACRO's

#define ENABLE  	1
#define DISABLE 	0
#define SET 		ENABLE
#define RESET 		DISABLE


#define FLASH_BASE		 		0x08000000U		/* Base Address/ Starting address of Flash memory */
#define SRAM1_BASE				0x20000000U		/* Base Address/ Starting address of SRAM1 memory */
#define SRAM2_BASE				0x20018000U		/* Base Address/ Starting address of SRAM2 memory */
#define SRAM_BASE				SRAM1_BASE
#define ROM_BASE		 		0x1FFF0000U		/* Base Address/ Starting address of ROM/ System memory */

/* Base Addresses of Peripherals AHBx & APBx */
#define Peri_BASE				0x40000000U
#define APB1_BASE				Peri_BASE
#define APB2_BASE				0x40010000U
#define AHB1_BASE				0x40020000U
#define AHB2_BASE				0x48000000U

/* Base addresses of Peripherals that are Hanging on AHB2 Bus*/

#define RCC_BASE				(AHB1_BASE + 0x1000U)

#define GPIOA_BASE				(AHB2_BASE + 0x0000U)
#define GPIOB_BASE				(AHB2_BASE + 0x0400U)
#define GPIOC_BASE				(AHB2_BASE + 0x0800U)
#define GPIOD_BASE				(AHB2_BASE + 0x0C00U)
#define GPIOE_BASE				(AHB2_BASE + 0x1000U)
#define GPIOF_BASE				(AHB2_BASE + 0x1400U)
#define GPIOG_BASE				(AHB2_BASE + 0x1800U)
#define GPIOH_BASE				(AHB2_BASE + 0x1C00U)
#define GPIOI_BASE				(AHB2_BASE + 0x2000U)
#define OTG_FS_BASE				0x50000000U
#define ADC_BASE				(OTG_FS_BASE + 0x40000U)
#define DCMI_BASE				0x50050000U
#define AES_BASE				0x50060000U
#define HASH_BASE				(AES_BASE + 0x0400)
#define RNG_BASE				(AES_BASE + 0x0800)

/* Base Addresses of Peripherals that are hanging on APB1 Bus */

#define I2C1_BASE				(APB1_BASE + 0x5400U)
#define I2C2_BASE				(APB1_BASE + 0x5800U)
#define I2C3_BASE				(APB1_BASE + 0x5C00U)
#define I2C4_BASE				(APB1_BASE + 0x8400U)
#define SPI2_BASE				(APB1_BASE + 0x3800U)
#define SPI3_BASE				(APB1_BASE + 0x3C00U)
#define USART2_BASE				(APB1_BASE + 0x4400U)
#define USART3_BASE				(APB1_BASE + 0x4800U)
#define UART4_BASE				(APB1_BASE + 0x4C00U)
#define UART5_BASE				(APB1_BASE + 0x5000U)

/*
 * Base Addresses of Peripherals that are hanging on APB2 Bus
 */

#define EXIT_BASE				(APB2_BASE + 0x0400U)
#define USART1_BASE				0x40013800U
#define SPI1_BASE				0x40013000U
#define SYSCFG_BASE				(APB2_BASE + 0x0000)

/*   GPIO Structure for Mode Registers */

typedef struct
{
	__vo uint32_t MODER;			//GPIO port mode register
	__vo uint32_t OTYPER;			//GPIO port output type register
	__vo uint32_t OSPEEDR;			//GPIO port output speed register
	__vo uint32_t PUPDR;			//GPIO port pull-up/pull-down register
	__vo uint32_t IDR;				//GPIO port input data register
	__vo uint32_t ODR;				//GPIO port output data register
	__vo uint32_t BSRR;				//GPIO port bit set/reset register
	__vo uint32_t LCKR;				//GPIO port configuration lock register
	__vo uint32_t AFR[2];			//AFR[0]:GPIO alternate function low register & AFR[1]:GPIO alternate function high register
	__vo uint32_t BRR;				//GPIO port bit reset register
	__vo uint32_t ASCR;				//GPIO port analog switch control register

}GPIO_RegDef_t;

/*
 * Peripherals definitions for GPIO's
 */

#define GPIOA 			((GPIO_RegDef_t*)GPIOA_BASE)
#define GPIOB 			((GPIO_RegDef_t*)GPIOB_BASE)
#define GPIOC 			((GPIO_RegDef_t*)GPIOC_BASE)
#define GPIOD 			((GPIO_RegDef_t*)GPIOD_BASE)
#define GPIOE 			((GPIO_RegDef_t*)GPIOE_BASE)
#define GPIOF 			((GPIO_RegDef_t*)GPIOF_BASE)
#define GPIOG 			((GPIO_RegDef_t*)GPIOG_BASE)
#define GPIOH 			((GPIO_RegDef_t*)GPIOH_BASE)
#define GPIOI 			((GPIO_RegDef_t*)GPIOI_BASE)

/*
 * Structure for RCC Register member elements
 */

typedef struct
{
	__vo uint32_t CR;
	__vo uint32_t ICSCR;
	__vo uint32_t CFGR;
	__vo uint32_t PLLCFGR;
	__vo uint32_t PLLSAI_CFGER[2];
	__vo uint32_t CIER;
	__vo uint32_t CIFR;
	__vo uint32_t CICR;
	__vo uint32_t RESERVED0;
	__vo uint32_t AHB1RSTR;
	__vo uint32_t AHB2RSTR;
	__vo uint32_t AHB3RSTR;
	__vo uint32_t RESERVED1;
	__vo uint32_t APB1RSTR[2];
	__vo uint32_t APB2RSTR;
	__vo uint32_t RESERVED2;
	__vo uint32_t AHB1ENR;
	__vo uint32_t AHB2ENR;
	__vo uint32_t AHB3ENR;
	__vo uint32_t RESERVED3;
	__vo uint32_t APB1ENR1;
	__vo uint32_t APB1ENR2;
	__vo uint32_t APB2ENR;
	__vo uint32_t RESERVED4;
	__vo uint32_t AHB1SMENR;
	__vo uint32_t AHB2SMENR;
	__vo uint32_t AHB3SMENR;
	__vo uint32_t RESERVED5;
	__vo uint32_t APB1SMENR1;
	__vo uint32_t APB1SMENR2;
	__vo uint32_t APB2SMENR;
	__vo uint32_t RESERVED6;
	__vo uint32_t CCIPR;
	__vo uint32_t RESERVED7;
	__vo uint32_t BDCR;
	__vo uint32_t CSR;
	__vo uint32_t CRRCR;
	__vo uint32_t CCIPR2;

}RCC_RegDef_t;

#define RCC ((RCC_RegDef_t*)RCC_BASE)

/*
 * MACROS FOR ENABLE THE CLOCK FOR GPIOx PERIPHERALS
 */

#define GPIOA_PCLK_EN() (RCC->AHB2ENR |= (1 << 0))
#define GPIOB_PCLK_EN() (RCC->AHB2ENR |= (1 << 1))
#define GPIOC_PCLK_EN() (RCC->AHB2ENR |= (1 << 2))
#define GPIOD_PCLK_EN() (RCC->AHB2ENR |= (1 << 3))
#define GPIOE_PCLK_EN() (RCC->AHB2ENR |= (1 << 4))
#define GPIOF_PCLK_EN() (RCC->AHB2ENR |= (1 << 5))
#define GPIOG_PCLK_EN() (RCC->AHB2ENR |= (1 << 6))
#define GPIOH_PCLK_EN() (RCC->AHB2ENR |= (1 << 7))
#define GPIOI_PCLK_EN() (RCC->AHB2ENR |= (1 << 8))

/*
 * MACROS FOR ENABLE THE CLOCK FOR I2Cx PERIPHERILES
 */

#define I2C1_PCLK_EN() (RCC->APB1ENR1 |= (1 << 21))
#define I2C2_PCLK_EN() (RCC->APB1ENR1 |= (1 << 22))
#define I2C3_PCLK_EN() (RCC->APB1ENR1 |= (1 << 23))
#define I2C4_PCLK_EN() (RCC->APB1ENR2 |= (1 << 1))

/*
 * MACROS FOR ENABLE THE CLOCK FOR SPIx PERIPHERALS
 */

#define SPI1_PCLK_EN() (RCC->APB2ENR  |= (1 << 12))
#define SPI2_PCLK_EN() (RCC->APB1ENR1 |= (1 << 14))
#define SPI3_PCLK_EN() (RCC->APB1ENR1 |= (1 << 15))

/*
 * MACROS FOR ENABLE THE CLOCK FOR UARTx PERIPHERALS
 */

#define USART1_PCLK_EN() (RCC->APB2ENR  |= (1 << 14))
#define USART2_PCLK_EN() (RCC->APB1ENR1 |= (1 << 17))
#define USART3_PCLK_EN() (RCC->APB1ENR1 |= (1 << 18))
#define USART4_PCLK_EN() (RCC->APB1ENR1 |= (1 << 19))
#define USART5_PCLK_EN() (RCC->APB1ENR1 |= (1 << 20))

/*
 * MACROS FOR ENABLE THE CLOCK FOR SYSCFG PERIPHERILS
 */

#define SYSCFG_PCLK_EN() (RCC->APB2ENR |= (1 << 0))


/*
 * MACROS FOR DISABLE THE CLOCK FOR GPIOx PERIPHERALS
 */

#define GPIOA_PCLK_DI() (RCC->AHB2ENR &= ~(1 << 0))
#define GPIOB_PCLK_DI() (RCC->AHB2ENR &= ~(1 << 1))
#define GPIOC_PCLK_DI() (RCC->AHB2ENR &= ~(1 << 2))
#define GPIOD_PCLK_DI() (RCC->AHB2ENR &= ~(1 << 3))
#define GPIOE_PCLK_DI() (RCC->AHB2ENR &= ~(1 << 4))
#define GPIOF_PCLK_DI() (RCC->AHB2ENR &= ~(1 << 5))
#define GPIOG_PCLK_DI() (RCC->AHB2ENR &= ~(1 << 6))
#define GPIOH_PCLK_DI() (RCC->AHB2ENR &= ~(1 << 7))
#define GPIOI_PCLK_DI() (RCC->AHB2ENR &= ~(1 << 8))

/*
 * MACROS FOR DISABLE THE CLOCK FOR I2Cx PERIPHERALS
 */

#define I2C1_PCLK_DI() (RCC->APB1ENR1 &= ~(1 << 21))
#define I2C2_PCLK_DI() (RCC->APB1ENR1 &= ~(1 << 22))
#define I2C3_PCLK_DI() (RCC->APB1ENR1 &= ~(1 << 23))
#define I2C4_PCLK_DI() (RCC->APB1ENR2 &= ~(1 << 1))

/*
 * MACROS FOR DISABLE THE CLOCK FOR SPIx PERIPHERALS
 */

#define SPI1_PCLK_DI() (RCC->APB2ENR  &= ~(1 << 12))
#define SPI2_PCLK_DI() (RCC->APB1ENR1 &= ~(1 << 14))
#define SPI3_PCLK_DI() (RCC->APB1ENR1 &= ~(1 << 15))

/*
 * MACROS FOR DISABLE THE CLOCK FOR UARTx PERIPHERALS
 */

#define USART1_PCLK_DI() (RCC->APB2ENR  &= ~(1 << 14))
#define USART2_PCLK_DI() (RCC->APB1ENR1 &= ~(1 << 17))
#define USART3_PCLK_DI() (RCC->APB1ENR1 &= ~(1 << 18))
#define USART4_PCLK_DI() (RCC->APB1ENR1 &= ~(1 << 19))
#define USART5_PCLK_DI() (RCC->APB1ENR1 &= ~(1 << 20))

/*
 * MACROS FOR DISABLE THE CLOCK FOR SYSCFG PERIPHERALS
 */

#define SYSCFG_PCLK_DI() (RCC->APB2ENR &= ~(1 << 0))

/*
 * MACROS FOR RESET GPIOx PERIPHERALS
 */

// Used do while condition-zero loop for RESETING the peripherals clock register.

#define GPIOA_REG_RESET()	do {(RCC->AHB2RSTR  |= (1 << 0)); (RCC->AHB2RSTR  &= ~(1 << 0));} while (0)
#define GPIOB_REG_RESET()	do {(RCC->AHB2RSTR  |= (1 << 1)); (RCC->AHB2RSTR  &= ~(1 << 1));} while (0)
#define GPIOC_REG_RESET()	do {(RCC->AHB2RSTR  |= (1 << 2)); (RCC->AHB2RSTR  &= ~(1 << 2));} while (0)
#define GPIOD_REG_RESET()	do {(RCC->AHB2RSTR  |= (1 << 3)); (RCC->AHB2RSTR  &= ~(1 << 3));} while (0)
#define GPIOE_REG_RESET()	do {(RCC->AHB2RSTR  |= (1 << 4)); (RCC->AHB2RSTR  &= ~(1 << 4));} while (0)
#define GPIOF_REG_RESET()	do {(RCC->AHB2RSTR  |= (1 << 5)); (RCC->AHB2RSTR  &= ~(1 << 5));} while (0)
#define GPIOG_REG_RESET()	do {(RCC->AHB2RSTR  |= (1 << 6)); (RCC->AHB2RSTR  &= ~(1 << 6));} while (0)
#define GPIOH_REG_RESET()	do {(RCC->AHB2RSTR  |= (1 << 7)); (RCC->AHB2RSTR  &= ~(1 << 7));} while (0)
#define GPIOI_REG_RESET()	do {(RCC->AHB2RSTR  |= (1 << 8)); (RCC->AHB2RSTR  &= ~(1 << 8));} while (0)



#endif /* INC_L475DH_H_ */

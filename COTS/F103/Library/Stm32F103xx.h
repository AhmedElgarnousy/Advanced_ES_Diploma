#ifndef STM32F103XX_H_
#define STM32F103XX_H_

/************* Various Memories Base Addresses***************/

/************* AHB Peripherals Base Addresses***************/
#define RCC_BASE_ADDRESS 0x40021000UL

/************* APB1 Peripherals Base Addresses***************/

/************* APB2 Peripherals Base Addresses***************/

#define GPIOA_BASE_ADDRESS 0x40010800UL
#define GPIOB_BASE_ADDRESS 0x40010C00UL
#define GPIOC_BASE_ADDRESS 0x40011000UL
#define GPIOD_BASE_ADDRESS 0x40011400UL
#define GPIOE_BASE_ADDRESS 0x4001800UL
#define GPIOF_BASE_ADDRESS 0x40011C00UL
#define GPIOG_BASE_ADDRESS 0x40012000UL

/************* RCC Registers Definition Structure***************/
typedef struct
{
    uint32_t CR;       /*   Clock Control Register                 */
    uint32_t CFGR;     /*   Clock Configuration                    */
    uint32_t CIR;      /*   Clock Iterrupt Register                */
    uint32_t APB2RSTR; /*   APB2 peripheral reset Register         */
    uint32_t APB1RSTR; /*   APB1 peripheral reset register         */
    uint32_t AHBENR;   /*   AHB  peripheral clock enable register  */
    uint32_t APB2ENR;  /*   APB2 peripheral clock enable register  */
    uint32_t APB1ENR;  /*   APB1 peripheral clock enable register  */
    uint32_t BDCR;     /*   Backup domain control register         */
    uint32_t CSR;      /*   Control/status register                */
} RCC_register_t;

/************* RCC Peripheral Definition ***************/

RCC_register_t *RCC = (RCC_register_t *)RCC_BASE_ADDRESS;

// #define RCC ((RCC_register_t *)RCC_BASE_ADDRESS) // another way

/************* GPIO Registers Definition Structure ***************/

typedef struct
{
    volatile uint32_t CR[2]; /* Port Configuration Register         */
    volatile uint32_t IDR;   /* Port Intput Data Register           */
    volatile uint32_t ODR;   /* Port Output Data Register           */
    volatile uint32_t BSRR;  /* Port Bit Set/Reset Register         */
    volatile uint32_t BRR;   /* Port Reset Register                 */
    volatile uint32_t LCKR;  /* Port Configuration Lock Register    */
} GPIO_RegDef_t;

/************* GPIO Peripheral Definitions ***************/

#define GPIOA ((GPIO_RegDef_t *)GPIOA_BASE_ADDRESS)
#define GPIOB ((GPIO_RegDef_t *)GPIOB_BASE_ADDRESS)
#define GPIOC ((GPIO_RegDef_t *)GPIOC_BASE_ADDRESS)
#define GPIOD ((GPIO_RegDef_t *)GPIOD_BASE_ADDRESS)
#define GPIOE ((GPIO_RegDef_t *)GPIOE_BASE_ADDRESS)
#define GPIOF ((GPIO_RegDef_t *)GPIOF_BASE_ADDRESS)
#define GPIOG ((GPIO_RegDef_t *)GPIOG_BASE_ADDRESS)

#endif /* STM32F103XX_H_ */

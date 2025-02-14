#ifndef STM32F446XX_H_
#define STM32F446XX_H_

/************* Various Memories Base Addresses***************/

#define FLASH_BASE_ADDRESS 0x08000000UL
// 2 SRAM but can considered as a Big SRAM
#define SRAM_BASE_ADDRESS 0x20000000UL

// system memory constain Bootloader by ST (Read Only)
#define ROM_BASE_ADDRESS 0x1FFF0000UL

/************* AHB1 Peripherals Base Addresses***************/

/*GPIO*/
#define GPIOA_BASE_ADDRESS 0x40020000UL
#define GPIOB_BASE_ADDRESS 0x40020400UL
#define GPIOC_BASE_ADDRESS 0x40020800UL
#define GPIOD_BASE_ADDRESS 0x40020C00UL
#define GPIOE_BASE_ADDRESS 0x40021000UL
#define GPIOF_BASE_ADDRESS 0x40021400UL
#define GPIOG_BASE_ADDRESS 0x40021800UL
#define GPIOH_BASE_ADDRESS 0x40021C00UL

/*RCC*/
#define RCC_BASE_ADDRESS 0x40023800UL

/************* AHB2 Peripherals Base Addresses***************/

/************* AHB3 Peripherals Base Addresses***************/

/************* APB1 Peripherals Base Addresses***************/

/************* APB2 Peripherals Base Addresses***************/

/************* RCC Registers Definition Structure***************/
typedef struct {
    volatile uint32_t CR;          /*!<RCC Clock Control Register,  */
    volatile uint32_t PLLCFGR;     /*!<RCC PLL Configuration Register,  */
    volatile uint32_t CFGR;        /*!<RCC Clock Control Register,  */
    volatile uint32_t CIR;         /*!<RCC Clock Interrupt Register,  */
    volatile uint32_t AHB1RSTR;    /*!<RCC AHB1 Peripheral reset Register,  */
    volatile uint32_t AHB2RSTR;    /*!<RCC AHB2 Peripheral reset Register,  */
    volatile uint32_t AHB3RSTR;    /*!<RCC AHB3 Peripheral reset Register,  */
    volatile uint32_t RSERVED0;    /*!<Reserved, 0x1c,  */
    volatile uint32_t APB1RSTR;    /*!<RCC APB1 Peripheral reset Register,  */
    volatile uint32_t APB2RSTR;    /*!<RCC APB2 Peripheral reset Register,  */
    volatile uint32_t RSERVED1[2]; /*!<Reserved, 0x28-0x2c,  */
    volatile uint32_t AHB1ENR;     /*!<RCC AHB1 Peripheral Clock Register,  */
    volatile uint32_t AHB2ENR;     /*!<RCC AHB2 Peripheral Clock Register,  */
    volatile uint32_t AHB3ENR;     /*!<RCC AHB3 Peripheral Clock Register,  */
    volatile uint32_t RSERVED2;    /*!<Reserved, 0x3c,  */
    volatile uint32_t APB1ENR;     /*!<RCC APB1 Peripheral Clock Enable Register,  */
    volatile uint32_t APB1ENR;     /*!<RCC APB2 Peripheral Clock Enable Register,  */
    volatile uint32_t RSERVED3[2]; /*!<Reserved, 0x48-0x4c,  */
    volatile uint32_t AHB1LPENR;   /*!< AHB1 Peripheral Clock Enable in Low Power Mode Register,  */
    volatile uint32_t AHB2LPENR;   /*!< AHB2 Peripheral Clock Enable in Low Power Mode Register,  */
    volatile uint32_t AHB3LPENR;   /*!< AHB3 Peripheral Clock Enable in Low Power Mode Register,  */
    volatile uint32_t RESERVED4;   /*!< 0x5C,  */
    volatile uint32_t APB1LPENR;   /*!< APB1 Peripheral Clock Enable in Low Power Mode Register,  */
    volatile uint32_t APB2LPENR;   /*!< APB2 Peripheral Clock Enable in Low Power Mode Register,  */
    volatile uint32_t RESERVED[2]; /*!< Reserved, 0x68-0x6C,  */
    volatile uint32_t BDCR;        /*!< RCC Backup Domain Control Register,   */
    volatile uint32_t CSR;         /*!< RCC Clock Control & Status Register Register,  */
    volatile uint32_t RESERVED[2]; /*!< Reserved, */
    volatile uint32_t SSCGR;       /*!< RCC Spread Spectrum Clock Generation Register,  */
    volatile uint32_t PLLI2SCFGR;  /*!< RCC PLLI2S Configuration Register,  */
    volatile uint32_t PLLSAICFGR;  /*!< RCC PLLSAI Configuration Register,  */
    volatile uint32_t DCKCFGR;     /*!< RCC Dedicated Clocks ConfigurationRegister,  */
    volatile uint32_t CKGATENR;    /*!< RCC Gated Enable Register,  */
    volatile uint32_t DCKCFGR2;    /*!< RCC Dedicated Clocks Configuration Register 2,  */
} RCC_RegDef_t;

/************* RCC Peripheral Definition ***************/
#define RCC ((RCC_RegDef_t *)RCC_BASE_ADDRESS)

/************* GPIO Registers Definition Structure ***************/

typedef struct
{
    volatile uint32_t MODER;   /*GPIO PORT Mode Register */
    volatile uint32_t OTYPER;  /*GPIO PORT Output Type Register */
    volatile uint32_t OSPEEDR; /*GPIO PORT Output Speed Register */
    volatile uint32_t PUPDR;   /*GPIO PORT PULL up/ Pull down Register */
    volatile uint32_t IDR;     /*GPIO PORT Input DataRegister */
    volatile uint32_t ODR;     /*GPIO PORT Output DataRegister */
    volatile uint32_t BSRR;    /*GPIO PORT Bit Set / Reset Register */
    volatile uint32_t LCKR;    /*GPIO PORT Lock Register */
    volatile uint32_t AFR[2];  /*GPIO PORT Alternate Function Register */
} GPIO_RegDef_t;

/************* GPIO Peripheral Definitions ***************/

#define GPIOA ((GPIO_RegDef_t *)GPIOA_BASE_ADDRESS)
#define GPIOB ((GPIO_RegDef_t *)GPIOB_BASE_ADDRESS)
#define GPIOC ((GPIO_RegDef_t *)GPIOC_BASE_ADDRESS)
#define GPIOD ((GPIO_RegDef_t *)GPIOD_BASE_ADDRESS)
#define GPIOE ((GPIO_RegDef_t *)GPIOE_BASE_ADDRESS)
#define GPIOF ((GPIO_RegDef_t *)GPIOF_BASE_ADDRESS)
#define GPIOG ((GPIO_RegDef_t *)GPIOG_BASE_ADDRESS)
#define GPIOH ((GPIO_RegDef_t *)GPIOH_BASE_ADDRESS)

#endif /* STM32F446XX_H_*/

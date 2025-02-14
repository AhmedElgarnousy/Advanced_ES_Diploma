#ifndef RCC_INTERFACE_H_
#define RCC_INTERFACE_H_

//? How to make it post build configuration
#define RCC_CLK_SRC_READY_FLAG_TIMEOUT 400U

typedef enum
{
    HSI,
    HSE,
    PLL,
}RCC_ClkType;

typedef enum
{
    OFF,
    ON,
}RCC_ClkStatus;

typedef enum 
{
    DIV_BY_1,
    DIV_BY_2,
}RCC_HSE_Config;

typedef enum 
{
	X2,
	X3 = (1<<17),
	X4 = (2<<17),
	X5 = (3<<17),
	X6 = (4<<17),
	X7 = (5<<17) ,
	X8 = (6<<17),
	X9 = (7<<17),
	X10 = (8<<17),
	X11 = (9<<17),
	X12 = (10<<17),
	X13 = (11<<17),
	X14 = (12<<17),
	X15 = (13<<17),
	X16 = (14<<17),
}RCC_PLL_MUL;

typedef enum 
{
	HSI_DIV_BY_2_PLL_SRC,
	HSE_PLL_SRC,
}RCC_PLL_SRC_MUX;

typedef enum 
{
    DMA1,
    DMA2,
    SRAM,
    FLITF = 4,
    CRCE = 6,
    FSMC = 8,
    SDIO = 10,
}RCC_AHB_EN_PERIPHERAL;

typedef enum 
{
    TIM2,
    TIM3,
    TIM4,
    TIM5,
    TIM6,
    TIM7,
    TIM12,
    TIM13,
    TIM14,
    WWDG = 11,
    SPI2 = 14,
    SPI3,
    USART2 = 17,
    USART3,
    UART4,
    UART5,
    I2C1,
    I2C2,
    USB,
    CAN = 25,
    BKP = 27,
    PWR,
    DAC,
}RCC_APB1_EN_PERIPHERAL;

typedef enum 
{
    AFIO = 0,
    IOPA = 2,
    IOPB,
    IOPC,
    IOPD,
    IOPE,
    IOPF,
    IOPG,
    ADC1,
    ADC2,
    TIM1,
    SPI1,
    TIM8,
    USART,
    ADC3,
    TIM9 = 19,
    TIM10,
    TIM11,
}RCC_APB2_EN_PERIPHERAL;

// RCC RC Register Pins
enum
{
    HSI_ON,
    HSI_RDY,
    HSITRIM0 = 3,
    HSITRIM1,
    HSITRIM2,
    HSITRIM3,
    HSITRIM4,
    HSICAL0,
    HSICAL1,
    HSICAL2,
    HSICAL3,
    HSICAL4,
    HSICAL5,
    HSICAL6,
    HSICAL7,
    HSE_ON,
    HSE_RDY,
    HSE_BYP,
    CSS_ON,
    PLL_ON = 24,
    PLL_RDY,
};

// RCC_CFGR Registers Pins
enum
{
    PLLSRC = 16,
    PLLXTPRE,
};

void RCC_voidSetClkStatus(RCC_ClkType Copy_RCC_clkType, RCC_ClkStatus Copy_RCC_ClkStatus);

void RCC_voidSetSysClk(RCC_ClkType Copy_RCC_clkType);

void RCC_voidHSEConfig(RCC_HSE_Config Copy_RCC_HSE_Config);

void RCC_voidPLLConfig(RCC_PLL_MUL Copy_RCC_PLL_MUL, RCC_PLL_SRC_MUX Copy_RCC_PLL_SRC_MUX);

void RCC_voidAHBEnableClk(RCC_AHB_EN_PERIPHERAL Copy_RCC_AHB_EN_PERIPHERAL, uint8_t Copy_Enable);

void RCC_voidAPB1EnableClk(RCC_APB1_EN_PERIPHERAL Copy_RCC_APB1_EN_PERIPHERAL, uint8_t Copy_Enable);

void RCC_voidAPB2EnableClk(RCC_APB2_EN_PERIPHERAL Copy_RCC_APB2_EN_PERIPHERAL, uint8_t Copy_Enable);


#endif /* RCC_INTERFACE_H_ */

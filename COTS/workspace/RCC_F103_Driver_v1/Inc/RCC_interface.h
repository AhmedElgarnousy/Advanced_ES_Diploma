#ifndef RCC_INTERFACE_H_
#define RCC_INTERFACE_H_

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
    DIV_BY_2,
    DIV_BY_1,
}RCC_HSE_Config;

typedef enum 
{
	X2,
	X3,
	X4,
	X5,
	X6,
	X7,
	X8,
	X9,
	X10,
	X11,
	X12,
	X13,
	X14,
	X15,
	X16,
}RCC_PLL_MUL;

typedef enum 
{
	HSE_SRC,
	HSI_SRC,
}RCC_SRC_MUX;

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


void RCC_voidSetClkStatus(RCC_ClkType Copy_RCC_clkType, RCC_ClkStatus Copy_RCC_ClkStatus);

void RCC_voidSetSysClk(RCC_ClkType Copy_RCC_clkType);

void RCC_voidHSEConfig(RCC_HSE_Config Copy_RCC_HSE_Config);

void RCC_voidPLLConfig(RCC_PLL_MUL Copy_RCC_PLL_MUX, RCC_SRC_MUX Copy_RCC_SRC_MUX);

void RCC_voidAHBEnableClk(RCC_AHB_EN_PERIPHERAL Copy_RCC_AHB_EN_PERIPHERAL, uint8_t Copy_Enable);

void RCC_voidAPB1EnableClk(RCC_APB1_EN_PERIPHERAL Copy_RCC_APB1_EN_PERIPHERAL, uint8_t Copy_Enable);

void RCC_voidAPB2EnableClk(RCC_APB2_EN_PERIPHERAL Copy_RCC_APB2_EN_PERIPHERAL, uint8_t Copy_Enable);


#endif /* RCC_INTERFACE_H_ */

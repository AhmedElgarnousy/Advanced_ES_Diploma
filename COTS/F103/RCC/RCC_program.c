#include <stdint.h>
#include "BIT_MATH.h"

#include "RCC_interface.h"
#include "RCC_register.h"
#include "RCC_config.h"
#include "RCC_private.h"


RCC_register_t * RCC = (RCC_register_t*) RCC_BASE_ADDRESS;


void RCC_voidSetClkStatus(RCC_ClkType Copy_RCC_clkType, RCC_ClkStatus Copy_RCC_ClkStatus)
{
	if(Copy_RCC_clkType == HSI)
	{

	}
}
void RCC_voidSetSysClk(RCC_ClkType Copy_RCC_clkType)
{

}
void RCC_voidHSEConfig(RCC_HSE_Config Copy_RCC_HSE_Config)
{

}
void RCC_voidPLLConfig(RCC_PLL_MUL Copy_RCC_PLL_MUL, RCC_SRC_MUX Copy_RCC_SRC_MUX)
{

}

void RCC_voidAHBEnableClk(RCC_AHB_EN_PERIPHERAL Copy_RCC_AHB_EN_PERIPHERAL, uint8_t Copy_Enable)
{
	if(Copy_Enable == 1)
	{
		SET_BIT(RCC -> AHBENR, Copy_RCC_AHB_EN_PERIPHERAL);
	}
	else if(Copy_Enable == 0)
	{
		CLR_BIT(RCC -> AHBENR, Copy_RCC_AHB_EN_PERIPHERAL);
	}
	else
	{
		// error invalid input
	}
}

void RCC_voidAPB1EnableClk(RCC_APB1_EN_PERIPHERAL Copy_RCC_APB1_EN_PERIPHERAL, uint8_t Copy_Enable)
{
	if(Copy_Enable == 1)
	{
		SET_BIT(RCC -> APB1ENR, Copy_RCC_APB1_EN_PERIPHERAL);
	}
	else if(Copy_Enable == 0)
	{
		CLR_BIT(RCC -> APB1ENR, Copy_RCC_APB1_EN_PERIPHERAL);
	}
	else
	{
		// error invalid input
	}
}
void RCC_voidAPB2EnableClk(RCC_APB2_EN_PERIPHERAL Copy_RCC_APB2_EN_PERIPHERAL, uint8_t Copy_Enable)
{
	if(Copy_Enable == 1)
	{
		SET_BIT(RCC -> APB2ENR, Copy_RCC_APB2_EN_PERIPHERAL);
	}
	else if(Copy_Enable == 0)
	{
		CLR_BIT(RCC -> APB2ENR, Copy_RCC_APB2_EN_PERIPHERAL);
	}
	else
	{
		// error invalid input
	}
}

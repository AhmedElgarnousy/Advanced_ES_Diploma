#include <stdint.h>
#include "BIT_MATH.h"

#include "Stm32F103xx.h" 
#include "RCC_private.h"
#include "RCC_interface.h"

void RCC_voidSetClkStatus(RCC_ClkType Copy_RCC_clkType, RCC_ClkStatus Copy_RCC_ClkStatus)
{
	uint16_t Local_u16Timeout = 0;

	if(Copy_RCC_ClkStatus == ON)
	{
		switch (Copy_RCC_clkType)
		{
			case HSI:
				SET_BIT( RCC->CR, HSI_ON);
				while( (GET_BIT(RCC->CR, HSI_RDY) == NOT_RDY) && Local_u16Timeout != RCC_CLK_SRC_READY_FLAG_TIMEOUT)
				{
					Local_u16Timeout ++;
				}
				break;
			case HSE:
				SET_BIT( RCC->CR, HSE_ON);
				while( (GET_BIT(RCC->CR, HSE_RDY) == NOT_RDY) && Local_u16Timeout != RCC_CLK_SRC_READY_FLAG_TIMEOUT)
				{
					Local_u16Timeout ++;
				}
				break;
			case PLL:
				SET_BIT( RCC->CR, PLL_ON);
				while( (GET_BIT(RCC->CR, PLL_RDY) == NOT_RDY) && Local_u16Timeout != RCC_CLK_SRC_READY_FLAG_TIMEOUT)
				{
					Local_u16Timeout ++;
				}
				break;
			default: /* */ break;
		}
	}
	else if (Copy_RCC_ClkStatus == OFF)
	{
		switch (Copy_RCC_clkType)
		{
			case HSI: CLR_BIT( RCC->CR, HSI_ON);  break;
			case HSE: CLR_BIT( RCC->CR, HSE_ON);  break;
			case PLL: CLR_BIT( RCC->CR, PLL_ON);  break;
			default: /* */ break;
		}
	}
	else
	{
		// Invalid Copy_RCC_ClkStatus Parameter
	}

}
void RCC_voidSetSysClk(RCC_ClkType Copy_RCC_clkType)
{
	switch(Copy_RCC_clkType)
	{
		case HSI: RCC->CFGR |= RCC_CFGR_SYSLCK_SW_HSI_MASK; break;
		case HSE: RCC->CFGR |= RCC_CFGR_SYSLCK_SW_HSE_MASK; break;
		case PLL: RCC->CFGR |= RCC_CFGR_SYSLCK_SW_PLL_MASK; break;
		default : /* InValid Copy_RCC_clkType Parameter*/ break;
	}
}
void RCC_voidHSEConfig(RCC_HSE_Config Copy_RCC_HSE_Config)
{
	if(Copy_RCC_HSE_Config == DIV_BY_1)
	{
		CLR_BIT(RCC ->CFGR, PLLXTPRE);
	}
	else if(Copy_RCC_HSE_Config == DIV_BY_2)
	{
		SET_BIT(RCC ->CFGR, PLLXTPRE);
	}
	else
	{
		// invalid Copy_RCC_HSE_Config Parameter
	}
}
void RCC_voidPLLConfig(RCC_PLL_MUL Copy_RCC_PLL_MUL, RCC_PLL_SRC_MUX Copy_RCC_PLL_SRC_MUX)
{

	// clear (PLLMUL[3:0])the old  Multiplication factor configuration before
	// set Multiplication factor
	RCC->CFGR &= RCC_CFGR_PLLMUL_MASK;
	RCC->CFGR |= Copy_RCC_PLL_MUL;

	// set PLL src
	if(Copy_RCC_PLL_SRC_MUX == HSI_DIV_BY_2_PLL_SRC)
	{
		CLR_BIT( RCC->CFGR, PLLSRC);
	}
	else if(Copy_RCC_PLL_SRC_MUX == HSE_PLL_SRC)
	{
		SET_BIT( RCC->CFGR, PLLSRC);
	}
	else
	{
		// invalid Copy_RCC_PLL_SRC_MUX Parameter
	}
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

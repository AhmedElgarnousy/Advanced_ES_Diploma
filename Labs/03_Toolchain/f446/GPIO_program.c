/*********************************************************************************************************************************************************/
/*
 * @file GPIO_prog.c
 * @author Ahmed Kamal Elgarnousy
 * @brief The GPIO main source file, including functions's definitions
 *
 */

#include <stdint.h>
#include "Stm32F446xx.h"
#include "ErrType.h"

#include "GPIO_private.h"
#include "GPIO_interface.h"


static GPIO_RegDef_t* GPIO_PORT[GPIO_PERIPHERAL_NUM] = {GPIOA, GPIOB, GPIOC, GPIOD, GPIOE, GPIOF, GPIOG, GPIOH};


/*******************************************************************************
 * @fn GPIO_u8PinInit
 * @brief the function initializes the GPIO pin according to the input parameters
 * @param[in] PinConfig: the initialization values of the pin
 * @retval ErrorStatus
 *
 */
uint8_t GPIO_u8PinInit(const GPIO_PinConfig_t *PinConfig)
{
	uint8_t LocalErrorStatus = OK;

	if(PinConfig != NULL)
	{
		if( ( PinConfig -> Port  <=  PORTH ) && (PinConfig -> PinNum <= PIN15))
		{
			/* Select GPIO Mode: Input, Output, Analog, Alternate Function */
			GPIO_PORT[ PinConfig -> Port ] -> MODER &= ~(MODER_PIN_MASK << (PinConfig->PinNum  * MODER_PIN_ACCESS)); /* Clear Previous GPIO Mode Setting Bits */
			GPIO_PORT[ PinConfig -> Port ] -> MODER |=  (PinConfig -> Mode << (PinConfig->PinNum * MODER_PIN_ACCESS));

			/* Select GPIO Pull State: PULL Up, PULL Down, NO PULL(Floating)*/
			GPIO_PORT[ PinConfig -> Port ] -> PUPDR &= ~(PUPDR_PIN_MASK  << (PinConfig->PinNum  * PUPDR_PIN_ACCESS));
			GPIO_PORT[ PinConfig -> Port ] -> PUPDR |=  (PinConfig -> PullType << (PinConfig -> PinNum * PUPDR_PIN_ACCESS));

			/* Select GPIO Output-Type & Output-Speed, in case of general purpose output or alternate function: */
			if( (PinConfig -> Mode == OUTPUT) || (PinConfig -> Mode == ALTERNATE_FUNCTION))
			{
				/*Select Output-Type: Push_PULL, OPen-Drain*/
				GPIO_PORT[ PinConfig->Port]->OTYPER &= ~(OTYPER_PIN_MASK << (PinConfig -> PinNum ));
				GPIO_PORT[ PinConfig->Port]->OTYPER |= (PinConfig -> OutPutType << (PinConfig -> PinNum));

				/*Select Output-Speed: Low, medium, Fast, High */
				GPIO_PORT[ PinConfig->Port]->OSPEEDR &= ~(OSPEEDR_PIN_MASK << (PinConfig->PinNum * OSPEEDR_PIN_ACCESS));
				GPIO_PORT[ PinConfig->Port]->OSPEEDR |=  (PinConfig->Speed <<  (PinConfig->PinNum * OSPEEDR_PIN_ACCESS));

				if(PinConfig->Mode == ALTERNATE_FUNCTION)
				{
					uint8_t Local_u8RegNum = (PinConfig->PinNum) / 8U;
					uint8_t Local_uBitNum = (PinConfig->PinNum) % 8U; // each register has 8 pins, each pin has 4bits

					GPIO_PORT[ PinConfig->Port] -> AFR[Local_u8RegNum] &= ~(AFR_PIN_MASK << 	  (Local_uBitNum * AFR_PIN_ACCESS));
					GPIO_PORT[ PinConfig->Port] -> AFR[Local_u8RegNum] |=  (PinConfig->AltFunc << (Local_uBitNum * AFR_PIN_ACCESS));
				}
			}

		}
		else
		{
			LocalErrorStatus = NULL_PTR_ERR;
		}
	}
	return LocalErrorStatus;
}

/*******************************************************************************
 * @fn GPIO_u8SetPinValue
 * @brief the function outputs a certain value on an output pin
 * @param[in] Port:   specify the Port Number, get options @Port_t enum Port_t
 * @param[in] PinNum: specify the pin Number, get options @Pin_t enum PinNum
 * @param[in] PinVal: specify the output pin value, get options @PinVal_t enum PinVal
 * @retval ErrorStatus
 *
 */
uint8_t GPIO_u8SetPinValue(Port_t Port, Pin_t PinNum, PinVal_t PinVal)
{
	/* implemented with read modify write method, 3 cycle */
	uint8_t Local_u8ErrorStatus = OK;
	if( (Port  <=  PORTH ) && (PinNum <= PIN15) )
	{
		if(PinVal == PIN_LOW)
		{
			GPIO_PORT[Port] -> ODR &= ~(1 << PinNum);
			/*GPIO_PORT[Port] ->BSRR = 1 << (16 + PinNum);*/ /*with atomic set.reset bit method*/
		}
		else if(PinVal == PIN_HIGH)
		{
			GPIO_PORT[Port] -> ODR |= 1 << PinNum;
			/*GPIO_PORT[Port] ->BSRR = 1 << PinNum;*/ /*with atomic set.reset bit method , one cycle*/
		}
		else
		{
			Local_u8ErrorStatus = NOK;
		}
	}
	else
	{
		Local_u8ErrorStatus = NOK;
	}

	return Local_u8ErrorStatus;
}

/*******************************************************************************
 * @fn GPIO_u8TogglePinValue
 * @brief the function toggles the GPIO pin value
 * @param[in] Port: specify the Port Number
 * @param[in] PinNum: specify the pin Number
 * @retval ErrorStatus
 *
 */
uint8_t GPIO_u8TogglePinValue(Port_t Port, Pin_t PinNum)
{
	uint8_t Local_u8ErrorStatus = OK;

	if((Port <= PORTH ) && (PinNum <= PIN15))
	{
		GPIO_PORT[Port]->ODR ^= (1 << PinNum);
	}
	else
	{
		Local_u8ErrorStatus = NOK;
	}
	return Local_u8ErrorStatus;
}

/*******************************************************************************
 * @fn GPIO_u8ReadPinValue
 * @brief the function reads/gets the GPIO pin value
 * @param[in] Port: specify the Port Number
 * @param[in] PinNum: specify the pin Number
 * @param[out] PinVal: loaded with the pin value
 * @retval ErrorStatus
 *
 */
uint8_t GPIO_u8ReadPinValue(Port_t Port, Pin_t PinNum, PinVal_t *PinVal)
{
	uint8_t Local_u8ErrorStatus = OK;
	if( (Port  <=  PORTH ) && (PinNum <= PIN15) )
	{
		*PinVal = (((GPIO_PORT[Port] -> IDR) >> PinNum )& 1);
	}
	else
	{
		Local_u8ErrorStatus = NOK;
	}
	return Local_u8ErrorStatus;
}

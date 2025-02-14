
#include <stdint.h>
#include "../../../Library/Stm32F446xx.h"
#include "../Inc/GPIO_private.h"
#include "../Inc/GPIO_interface.h"




uint8_t GPIO_u8PinInit(const PinConfig_t *PinConfig)
{

    PinConfig->
}

uint8_t GPIO_u8SetPinValue(Port_t Port, Pin_t PinNum, PinVal_t PinVal)
{
    uint8_t LocalErrorStatus = OK;

    return LocalErrorStatus;
}

uint8_t GPIO_u8TogglePinValue(Port_t Port, Pin_t PinNum, PinVal_t PinVal)
{

}

uint8_t GPIO_u8ReadPinValue(Port_t Port, Pin_t PinNum, PinVal_t *PinVal)
{

}

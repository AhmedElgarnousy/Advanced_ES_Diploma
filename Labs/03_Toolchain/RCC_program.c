#include "stdint.h"
#include "Stm32F446xx.h"

#include "RCC_private.h"
#include "RCC_interface.h"

/************
 * @fn  RCC_voidAHB1EnablePeripheralClock
 * @brief
 * @param[in] Peripheral: Peripheral Number
 * 
*/
void RCC_voidAHB1EnablePeripheralClock(uint8_t Peripheral)
{
    RCC->AHB1ENR |= (1 << Peripheral);
}


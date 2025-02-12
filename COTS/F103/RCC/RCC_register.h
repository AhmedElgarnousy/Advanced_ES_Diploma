#ifndef RCC_REGISTER_H_
#define RCC_REGISTER_H_

typedef struct
{
    uint32_t CR;                /*   Clock Control Register                 */
    uint32_t CFGR;              /*   Clock Configuration                    */
    uint32_t CIR;               /*   Clock Iterrupt Register                */
    uint32_t APB2RSTR;          /*   APB2 peripheral reset Register         */
    uint32_t APB1RSTR;          /*   APB1 peripheral reset register         */
    uint32_t AHBENR;            /*   AHB  peripheral clock enable register  */
    uint32_t APB2ENR;           /*   APB2 peripheral clock enable register  */
    uint32_t APB1ENR;           /*   APB1 peripheral clock enable register  */
    uint32_t BDCR;              /*   Backup domain control register         */
    uint32_t CSR;               /*   Control/status register                */
} RCC_register_t;

RCC_register_t * RCC = (RCC_register_t*) RCC_BASE_ADDRESS;


// RCC RC Register Pins
enum
{
	HSI_ON ,
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
enum {
	PLLSRC = 16,
	PLLXTPRE,
};


#endif /* RCC_REGISTER_H_ */

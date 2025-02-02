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


#endif /* RCC_REGISTER_H_ */

#ifndef GPIO_INTERFACE_H_
#define GPIO_INTERFACE_H_
typedef enum {
    PIN_LOW = 0,
    PIN_HIGH,
} PinVal_t;

typedef enum {
    PORTA = 0,
    PORTB,
    PORTC,
    PORTD,
    PORTE,
    PORTF,
    PORTG,
    PORTH,
} Port_t;

// CONST better to be CAPITAL Letters
typedef enum {
    PIN0 = 0,
    PIN1,
    PIN2,
    PIN3,
    PIN4,
    PIN5,
    PIN6,
    PIN7,
    PIN8,
    PIN9,
    PIN10,
    PIN11,
    PIN12,
    PIN13,
    PIN14,
    PIN15,
} Pin_t;

typedef enum
{
    OUTPUT = 0,
    ALTERNATE_FUNCTION,
    INPUT,
} CNF_Mode_t;
typedef enum
{
    MAX_10MH = 1,
    MAX_2MH,
    MAX_50MH,
} SpeedMode_t;
typedef enum
{
    ANALOG = 0,
    FLOATING,
    PUSH_PULL,
} InputType_t;
typedef enum
{
    PUSH_PULL = 0,
    OPEN_DRAIN,
    AF_PUSH_PULL,
    AF_OPEN_DRAIN,
} OutputType_t;
typedef struct {
    Port_t Port;
    Pin_t PinNum;
    CNF_Mode_t ConfigMode;
    SpeedMode_t SpeedMode;
    OutputType_t OutputType;
    InputType_t InputType;
    // PullUpDown_t PullType;
    // AltFunc_t AltFunc;
} GPIO_PinConfig_t;

uint8_t GPIO_u8PinInit(const GPIO_PinConfig_t *PinConfig);

uint8_t GPIO_u8SetPinValue(Port_t Port, Pin_t PinNum, PinVal_t PinVal);

uint8_t GPIO_u8TogglePinValue(Port_t Port, Pin_t PinNum, PinVal_t PinVal);

uint8_t GPIO_u8ReadPinValue(Port_t Port, Pin_t PinNum, PinVal_t *PinVal);

#endif /*GPIO_INTERFACE_H_*/

### Systick

#### Revision On Timer

<p align="center">
    <img width="80%" height="50%" src="../imgs/systick.JPG">
  </p>

> note: accessing systick register register, zeros it

### Assignments

- systick simple driver (Polling)
  same for f103, f446
  - assume fixed clock AHB values in RCC
  - another to be generic values
    - make a global variable in RCC contains final AHB clock value
    - and extern this variable in SYSTICK to use it in your calculations

```c
systick_delay_ms(time_ms);
systick_delay_us(time_us);
```

- app1:
  - while switch pressed on f103 LED turned on for userled on nucleo-f446
  - without any communication protocols
- app2:
  - 3 switches on f103 LED turned on for 3leds on nucleo-f446
  - without any communication protocols, only one wire
- app3:
  - developed panda driver modules:LCD,SSD,Buzzer,Keypad
  - Do it with prebuild configs, config.h

### Bootloader2 , Custom Bootloader

custom Bootloader 1st step

#### Where to place our bootloader & code in the memory

<p align="center">
  <img width="50%" height="50%" src="../imgs/boot40.JPG">
</p>

we know that we have ROM of 30KB, where ST'S Bootloader is stored
we hoped to use it but we can't remove that because it READ only and not access from vendor.

instead of consume our flash, and it will erase after using debugger

so we use the flash memory itself to store our bootloader, sector 0, sector 1

which is 1st 32 KB of the flash memory, then sector2 > sector 7 for the application code

###### Flash Memory Organization

<p align="center">
  <img width="50%" height="50%" src="../imgs/boot39.JPG">
</p>

<p align="center">
  <img width="50%" height="50%" src="../imgs/boot41.JPG">
</p>

Note: We can also use external flash to store our Custom Bootloader, as we have Flexible memory controller (FMC) Peripheral In Nucleo64 board to map its addresses to internal processor accessable addresses
which is parallel communication for high speed

but we limited to FMC Block Memory Region

---

#### Host-Bootloader Communication

Host may be machine, or another Microcontroller

<p align="center">
  <img width="50%" height="50%" src="../imgs/boot42.JPG">
</p>

##### Our Communication Architecture

`1)` When your reset your MC, it will make some initialisations, like clock, communicatio9n, then it'll wait for data from host on communication bus

`2)` when host sends command packet , the bootloader will receive it, decode it, checks for data validation(CRC) of the recieved packet

`3)` If data is good, it will send ACK, if it fails it will send NACK

`4)` I f ACK is sent, it will be followed by length to follow
This is total 2B: 1B for ACK, 1B for length
The length is #of bytes the bootloader will send next as reply

`5)` The bootloader sends reply actually

#### Ex1

`1)` Host sends GET_CID Command, get Chip Id is represent a number not string
`2)` CRC is verified, if good, BL sends ACK, 2(as length)
`3)` Then BL executes function that reads Chip Id of the MC
`4)` Then BL sends reply of 2B, and the host knows that is 2B

Let's create 2 projects for BL ,user App using ST generated Code

```c
\r --> Carriage Return
```

##### 1st task: Bootloader jumping to User App for f446

our custom bootloader will be stored in sector 0, 1 in the flash, we want this bootloader to check for a user button, if pressed it will call function Bootloader-UARTReadData, if not, it will jump to user app

<p align="center">
  <img width="50%" height="50%" src="../imgs/boot43.JPG">
</p>

User App is switch as EXTI source and toggle LED in it's handler ISR

<p align="center">
  <img width="50%" height="50%" src="../imgs/boot44.JPG">
</p>

in Nucleo-F446

Processor has feature to tell him about new location for vectortable of user application

you have to think in the reset sequence done by processor to implement it by software in jumping to user app function

When dubugger uploads code erases flash memory starts from origin address in linker script

so we should upload bootloader first then user app

<p align="center">
  <img width="50%" height="50%" src="../imgs/boot45.JPG">
</p>

### What is the Bootloader

small piece of code, stored in the MCU flash or ROM, to act as an application loader as well as a mechanism to update the applications whereevr required.

###### Bootloader Examples:

`1)` 'Arduino UNO Board': (based ATmega328p)
Programmed by UART Bootloader ? and that's why RX,TX Pins blink during code uploading

upon reset, arduino bootloader runs first to download arduino sketch to the board

<p align="center">
  <img width="90%" height="50%" src="../imgs/boot23.JPG">
</p>

After Bootloader code executes and receive complete valid new app, MC resets and bootloader decide to run new app that received.

[''Bootloader src code''](https://docs.arduino.cc/retired/hacking/software/Bootloader/), [''Arduino as ISP''](https://docs.arduino.cc/built-in-examples/arduino-isp/ArduinoISP/#the-bootloader)

**Note:** ==if we used to ISP programmer to upload code on MC contains Boatloader code will be erased.
because programmer erase flash before uploading code==.

ATmega32 Programming Port is SPI, JTAG
so you can use USAasp(SPI) to upload bootloader code

`2)` ST MCUs, Nucleo-F4446RE Board

1. comes with on chip bootloader, all ST Microcontrollers also
2. It doesn't run by default when MC resets, you have to activate it by changing state of boot pins
3. used to upload binaries(.hex)
4. The Board is by default programmed by In-Circuit debugger/programmer, this circuit is absent in arduino board (ICP, ISP, OCP)
5. and that's why on chip boatloader does't erased when board programmed by ISP programmer.

- `STM32 Programming protocols are SWD, JTAG.`

`3)` TM4C123G Launchpad (TI)
like Nucleo, it has TivaWare bootloader

---

##### STM32F446XX Memory Organization

1. Internal flash memory also called Embedded flash of 512 KB or On-chip flash
2. SRAM1 -> 112 KB, SRAM2 -> 16 KB
3. System Memory (ROM) of 30 KB, used by ST to store ST Native Bootloader
4. OTP(One time Programmable), of 528 bytes, used mainly to store the product number, serial number of the MCU
5. Option Bytes of 16 B, mainly contain flags used to access flash memory
6. Backup SRAM of 4KB (used with Battery) Implement NVRAM

#### 1- Embedded Flash

1. size is 512 KB
2. starts at address `0x08000000 -> 0x0807ffff(0x08000000 + 0x(512 * 1024) - 1)`
3. used to store application code , and storing non-volatile data(.rodata) through flash driver peripheral during runtime, not direct through address pointer, also data by page
4. Non Volatile

#### 2- System Memory

1. size is 30KB
2. starts at `0x1fff0000 -> 0x1fff77ff`
3. All ST MCUs store Bootloader in this memory
4. Read only
5. By default MCU will not execute any code from this memory, but you can configure MCU to boot or execute bootloader from this memory
6. After Reset the MC reads status of some pins, then it decides whether to execute from this memory or another

from stm32f446_reference_manual -> 3.3
Embedded Flash memory

<p align="center">
  <img width="90%" height="50%" src="../imgs/boot25.JPG">
</p>

---

#### Reset Sequence & Memory Aliasing

- Recall Cortex-m reset sequence:
- Address 0x0 is the 1st address the processor goes to,but in stm32 MC, the user flash actually starts at 0x08000000 this is by the ST vendor, this changes by the vendors,
  This means code, vector table , etc starts at 0x0800-0000?????

##### Mistry

- All cortex based MCUs right after reset

  - 1- Load value at memory address 0x00000000 into MSP
  - 2- Load value at memory address 0x00000004 into PC(address of reset handler)

- in STM32 MCs
  - 1- MSP value stored at 0x08000000
  - 2- Address of reset handler is at 0x08000004
- so we must in some how link the address 0x000000000 to the address 0x080000000
  - done by Memory Aliasing(It's a HW technique to link memory addresses and it depends on MCU)

<p align="center">
  <img width="90%" height="50%" src="../imgs/boot26.JPG">
</p>
<p align="left">
  <img width="50%" height="50%" src="../imgs/boot27.JPG">
  <img width="50%" height="50%" src="../imgs/boot28.JPG">
</p>

- why and how this technique? this is a ST vendor memory specific design.

#### Boot Configuration of STM32

ST says there are 2 pins on your MC called BOOT1, BOOT0

from stm32f446_reference_manual -> 2.3

<p align="left">
  <img width="50%" height="50%" src="../imgs/boot29.JPG">
  <img width="50%" height="50%" src="../imgs/boot30.JPG">
</p>

TivaWare in TM4C123 TI vendor

#### ST Bootloader Demo

is closed source code

Activatation

- [How to Upload STM32F103C8T6 USB Bootloader? Program STM32 Blue Pill via USB](https://www.electronicshub.org/how-to-upload-stm32f103c8t6-usb-bootloader/)

##### AN2606 Application note STM32 microcontroller system memory boot mode

<p align="left">
  <img width="50%" height="50%" src="../imgs/boot31.JPG">
  <img width="50%" height="50%" src="../imgs/boot32.JPG">
</p>

Download stm32 flash loader demonstrator [click here](https://www.st.com/en/development-tools/flasher-stm32.html)
only for windows

To open **Flash Loader Demonstrator** Tool: C:\Program Files (x86)\STMicroelectronics\Software\Flash Loader Demo\STMFlashLoader Demo.exe

<p align="left">
  <img width="50%" height="50%" src="../imgs/boot33.JPG">
  <img width="50%" height="50%" src="../imgs/boot37.JPG">
</p>

**WARNNING**: My BlueBill Has a NOT WORKING GND PIN

- coonect Boot0 -> High, to boot from system memory
- reset, because the previous uploaded application is running at this time so it should communicate with bootloader code itself that waits to UART connection
- Dis/Connect TTL

- also should TTL Driver installed ex: PL2303 Driver for Blue TTL device.

<p align="left">
  <img width="50%" height="50%" src="../imgs/boot34.JPG">
</p>

<p align="left">
  <img width="50%" height="50%" src="../imgs/boot38.JPG">
  <img width="50%" height="50%" src="../imgs/boot35.JPG">
  <img width="50%" height="50%" src="../imgs/boot36.JPG">
</p>

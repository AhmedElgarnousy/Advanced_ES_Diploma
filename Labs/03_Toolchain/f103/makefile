CC = arm-none-eabi-gcc

CFLAGS = -c -mcpu=$(MARH) -std=gnu11 -mthumb -Wall

MARH = cortex-m4

LDFLAGS = -T STM32F103_LinkerScript.ld -nostdlib -Wl,-Map=final.map

main.o:  main.c
	$(CC) $(CFLAGS) $^ -o $@

RCC_program.o: RCC_program.c
	$(CC) $(CFLAGS) $^ -o $@

GPIO_program.o: GPIO_program.c
	$(CC) $(CFLAGS) $^ -o $@

STM32F103_startup.o: STM32F103_startup.c
	$(CC) $(CFLAGS) $^ -o $@

final.elf: main.o GPIO_program.o RCC_program.o STM32F103_startup.o 
	$(CC) $^ $(LDFLAGS) -o $@ 

all: main.o GPIO_program.o RCC_program.o STM32F103_startup.o final.elf	

clean:
	rm -f *.o *.elf *.bin *.hex

load:
	openocd -f stm32f103c8_blue_pill.cfg -c "tcl port 6668"
# 	openocd -f stm32f103c8_blue_pill.cfg -c "transport select swd" 

# for stlink
update:
	openocd -f stlink.cfg -c "transport select hla_swd" 

lol:
	openocd 
	openocd -f stlink.cfg -f stm32f103c8_blue_pill.cfg -c "transport select hla_swd" 

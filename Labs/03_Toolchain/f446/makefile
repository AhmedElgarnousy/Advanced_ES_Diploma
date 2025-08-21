CC = arm-none-eabi-gcc

CFLAGS = -c -mcpu=$(MARH) -std=gnu11 -mthumb -Wall

MARH = cortex-m4

main.o:  main.c
	$(CC) $(CFLAGS) $^ -o $@

GPIO_program.o: GPIO_program.c
	$(CC) $(CFLAGS) $^ -o $@

STM32F466re_startup.o: STM32F466re_startup.c
	$(CC) $(CFLAGS) $^ -o $@

clean:
	rm -f *.o *.elf *.bin *.hex

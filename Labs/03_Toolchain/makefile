CC = arm-none-eabi-gcc

CFLAGS = -c -mcpu=$(MARH) -std=gnu11 -mthumb

MARH = cortex-m4

main.o:  main.c
	$(CC) $(CFLAGS) $^ -o $@

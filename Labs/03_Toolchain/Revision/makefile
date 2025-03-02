# Build: file.c
# 	gcc -E file.c -o out.i
# 	gcc -S file.c -o out.asm
# 	gcc -c file.c -o out.obj
# 	gcc file.c -o out.exe


main.o: main.c
	gcc -c main.c -o main.o

math.o: math.c math.h
	gcc -c math.c -o math.o

all: main.o math.o
	gcc main.o math.o -o out.exe



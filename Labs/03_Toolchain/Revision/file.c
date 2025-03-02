#include <stdio.h>


int main()
{
    int x = 0x11223344;
    char *ptr = (char*)&x;

    if(*ptr == (char)x)
    {
        printf("Little endian");
    }
    else
    {
        printf("Big endian");
    }
}
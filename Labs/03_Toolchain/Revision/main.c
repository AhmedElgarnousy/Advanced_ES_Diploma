#include <stdio.h>

#include "math.h"

int main()
{
    int num1, num2, res;
    char operator;
    printf("Please enter number 1: ");
    scanf("%d",&num1);
    printf("Please enter number 2: ");
    scanf("%d",&num2);
    printf("Please enter operator: ");
    scanf("%c\n",&operator);
    
    
    switch (operator)
    {
        case '+':
        res = num1 + num2;
        break;
        case '-':
        res = num1 - num2;
        break;
    }
    
    printf("Res = %d\n", res);

}
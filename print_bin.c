#include "main.h"

/**
 * print_binary - Converts unsigned int to binary
 * @n: Unsigned int
 *
 * Return: binaryy
 */

int print_binary(unsigned int n)
{
    if (n == 0)
    {
        printf("0");
        return;
    }

    int binary[32];  
    int index = 0;

    while (n > 0) {
        binary[index++] = n % 2;
        n /= 2;
    }

    for (int i = index - 1; i >= 0; i--) {
        printf("%d", binary[i]);
    }
}

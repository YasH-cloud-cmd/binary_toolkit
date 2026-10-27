#include <limits.h>
#include <stdio.h>

#include "../include/binary_rep.h"
#include "../include/toolkit_input.h"

void binary_rep(void) {
    long long input;
    int number;
    int width = (int)(sizeof(unsigned int) * CHAR_BIT);
    unsigned int value;

    if (read_number("enter the number : ", &input) != 1) {
        return;
    }
    if (input < INT_MIN || input > INT_MAX) {
        printf("number is outside the range of int\n");
        return;
    }

    number = (int)input;
    value = (unsigned int)number;
    printf("binary representation of %d :\n", number);

    for (int i = width - 1; i >= 0; i--) {
        printf("%u", (value >> i) & 1u);
        if (i > 0 && i % CHAR_BIT == 0) {
            printf("   ");
        }
    }
    printf("\n");
}
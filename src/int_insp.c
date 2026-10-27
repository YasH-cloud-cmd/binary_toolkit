#include <limits.h>
#include <stdio.h>

#include "../include/int_insp.h"
#include "../include/toolkit_input.h"

void int_insp(void) {
    long long input;
    int number;
    int width = (int)(sizeof(unsigned int) * CHAR_BIT);
    unsigned int value;
    int setbits = 0;

    if (read_number("enter a number : ", &input) != 1) {
        return;
    }
    if (input < INT_MIN || input > INT_MAX) {
        printf("number is outside the range of int\n");
        return;
    }

    number = (int)input;
    value = (unsigned int)number;

    printf("======== INTEGER INSPECTOR ========\n");
    printf("Decimal\t\t: %d\n", number);
    printf("Hexadecimal\t: %#X\n", value);
    printf("Octal\t\t: %#o\n", value);
    printf("Binary\t\t: ");
    for (int i = width - 1; i >= 0; i--) {
        unsigned int bit = (value >> i) & 1u;
        printf("%u", bit);
        setbits += (int)bit;
        if (i > 0 && i % CHAR_BIT == 0) {
            printf(" ");
        }
    }
    printf("\n");

    if (number > 0) {
        printf("Number\t\t: positive\n");
    } else if (number < 0) {
        printf("Number\t\t: negative\n");
    } else {
        printf("Number\t\t: zero\n");
    }

    printf("Parity\t\t: %s\n", number % 2 == 0 ? "even" : "odd");
    printf("Set bits\t: %d\n", setbits);
    printf("Clear bits\t: %d\n", width - setbits);
}

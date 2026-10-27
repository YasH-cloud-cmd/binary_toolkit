#include <limits.h>
#include <stdio.h>

#include "../include/bitwise_ops.h"
#include "../include/toolkit_input.h"

static void print_binary(unsigned int value) {
    int width = (int)(sizeof(unsigned int) * CHAR_BIT);

    for (int i = width - 1; i >= 0; i--) {
        printf("%u", (value >> i) & 1u);
        if (i > 0 && i % CHAR_BIT == 0) {
            printf(" ");
        }
    }
    printf("\n");
}

void bitwise_ops(void) {
    long long first_input;
    long long second_input;
    int first;
    int second;
    int width = (int)(sizeof(unsigned int) * CHAR_BIT);
    unsigned int a;
    unsigned int b;

    if (read_number("enter the first integer : ", &first_input) != 1 ||
        read_number("enter the second integer : ", &second_input) != 1) {
        return;
    }
    if (first_input < INT_MIN || first_input > INT_MAX ||
        second_input < INT_MIN || second_input > INT_MAX) {
        printf("both numbers must be in the range of int\n");
        return;
    }

    first = (int)first_input;
    second = (int)second_input;
    a = (unsigned int)first;
    b = (unsigned int)second;

    printf("A in binary\t: ");
    print_binary(a);
    printf("B in binary\t: ");
    print_binary(b);
    printf("A AND B\t\t: %#x\n", a & b);
    printf("A OR B\t\t: %#x\n", a | b);
    printf("A XOR B\t\t: %#x\n", a ^ b);
    printf("NOT A\t\t: %#x\n", ~a);

    if (second >= 0 && second < width) {
        printf("A left shift %d\t: %#x\n", second, a << second);
        printf("A right shift %d\t: %#x\n", second, a >> second);
    } else {
        printf("shift count must be between 0 and %d\n", width - 1);
    }
}

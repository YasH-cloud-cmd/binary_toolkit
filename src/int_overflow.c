#include <limits.h>
#include <stdio.h>

#include "../include/int_overflow.h"
#include "../include/toolkit_input.h"

void int_overflow(void) {
    long long first_input;
    long long second_input;
    int first;
    int second;
    long long result;

    printf("======== INTEGER OVERFLOW EXPLORER ========\n");
    printf("int range: %d to %d\n", INT_MIN, INT_MAX);
    if (read_number("enter the first int : ", &first_input) != 1 ||
        read_number("enter the second int : ", &second_input) != 1) {
        return;
    }
    if (first_input < INT_MIN || first_input > INT_MAX ||
        second_input < INT_MIN || second_input > INT_MAX) {
        printf("both numbers must be in the range of int\n");
        return;
    }

    first = (int)first_input;
    second = (int)second_input;
    result = (long long)first + second;

    if ((second > 0 && first > INT_MAX - second) ||
        (second < 0 && first < INT_MIN - second)) {
        printf("%d + %d would overflow a signed int\n", first, second);
        printf("signed integer overflow is undefined behavior in C\n");
    } else {
        result = (long long)first + second;
        printf("%d + %d = %lld, which fits in an int\n",
               first, second, result);
    }
    printf("unsigned int range: 0 to %u; unsigned arithmetic wraps modulo %u + 1\n",
           UINT_MAX, UINT_MAX);
}

#include <limits.h>
#include <stdio.h>

#include "../include/memory_insp.h"
#include "../include/toolkit_input.h"

void memory_insp(void) {
    long long input;
    int value;
    unsigned char *bytes;

    if (read_number("enter an integer : ", &input) != 1) {
        return;
    }
    if (input < INT_MIN || input > INT_MAX) {
        printf("number is outside the range of int\n");
        return;
    }

    value = (int)input;
    bytes = (unsigned char *)&value;

    printf("======== MEMORY INSPECTOR ========\n");
    printf("Value\t\t: %d\n", value);
    printf("Address\t\t: %p\n", (void *)&value);
    printf("Size\t\t: %zu bytes\n", sizeof(value));
    printf("Bytes in memory\t: ");
    for (size_t i = 0; i < sizeof(value); i++) {
        printf("%02X ", bytes[i]);
    }
    printf("\n");
    printf("Byte order shown is the order used by this computer.\n");
}

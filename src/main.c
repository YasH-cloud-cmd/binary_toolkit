#include <stdio.h>

#include "../include/binary_rep.h"
#include "../include/data_type.h"
#include "../include/int_insp.h"
#include "../include/int_overflow.h"
#include "../include/memory_insp.h"
#include "../include/number_convert.h"
#include "../include/bitwise_ops.h"
#include "../include/toolkit_input.h"

int main(void) {
    long long choice = 0;
    int result;

    do {
        printf("=======================================\n");
        printf("       BINARY INSPECTION TOOLKIT       \n");
        printf("=======================================\n");
        printf("1. Integer Inspector\n");
        printf("2. Binary Representation\n");
        printf("3. Bitwise Operations\n");
        printf("4. Number System Converter\n");
        printf("5. Data Type Explorer\n");
        printf("6. Memory Inspector\n");
        printf("7. Integer Overflow Explorer\n");
        printf("8. Exit\n");

        result = read_number("Select an option: ", &choice);
        if (result == 0) {
            break;
        }
        if (result == -1) {
            continue;
        }

        switch (choice) {
            case 1:
                int_insp();
                break;
            case 2:
                binary_rep();
                break;
            case 3:
                bitwise_ops();
                break;
            case 4:
                number_convert();
                break;
            case 5:
                data_type();
                break;
            case 6:
                memory_insp();
                break;
            case 7:
                int_overflow();
                break;
            case 8:
                printf("goodbye\n");
                break;
            default:
                printf("please select a number from 1 to 8\n");
        }
        printf("\n");
    } while (choice != 8);

    return 0;
}
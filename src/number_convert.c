#include <ctype.h>
#include <errno.h>
#include <limits.h>
#include <stdio.h>
#include <stdlib.h>

#include "../include/number_convert.h"
#include "../include/toolkit_input.h"

static void print_in_base(long long value, int base) {
    const char digits[] = "0123456789ABCDEFGHIJKLMNOPQRSTUVWXYZ";
    char output[sizeof(unsigned long long) * CHAR_BIT + 1];
    unsigned long long magnitude;
    int index = 0;

    if (value < 0) {
        magnitude = 0ULL - (unsigned long long)value;
    } else {
        magnitude = (unsigned long long)value;
    }

    do {
        output[index++] = digits[magnitude % (unsigned int)base];
        magnitude /= (unsigned int)base;
    } while (magnitude > 0);

    if (value < 0) {
        printf("-");
    }
    while (index > 0) {
        printf("%c", output[--index]);
    }
}

void number_convert(void) {
    char text[128];
    char *end;
    long long value;
    long long from_input;
    long long to_input;
    int from_base;
    int to_base;

    if (read_text("enter the number to convert : ", text, sizeof(text)) != 1 ||
        read_number("enter its base (2-36) : ", &from_input) != 1 ||
        read_number("enter the base to convert to (2-36) : ", &to_input) != 1) {
        return;
    }
    if (from_input < 2 || from_input > 36 ||
        to_input < 2 || to_input > 36) {
        printf("base must be between 2 and 36\n");
        return;
    }

    from_base = (int)from_input;
    to_base = (int)to_input;
    errno = 0;
    value = strtoll(text, &end, from_base);
    while (isspace((unsigned char)*end)) {
        end++;
    }
    if (end == text || *end != '\0' || errno == ERANGE) {
        printf("number is not valid for base %d or is outside the supported range\n",
               from_base);
        return;
    }

    printf("%s (base %d) = ", text, from_base);
    print_in_base(value, to_base);
    printf(" (base %d)\n", to_base);
}

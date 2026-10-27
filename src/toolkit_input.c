#include <ctype.h>
#include <errno.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include "../include/toolkit_input.h"

int read_number(const char *prompt, long long *number) {
    char line[128];
    char *end;
    long long value;

    printf("%s", prompt);
    if (fgets(line, sizeof(line), stdin) == NULL) {
        return 0;
    }

    if (strchr(line, '\n') == NULL && !feof(stdin)) {
        int ch;
        while ((ch = getchar()) != '\n' && ch != EOF) {
        }
        printf("input is too long\n");
        return -1;
    }

    errno = 0;
    value = strtoll(line, &end, 10);
    while (isspace((unsigned char)*end)) {
        end++;
    }

    if (end == line || *end != '\0' || errno == ERANGE) {
        printf("invalid number\n");
        return -1;
    }

    *number = value;
    return 1;
}

int read_text(const char *prompt, char *text, size_t size) {
    size_t length;

    printf("%s", prompt);
    if (fgets(text, size, stdin) == NULL) {
        return 0;
    }

    length = strlen(text);
    if (length > 0 && text[length - 1] == '\n') {
        text[length - 1] = '\0';
    } else if (!feof(stdin)) {
        int ch;
        while ((ch = getchar()) != '\n' && ch != EOF) {
        }
        printf("input is too long\n");
        return -1;
    }

    if (text[0] == '\0') {
        printf("input cannot be empty\n");
        return -1;
    }

    return 1;
}

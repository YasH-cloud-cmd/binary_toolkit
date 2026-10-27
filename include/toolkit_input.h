#ifndef toolkit_input_h
#define toolkit_input_h

#include <stddef.h>

int read_number(const char *prompt, long long *number);
int read_text(const char *prompt, char *text, size_t size);

#endif

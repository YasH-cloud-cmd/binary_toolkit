#include <float.h>
#include <limits.h>
#include <stdio.h>

#include "../include/data_type.h"

void data_type(void) {
    printf("======== DATA TYPE EXPLORER ========\n");
    printf("Type\t\t\tSize\tRange\n");
    printf("char\t\t\t%zu\t%d to %d\n",
           sizeof(char), CHAR_MIN, CHAR_MAX);
    printf("signed char\t\t%zu\t%d to %d\n",
           sizeof(signed char), SCHAR_MIN, SCHAR_MAX);
    printf("unsigned char\t\t%zu\t0 to %u\n",
           sizeof(unsigned char), (unsigned int)UCHAR_MAX);
    printf("short\t\t\t%zu\t%d to %d\n",
           sizeof(short), SHRT_MIN, SHRT_MAX);
    printf("unsigned short\t\t%zu\t0 to %u\n",
           sizeof(unsigned short), (unsigned int)USHRT_MAX);
    printf("int\t\t\t%zu\t%d to %d\n",
           sizeof(int), INT_MIN, INT_MAX);
    printf("unsigned int\t\t%zu\t0 to %u\n",
           sizeof(unsigned int), UINT_MAX);
    printf("long\t\t\t%zu\t%ld to %ld\n",
           sizeof(long), LONG_MIN, LONG_MAX);
    printf("unsigned long\t\t%zu\t0 to %lu\n",
           sizeof(unsigned long), ULONG_MAX);
    printf("long long\t\t%zu\t%lld to %lld\n",
           sizeof(long long), LLONG_MIN, LLONG_MAX);
    printf("unsigned long long\t%zu\t0 to %llu\n",
           sizeof(unsigned long long), ULLONG_MAX);
    printf("float\t\t\t%zu\t-%g to %g\n",
           sizeof(float), FLT_MAX, FLT_MAX);
    printf("double\t\t\t%zu\t-%g to %g\n",
           sizeof(double), DBL_MAX, DBL_MAX);
    printf("Floating-point ranges show the finite limits.\n");
}

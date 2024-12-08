#include <stdio.h>
#include <stdint.h>
#include <setjmp.h>


#include "guess_number.h"

#if _WIN32
#  define C_RED(s)     s
#  define C_GREEN(s)   s
#else
#  define C_RED(s)     "\033[31;1m" s "\033[0m"
#  define C_GREEN(s)   "\033[32;1m" s "\033[0m"
#endif

#define TEST(s, x) \
    do { \
        if (x) { \
            printf(C_GREEN("PASS") " %s\n", s); \
            count_pass++; \
        } else { \
            printf(C_RED("FAIL") " %s\n", s); \
            count_fail++; \
        } \
    } while (0)


int main(int argc, char **argv) {
    volatile int count_pass = 0;
    volatile int count_fail = 0;

    TEST("Arabic 1 to roman I", !strcmp(arabic2roman(1), "I"));
    TEST("Arabic 99 to roman XCIX", !strcmp(arabic2roman(99), "XCIX"));
    TEST("Roman I to arabic 1", roman2arabic("I") == 1);
    TEST("Roman XCIX to arabic 99", roman2arabic("XCIX") == 99);
    TEST("Number 11 to string \"99\"", !strcmp(number2string(99), "99"));
    char* new_argv[2] = {"", "-h"};
    TEST("Guess number help", start_guessing(2, new_argv) == 0);

    printf("%d fail, %d pass\n", count_fail, count_pass);
    return count_fail != 0;
}

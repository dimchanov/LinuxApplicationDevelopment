#include <libintl.h>
#include <locale.h>
#include <stdio.h>
#include <string.h>

#include "guess_number.h"


char str_number[4] = {0};
char* roman_numbers[100] = {
    "I", "II", "III", "IV", "V", "VI", "VII", "VIII", "IX", "X",
    "XI", "XII", "XIII", "XIV", "XV", "XVI", "XVII", "XVIII", "XIX", "XX",
    "XXI", "XXII", "XXIII", "XXIV", "XXV", "XXVI", "XXVII", "XXVIII", "XXIX", "XXX",
    "XXXI", "XXXII", "XXXIII", "XXXIV", "XXXV", "XXXVI", "XXXVII", "XXXVIII", "XXXIX", "XL",
    "XLI", "XLII", "XLIII", "XLIV", "XLV", "XLVI", "XLVII", "XLVIII", "XLIX", "L",
    "LI", "LII", "LIII", "LIV", "LV", "LVI", "LVII", "LVIII", "LIX", "LX",
    "LXI", "LXII", "LXIII", "LXIV", "LXV", "LXVI", "LXVII", "LXVIII", "LXIX", "LXX",
    "LXXI", "LXXII", "LXXIII", "LXXIV", "LXXV", "LXXVI", "LXXVII", "LXXVIII", "LXXIX", "LXXX",
    "LXXXI", "LXXXII", "LXXXIII", "LXXXIV", "LXXXV", "LXXXVI", "LXXXVII", "LXXXVIII", "LXXXIX", "XC",
    "XCI", "XCII", "XCIII", "XCIV", "XCV", "XCVI", "XCVII", "XCVIII", "XCIX", "C"
};


char* arabic2roman(int number) {
    return roman_numbers[number-1];
}


int roman2arabic(char *roman) {
    for (int arabic = 0; arabic < 100; ++arabic) {
        if (!strcmp(roman, roman_numbers[arabic])) {
            return arabic + 1;
        }
    }
    return -1;
}


char* number2string(int number) {
    sprintf(str_number, "%d", number);
    return str_number;
}


int start_guessing(int argc, char **argv) {
    setlocale(LC_ALL, "");
    bindtextdomain("guess_number", ".");
    textdomain("guess_number");

    char*(*post_handler)(int) = &number2string;

    if (argc > 1) {
        if (!strcmp(argv[1], gettext("-h")) || !strcmp(argv[1], gettext("--help"))) {
            printf(gettext("A rather stupid C program that guesses the number\n"));
            printf(gettext("Args usage:\n"));
            printf(gettext("-h, --help\n\tPrints the usage for the executable and exits.\n"));
            printf(gettext("-r\n\tEnables roman numbers.\n"));
            return 0;
        } else if (!strcmp(argv[1], gettext("-r"))) {
            printf(gettext("Roman numerals are used\n"));
            post_handler = &arabic2roman;
        } else {
            printf(gettext("Unknown command line argument\n"));
        }
    }

    int left = 1, right = 100;
    int middle;

    printf(gettext("Please guess the number from %s "), post_handler(1));
    printf(gettext("to %s\n"), post_handler(100));

    while (left != right) {
        middle = (left + right) / 2;
        
        printf(gettext("Is your number greater than %s?\n"), post_handler(middle));

        char answer[10];
        char is_correct_answer = 0;
        while (!is_correct_answer) {
            is_correct_answer = scanf("%s", answer);
            
            if (!strcasecmp(answer, gettext("yes")) || !strcasecmp(answer, gettext("y"))) {
                left = middle + 1;
            } else if (!strcasecmp(answer, gettext("no")) || !strcasecmp(answer, gettext("n"))) {
                right = middle;
            } else {
                printf(gettext("Just answer the question yes or no, please\n"));
                is_correct_answer = 0;
            }
        }
    }

    printf(gettext("Your number is %s\n"), post_handler(left));

    return 0;
}

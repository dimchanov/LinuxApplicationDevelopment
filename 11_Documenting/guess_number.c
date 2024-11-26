#include <libintl.h>
#include <locale.h>
#include <stdio.h>
#include <string.h>


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
}


char* arabic2roman(int number) {
    return roman_numbers[number-1];
}


int main(int argc, char **argv) {
    setlocale(LC_ALL, "");
    bindtextdomain("guess_number", ".");
    textdomain("guess_number");

    int left = 1, right = 100;
    int middle;

    printf(gettext("Please guess the number from 1 to 100\n"));

    while (left != right) {
        middle = (left + right) / 2;
        
        printf(gettext("Is your number greater than %d?\n"), middle);

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

    printf(gettext("Your number is %d\n"), left);

    return 0;
}
#include <libintl.h>
#include <locale.h>
#include <stdio.h>
#include <string.h>

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
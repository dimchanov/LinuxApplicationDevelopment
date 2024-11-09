#include <stdio.h>
#include <string.h>

int main(int argc, char **argv) {
    int left = 1, right = 100;
    int middle;

    printf("Please guess the number from 1 to 100\n");

    while (left != right) {
        middle = (left + right) / 2;
        
        printf("Is your number greater than %d?\n", middle);

        char answer[10];
        char is_correct_answer = 0;
        while (!is_correct_answer) {
            is_correct_answer = 1;
            scanf("%s", answer);
            
            if (!strcasecmp(answer, "yes")) {
                left = middle + 1;
            } else if (!strcasecmp(answer, "no")) {
                right = middle;
            } else {
                printf("Just answer the question yes or no, please\n");
                is_correct_answer = 0;
            }
        }
    }

    printf("Your number is %d!\n", left);

    return 0;
}
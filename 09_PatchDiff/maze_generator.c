#include <stdio.h>
#include <stdlib.h>


int main(int argc, char **argv) {
    int size = 6;
    char wall = '#';
    char passage = '.';

    int offset = size * 2 + 1;
    char *maze = (char *)calloc(offset * offset, sizeof(char));

    for (int i = 1; i < offset; i += 2) {
        for (int j = 1; j < offset; j += 2) {
            maze[i * offset + j] = 1;
        }
    }    

    for (int i = 0; i < offset; ++i) {
        for (int j = 0; j < offset; ++j) {
            printf("%c", maze[i * offset + j] ? passage : wall);
        }
        printf("\n");
    }

    return 0;
}
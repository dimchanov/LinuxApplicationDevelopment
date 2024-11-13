#include <stdio.h>
#include <stdlib.h>


double p() {
    return (double)rand() / RAND_MAX;
}


void get_open_maze(char *maze, int size) {
    int offset = size * 2 + 1;
    for (int i = 1; i < offset; i += 2) {
        for (int j = 1; j < offset; j += 2) {
            // up
            if (i - 1 > 0) {
                maze[(i - 1) * offset + j] = 1;
                maze[i * offset + j] += 1;
            }
            // right
            if (j + 1 < offset - 1) {
                maze[i * offset + j + 1] = 1;
                maze[i * offset + j] += 1;
            }
            // down
            if (i + 1 < offset - 1) {
                maze[(i + 1) * offset + j] = 1;
                maze[i * offset + j] += 1;
            }
            // left
            if (j - 1 > 0) {
                maze[i * offset + j - 1] = 1;
                maze[i * offset + j] += 1;
            }
        }
    }
}


void set_passage(char *maze, int size) {
    int offset = size * 2 + 1;
    for (int i = 1; i < offset; i += 2) {
        for (int j = 1; j < offset; j += 2) {
            if (maze[i * offset + j] > 1) {
                continue;
            }
            // up
            if (p() > 0.75 && i - 2 > 0) {
                maze[(i - 1) * offset + j] = 1;
            }
            // right
            if (p() > 0.75 && j + 2 < offset) {
                maze[i * offset + j + 1] = 1;
            }
            // down
            if (p() > 0.75 && i + 2 < offset) {
                maze[(i + 1) * offset + j] = 1;
            }
            // left
            if (p() > 0.75 && j - 2 > 0) {
                maze[i * offset + j - 1] = 1;
            }
        }
    }
}


void show_maze(char *maze, int size, char wall, char passage) {
    int offset = size * 2 + 1;
    for (int i = 0; i < offset; ++i) {
        for (int j = 0; j < offset; ++j) {
            // printf("%d ", maze[i * offset + j]);
            printf("%c", maze[i * offset + j] ? passage : wall);
        }
        printf("\n");
    }
}


int main(int argc, char **argv) {
    int size = 6;
    char wall = '#';
    char passage = '.';

    int offset = size * 2 + 1;
    char *maze = (char *)calloc(offset * offset, sizeof(char));

    get_open_maze(maze, size);

    // set_passage(maze, size);

    show_maze(maze, size, wall, passage);
    
    return 0;
}
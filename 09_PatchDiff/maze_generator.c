#include <stdio.h>
#include <stdlib.h>


void show_maze(char *maze, int size, char wall, char passage) {
    int offset = size * 2 + 1;
    for (int i = 0; i < offset; ++i) {
        for (int j = 0; j < offset; ++j) {
            printf("%c", maze[i * offset + j] ? passage : wall);
        }
        printf("\n");
    }
}


void shuffle(char *arr, int size) {
    for (int i = 0; i < size; ++i) {
        int a = rand() % size;
        int b = rand() % size;
        char tmp = arr[a];
        arr[a] = arr[b];
        arr[b] = tmp;
    }
}


void set_passage(char *maze, int size, int i, int j) {
    char neighbors[4] = {0, 1, 2, 3};
    shuffle(neighbors, 4);

    int offset = size * 2 + 1;
    maze[i * offset + j] = 1;

    for (int ni = 0; ni < 4; ++ni) {
        // up
        if (neighbors[ni] == 0 && i - 2 > 0 && maze[(i - 2) * offset + j] == 0) {
            maze[(i - 1) * offset + j] = 1;
            set_passage(maze, size, i - 2, j);
        }
        // left
        else if (neighbors[ni] == 1 && j - 2 > 0 && maze[i * offset + j - 2] == 0) {
            maze[i * offset + j - 1] = 1;
            set_passage(maze, size, i, j - 2);
        }
        // down
        else if (neighbors[ni] == 2 && i + 2 < offset && maze[(i + 2) * offset + j] == 0) {
            maze[(i + 1) * offset + j] = 1;
            set_passage(maze, size, i + 2, j);
        }
        // right
        else if (neighbors[ni] == 3 && j + 2 < offset && maze[i * offset + j + 2] == 0) {
            maze[i * offset + j + 1] = 1;
            set_passage(maze, size, i, j + 2);
        }
    }
}


int main(int argc, char **argv) {
    int size = 6;
    char wall = '#';
    char passage = '.';

    int offset = size * 2 + 1;
    char *maze = (char *)calloc(offset * offset, sizeof(char));

    srand(42);
    set_passage(maze, size, 1, 1);

    show_maze(maze, size, wall, passage);
    
    free(maze);
    return 0;
}
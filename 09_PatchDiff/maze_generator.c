#include <stdio.h>
#include <stdlib.h>


double p() {
    return (double)rand() / RAND_MAX;
}

// void set_passage(char *maze, int size, int i, int j) {
//     int offset = size * 2 + 1;
//     maze[i * offset + j] = 1;
//     // up
//     if (p() > 0.5 && i - 2 > 0 && maze[(i - 2) * offset + j] != 1) {
//         maze[(i - 1) * offset + j] = 1;
//         set_passage(maze, size, i - 2, j);
//     }
//     // right
//     if (p() > 0.5 && j + 2 < offset && maze[i * offset + j + 2] != 1) {
//         maze[i * offset + j + 1] = 1;
//         set_passage(maze, size, i, j + 2);
//     }
//     // down
//     if (p() > 0.5 && i + 2 < offset && maze[(i + 2) * offset + j] != 1) {
//         maze[(i + 1) * offset + j] = 1;
//         set_passage(maze, size, i + 2, j);
//     }
// }


void get_impassable_maze(char *maze, int size) {
    int offset = size * 2 + 1;
    for (int i = 1; i < offset; i += 2) {
        for (int j = 1; j < offset; j += 2) {
            maze[i * offset + j] = 1;
        }
    }
}


void show_maze(char *maze, int size, char wall, char passage) {
    int offset = size * 2 + 1;
    for (int i = 0; i < offset; ++i) {
        for (int j = 0; j < offset; ++j) {
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

    get_impassable_maze(maze, size);

    show_maze(maze, size, wall, passage);
    
    return 0;
}
#include <stdio.h>
#include <stdlib.h>


void help() {
    printf("./range N - python range(N)\n");
    printf("./range M N - python range(M, N)\n");
    printf("./range M N S - python range(M, N, S)\n");
}

void range(long start, long stop, long step) {
    if (start < stop) {
        for (long i = start; i < stop; i += step) {
            printf("%ld\n", i);
        }
    } else {
        for (long i = start; i > stop; i += step) {
            printf("%ld\n", i);
        }
    }
}

int main(int argc, char **argv) {
    long N = 0, M = 0, S = 1;
    switch (argc) {
        case 1:
            help();
            break;
        case 2:
            N = strtol(argv[1], NULL, 10);
            N = N > 0 ? N : 0;
            range(M, N, S);
            break;
        case 3:
            M = strtol(argv[1], NULL, 10);
            N = strtol(argv[2], NULL, 10);
            if (M < N) {
                range(M, N, S);
            }
            break;
        case 4:
            M = strtol(argv[1], NULL, 10);
            N = strtol(argv[2], NULL, 10);
            S = strtol(argv[3], NULL, 10);
            if (S == 0) {
                printf("range arg 3 must not be zero\n");
                exit(1);
            }
            if ((M < N && S > 0) || (M > N && S < 0)) {
                range(M, N, S);
            }

            break;
        default:
            printf("Wrong number of arguments\n");
            exit(1);
    }
    return 0;
}










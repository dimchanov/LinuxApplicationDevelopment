#include <errno.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>


int close_or_remove(char **argv, FILE* infile, FILE* outfile, char with_error) {
    if (fclose(infile) == EOF) {
        fprintf(stderr, "Error closing %s\n", argv[1]);
        if (fclose(outfile) == EOF) {
            fprintf(stderr, "Error closing %s\n", argv[2]);
        }
        if (remove(argv[2]) == -1) {
            fprintf(stderr, "Error removing %s\n", argv[2]);
        }
        return 11;
    }

    if (fclose(outfile) == EOF) {
        fprintf(stderr, "Error closing %s\n", argv[2]);
        if (remove(argv[2]) == -1) {
            fprintf(stderr, "Error removing %s\n", argv[2]);
        }
        return 12;
    }

    if (with_error) {
        if (remove(argv[2]) == -1) {
            fprintf(stderr, "Error removing %s\n", argv[2]);
            return 13;
        }
    } else {
        if (remove(argv[1]) == -1) {
            fprintf(stderr, "Error removing %s\n", argv[1]);
            return 13;
        }
    }
    return 0;
}


int main(int argc, char **argv) {
    if (argc != 3) {
        fprintf(stderr, "Usage: ./move infile outfile\n");
        return 1;
    }

    FILE* infile = fopen(argv[1], "r");
    if (infile == NULL) {
        fprintf(stderr, "Error opening %s\n", argv[1]);
        return 2;
    }

    FILE *outfile = fopen(argv[2], "w");
    if (outfile == NULL) {
        fprintf(stderr, "Error opening %s\n", argv[2]);
        return 3;
    }

    char buffer[BUFSIZ];
    size_t bytes_count;
    while ((bytes_count = fread(buffer, sizeof(char), BUFSIZ, infile)) > 0) {
        size_t write_bytes_count = fwrite(buffer, sizeof(char), bytes_count, outfile);
        fflush(outfile);
        if (write_bytes_count != bytes_count || errno) {
            fprintf(stderr, "Error writing to %s\n", argv[2]);
            close_or_remove(argv, infile, outfile, 1);
            return 4;
        }
    }
    if (ferror(infile)) {
        fprintf(stderr, "Error reading from %s\n", argv[1]);
        close_or_remove(argv, infile, outfile, 1);
        return 5;
    }

    return close_or_remove(argv, infile, outfile, 0);
}




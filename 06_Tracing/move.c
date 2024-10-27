#include <stdio.h>
#include <stdlib.h>


int main(int argc, char **argv) {
    if (argc != 3) {
        fprintf(stderr, "Usage: ./move infile outfile\n");
        return 1;
    }

    FILE* infile = fopen(argv[1], "r");
    if (infile == NULL) {
        fprintf(stderr, "Error opening infile\n");
        return 2;
    }

    FILE *outfile = fopen(argv[2], "w");
    if (outfile == NULL) {
        fprintf(stderr, "Error opening outfile\n");
        return 3;
    }

    char buffer[BUFSIZ];
    size_t bytes_count;
    while ((bytes_count = fread(buffer, sizeof(char), BUFSIZ, infile)) > 0) {
        if (fwrite(buffer, sizeof(char), bytes_count, outfile) != bytes_count) {
            fprintf(stderr, "Error writing to file\n");
            fclose(infile);
            fclose(outfile);
            return 4;
        }
    }
    if (ferror(infile)) {
        fclose(infile);
        fclose(outfile);
        return 5;
    }

    fclose(infile);
    fclose(outfile);

    return 0;
}




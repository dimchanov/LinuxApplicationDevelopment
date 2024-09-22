#include <ncurses.h>
#include <locale.h>
#include <stdio.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <unistd.h>
#include <stdlib.h>


#define DX 5


int main(int argc, char **argv) {
	if (argc < 2) {
		fprintf(stderr, "Filename is missing\n");
		exit(1);
	}
	FILE *in_file;
	if ((in_file = fopen(argv[1], "r")) == NULL) {
		fprintf(stderr, "Cannot open file\n");
		exit(1);
	}
	struct stat in_file_info;
	stat(argv[1], &in_file_info);
	size_t in_file_size = in_file_info.st_size;
	char *buffer = malloc(in_file_size * sizeof(char));
	printf("in_file_size: %ld\n", in_file_size);
	fread(buffer, sizeof(char), in_file_size, in_file);
	fclose(in_file);
	int lines_count = 0;
	for (size_t i = 0; i < in_file_size; ++i) {
		if (buffer[i] == '\n') {
			lines_count += 1;
			buffer[i] = '\0';
		}
	}
	
	return 0;
}


#include <ncurses.h>
#include <locale.h>
#include <stdio.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <unistd.h>
#include <stdlib.h>
#include <string.h>


#define DX 3
#define DY 3


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
	char *buffer = malloc((in_file_size + 1) * sizeof(char));
	fread(buffer, sizeof(char), in_file_size, in_file);
	buffer[in_file_size] = '\0';
	fclose(in_file);
	
	int lines_count = 1;
	for (size_t i = 0; i < in_file_size; ++i) {
		if (buffer[i] == '\n') {
			lines_count += 1;
		}
	}

	char **lines = calloc(lines_count + 1, sizeof(char *));
	lines[0] = buffer;
	for (size_t i = 0, j = 1; i < in_file_size; ++i) {
		if (buffer[i] == '\n') {
			lines[j++] = buffer + i + 1;
			buffer[i] = '\0';
		}
	}
	
	setlocale(LC_ALL, "");
	initscr();
	noecho();
	cbreak();
	mvprintw(0, 0, "File: %s; size: %d\n", argv[1], lines_count);
	refresh();
	
	int w_height = LINES - 2 * DY;
	int w_width = COLS - 2 * DX;
	
	WINDOW *win = newwin(w_height, w_width, DY, DX);
	keypad(win, TRUE);
	scrollok(win, TRUE);
	
	char is_esc = 0;
	int X = 0, Y = 0, c;
	while (!is_esc) {
		werase(win);
		
		for (int row_i = 0; row_i < w_height - 1 && row_i + Y < lines_count; ++row_i) {
			mvwprintw(
				win, row_i, 0, "%4d: %s\n", row_i + Y + 1, 
				strlen(lines[row_i + Y]) > X ? lines[row_i + Y] + X : ""
				);
		}

		switch(c = wgetch(win)) {
			case 27: is_esc = TRUE; break;
			case 32:
			case KEY_NPAGE: Y = Y + (w_height - 1) < lines_count ? Y + (w_height - 1) : Y; break;
			case KEY_PPAGE: Y = Y - (w_height - 1) >= 0 ? Y - (w_height - 1) : 0; break;
			case KEY_UP: Y = Y > 0 ? Y - 1 : Y; break;
			case KEY_DOWN: Y = Y + 1 < lines_count ? Y + 1 : Y; break;
			case KEY_RIGHT: X++; break;
			case KEY_LEFT: X = X > 0 ? X - 1 : 0; break;
		}
	}
	
	free(lines);
	free(buffer);
	delwin(win);
	endwin();
	return 0;
}


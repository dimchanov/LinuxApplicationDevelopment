#include <ctype.h>
#include <regex.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAXGR 10
#define BUFFSIZE 256

int main(int argc, char **argv) {
    if (argc != 4) {
        printf("Usage: ./esub regexp substitution string");
        return 0;
    }
    char *pattern = argv[1];
    char *repl = argv[2];
    char *string = argv[3];
    printf("regexp: %s\nsubstitution: %s\nstring: %s\n", pattern, repl, string);

    regex_t regex;
    char errbuffer[BUFFSIZE];
    int errcode;
    if ((errcode = regcomp(&regex, pattern, REG_EXTENDED))) {
        regerror(errcode, &regex, errbuffer, BUFFSIZE);
        fprintf(stderr, "Error: %s\n", errbuffer);
        return 1;
    }

    regmatch_t bags[MAXGR];
    if ((errcode = regexec(&regex, string, MAXGR, bags, 0))) {
        regerror(errcode, &regex, errbuffer, BUFFSIZE);
        fprintf(stderr, "Error: %s\n", errbuffer);
        return 1;
    }

    int last_group_idx = 0;
    for (int i = 0; i < MAXGR && bags[i].rm_so >= 0; ++i) {
        printf("Group[%d]<span=(%d, %d), match=\'%.*s\'>\n", i, bags[i].rm_so, bags[i].rm_eo, bags[i].rm_eo - bags[i].rm_so, string + bags[i].rm_so);
        last_group_idx = i;
    }

    regfree(&regex);
    return 0;
}

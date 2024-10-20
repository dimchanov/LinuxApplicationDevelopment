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

    char backslash = 0;
    int new_repl_len = strlen(repl);
    int new_repl_pos = 0;
    char *new_repl = (char *)malloc(new_repl_len * sizeof(char));
    for (int i = 0; i < strlen(repl); ++i) {
        // printf("new_repl %d: %s\n", i, new_repl);
        if (repl[i] == '\\') {
            if (backslash) {
                new_repl[new_repl_pos] = '\\';
                ++new_repl_pos;
                backslash = 0;
            } else {
                backslash = 1;
            }
        } else {
            if (backslash && isdigit(repl[i])) {
                int bag_idx = repl[i] - '0';
                if (bag_idx > last_group_idx) {
                    // printf("There is no group with number %d\n", bag_idx);
                    return 2;
                }
                int bag_len = bags[bag_idx].rm_eo - bags[bag_idx].rm_so;
                new_repl_len += bag_len;
                new_repl = realloc(new_repl, new_repl_len);
                for (int j = 0; j < bag_len; ++j) {
                    new_repl[new_repl_pos] = string[bags[bag_idx].rm_so + j];
                    ++new_repl_pos;
                }
            } else {
                new_repl[new_repl_pos] = repl[i];
                ++new_repl_pos;
            }
            backslash = 0;
        }
    }
    new_repl[new_repl_pos] = 0;
    printf("new_repl: %s\n", new_repl);

    free(new_repl);
    regfree(&regex);
    return 0;
}

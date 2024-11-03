#include <ctype.h>
#include <errno.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include <rhash.h>




int custom_getline(char **lineptr, size_t *line_len, FILE *stream) {
    int res;
    printf("> ");
    res = getline(lineptr, line_len, stream);
    (*lineptr)[strlen(*lineptr) - 1] = 0;
    if (res == -1) {
        printf("\n");
    }
    return res;
}


int hash_name2type(const char *hash_name) {
    if (!strcasecmp(hash_name, "SHA1")) {
        return RHASH_SHA1;
    } else if (!strcasecmp(hash_name, "MD4")) {
        return RHASH_MD4;
    } else if (!strcasecmp(hash_name, "MD5")) {
        return RHASH_MD5;
    } else if (!strcasecmp(hash_name, "TTH")) {
        return RHASH_TTH;
    } else {
        return -1;
    }
}


int main(int argc, char **argv) {
    unsigned char digest[64];
    char output[130];
    rhash_library_init();

    char *lineptr = NULL;
    size_t line_len = 0;
    
    while (custom_getline(&lineptr, &line_len, stdin) != -1) {

        char *hash_name = strtok(lineptr, " ");
        if (!hash_name) {
            fprintf(stderr, "Enter <hash algorithm name> <file name or a string>\n");
            continue;
        }

        int hash_type = hash_name2type(hash_name);
        if (hash_type == -1) {
            fprintf(stderr, "Incorrect hash function\n");
            continue;
        }

        char *msg = strtok(NULL, " ");
        if (!msg) {
            fprintf(stderr, "The second argument must be a file name or a string\n");
            continue;
        }

        int res = 0;
        if (msg[0] == '"') {
            res = rhash_msg(hash_type, msg + 1, strlen(msg) - 1, digest);
        } else {
            res = rhash_file(hash_type, msg, digest);
        }

        if(res < 0) {
            fprintf(stderr, "LibRHash error: (%s) %s\n", msg, strerror(errno));
            continue;
        }

        rhash_print_bytes(
            output, digest, rhash_get_digest_size(RHASH_TTH),
            islower(hash_name[0]) ? RHPR_BASE64 : RHPR_HEX);
            
        printf("%s\n", output);
    }

    if (lineptr != NULL)
        free(lineptr);

    return 0;
}
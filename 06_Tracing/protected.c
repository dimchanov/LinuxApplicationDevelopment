#include <string.h>
#include <unistd.h>


int remove(char *filename) {
    if (!strstr(filename, "PROTECT")) {
        return unlink(filename);
    }
    return 0;
}

#include <stdio.h>
#include <stdlib.h>
#include <sys/stat.h>
#include <errno.h>

const char *name = "Arbitrary Directory";

int main(void) {

    errno = 0;
    int ret = mkdir(name, S_IRWXU);
    if (ret == -1) {
        switch (errno) {
            case EACCES :
                printf("the parent directory does not allow write");
                exit(EXIT_FAILURE);
            case EEXIST:
                printf("pathname already exists");
                exit(EXIT_FAILURE);
            case ENAMETOOLONG:
                printf("pathname is too long");
                exit(EXIT_FAILURE);
            default:
                perror("mkdir");
                exit(EXIT_FAILURE);
        }
    }

    exit(EXIT_SUCCESS);
}
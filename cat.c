#include<stdio.h>
#include<stdlib.h>

#define BOLD_RED() printf("\033[1;31m")
#define BOLD_BLUE() printf("\033[1;34m")
#define RESET() printf("\033[0m")

int main(int argc, char *argv[])
{
    FILE *fp;
    char *line = NULL;
    size_t len = 0;
    ssize_t read;

    if(argc < 2)
    {
        BOLD_RED();
        printf("ERROR: No File provided to read.\n");
        RESET();
        exit(1);
    }

    fp = fopen(argv[1],"r");
    if(fp == NULL)
    {
        BOLD_RED();
        printf("ERROR: The file doesn't exist.\n");
        RESET();
        exit(EXIT_FAILURE);
    }

    while((read = getline(&line,&len,fp))!= -1)
    {
        printf("%s",line);
    }
    printf("\n");

    if(line)
    {
        free(line);
    }

    fclose(fp);
    exit(EXIT_SUCCESS);
}
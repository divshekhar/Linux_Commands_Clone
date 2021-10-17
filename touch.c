#include<stdio.h>

int main(int agrc, char*agrv[])
{
    File *file;
    // open file with write permission
    file = open(argv[1],"w");
    fclose(file);
}

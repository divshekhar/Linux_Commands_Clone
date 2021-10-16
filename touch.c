#include<stdio.h>
int main(int agrc, char*agrv[])
{
    File *file;
    file = open(argv[1],"w");
    fclose(file);
}
#include<stdio.h>
#include<dirent.h>
#include<string.h>
#include<errno.h>
#include<stdlib.h>

#define BOLD_RED() printf("\033[1;31m")
#define BOLD_BLUE() printf("\033[1;34m")
#define RESET() printf("\033[0m")

int listDir(const int argc, const char *path)
{
    DIR *dir;
    struct dirent *dirp;
    if(argc !=2 )
    {
        if((dir = opendir("./")) == NULL)
        {
            BOLD_RED();
            printf("Cannot Open Current Directory : %s\n", strerror(errno));
            RESET();
            exit(1);
        }
    }
    else
    {
        if((dir = opendir(path)) == NULL)
        {
            BOLD_RED();
            printf("ERROR: %s\n", strerror(errno));
            RESET();
            exit(1);
        }
    }

    while ((dirp = readdir(dir))!=NULL)
    {
        if(dirp->d_type == DT_DIR)
        {
            BOLD_BLUE();
            printf("/%s\n", dirp->d_name);
            RESET();
        }
        else
        {
            printf("/%s\n",dirp->d_name);
        }
        
    }
    closedir(dir);
    exit(0);
    
}

int main(int argc,char *argv[])
{
    listDir(argc,argv[1]);
    return 0;
}



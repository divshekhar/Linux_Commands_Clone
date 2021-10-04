#include<stdio.h>
#include<unistd.h>
int main()
{
    char s[100];
    //Printing the current working directory
    printf("%s\n",getcwd(s,100));
    //Changing the current working directory to the previous directory
    chdir("..");
    //Printing the now current working directory
    printf("%s\n",getcwd(s,100));
    return 0;
}

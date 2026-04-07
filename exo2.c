#include<stdio.h>
#include<unistd.h>
#include<stdlib.h>
#include<sys/types.h>
#include<sys/wait.h>

int main()
{
    pid_t pid1 = fork();
    
    if( pid1 == -1 )
    {
        puts("Erreur lors de la creation du fils 1.");
        exit(1) ;
    }
    if( pid1 == 0 )
    {   
        printf("Je suis le fils 1\n");
        exit(0);
    }
    
    pid_t pid2 = fork();
    if( pid2 == -1 )
    {
        puts("Erreur lors de la creation du fils 2.");
        exit(1) ;
    }
    if( pid2 == 0 )
    {   
        printf("Je suis le fils 2\n");
        exit(0);
    }
    wait(NULL);
    wait(NULL);

    printf("Je suis le pere.\n");
    return 0;
}
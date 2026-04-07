#include<stdio.h>
#include<unistd.h>
#include<stdlib.h>
#include<sys/types.h>

int main()
{
    pid_t pid = fork();
    
    if( pid == -1 )
    {
        puts("Erreur lors de la creation du fils.");
        exit(1) ;
    }
    else if( pid == 0 )
    {   
        printf("Je suis le fils\n");
    }
    else
    {
        printf("Je suis le pere\n");
    }
    return 0;
}
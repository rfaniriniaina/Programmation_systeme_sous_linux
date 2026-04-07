#include<stdio.h>
#include<stdlib.h>
#include<unistd.h>
#include<sys/types.h>

int main()
{
    for( int i=0 ; i<5 ; i++ )
    {
        pid_t pid = fork();
        if( pid == -1 )
        {
            puts("Erreur lors de la creation du fils.");
            exit(1) ;
        }
        if( pid == 0 )
        {
            printf("Je suis le fils %d, PID-%d = %d.\n", i+1, i+1, getpid());
            break;
        }
    }
    printf("Je suis le pere, PID = %d.\n", getppid());
    return 0;
}

#include<stdio.h>
#include<unistd.h>
#include<stdlib.h>
#include<sys/types.h>
#include<sys/wait.h>

int main()
{
    time_t debut = time(NULL);
    int time1, time2;
    pid_t pid1 =  fork();
    if( pid1 == -1)
    {
        puts("Erreur lors de la creation du fils 1.");
        exit(1);
    }
    if( pid1 == 0 )
    {
        time1 = ((getpid() + time(NULL)) % 10) +1;
        if( time1 == 1 )
        {
            printf("Le fils 2 a dormi 1 seconde.\n ");
        }
        else
        {
            printf("Le fils 1 a dormi %d secondes.\n", time1);
            sleep(time1);
        }
        exit(0);
    }

    pid_t pid2 =  fork();
    if( pid2 == -1)
    {
        puts("Erreur lors de la creation du fils 2.");
        exit(1);
    }
    if( pid2 == 0 )
    {
        time2 = ((time(NULL) + getpid()) % 10) + 1;
        if( time2 == 1 )
        {
            printf("Le fils 2 a dormi 1 seconde.\n ");
        }
        else
        {
            printf("Le fils 2 a dormi %d secondes.\n", time2);
            sleep(time2);
        }
        exit(0);
    }
    wait(NULL);
    wait(NULL);


    time_t fin = time(NULL);
    
    int total_time = fin - debut;
    printf("La duree totale est: %d secondes.\n", total_time);
    return 0;
}
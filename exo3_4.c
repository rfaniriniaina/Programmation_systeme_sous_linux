#include<stdio.h>
#include<stdlib.h>
#include<unistd.h>
#include<string.h>
#include<sys/wait.h>

int main()
{
    while(1)
    {
        char rep[100];
        printf("Saisissez des noms de repertoires ou 'q/Q' pour quitter : \n");
        scanf("%s", rep);
        
        if(strcmp(rep,"q") == 0 || strcmp(rep, "Q") == 0)
        {
            break;
        }
        if( fork() == 0 )
        {
            execlp("cp", "cp", "-r", ".", rep, NULL );
            return 0;
        }
        wait(NULL);
    }
    return 0;
}
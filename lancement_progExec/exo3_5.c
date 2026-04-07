#include<stdio.h>
#include<stdlib.h>
#include<unistd.h>
#include<string.h>
#include<sys/wait.h>

int main()
{
    while(1)
    {
        char file[256];
        printf("Saisissez des noms de fichier ou 'q/Q' pour quitter : \n");
        scanf("%s", file);
        
        if(strcmp(file,"q") == 0 || strcmp(file, "Q") == 0)
        {
            break;
        }
        
        pid_t pid = fork();
        if( pid == 0 )
        {
            execlp("emacs", "emacs", ".", file, NULL );
            perror("Erreur");
            return 1;
        }
        else
        {
            wait(NULL);
        }
    }
    return 0;
}
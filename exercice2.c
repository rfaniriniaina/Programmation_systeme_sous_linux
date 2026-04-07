
#include<unistd.h>
#include<stdio.h>
#include<stdlib.h>
#include<sys/wait.h>
#include<sys/types.h>
#include<string.h>

int main()
{
    int d1[2]; //fils -> pere
    int d2[2]; //pere -> fils

    pipe(d1);
    pipe(d2);

    pid_t pid = fork();
    if( pid == 0)
    {
        dup2(d1[1], STDOUT_FILENO); //redirection stdout vers d1
        dup2(d2[0], STDIN_FILENO); //redirection stdin vers d2
        close(d1[0]);
        close(d1[1]);
        close(d2[0]);
        close(d2[1]);

        char mot[100];
        printf("Entrez un mot : ");
        scanf("%s", mot);

        printf("%s", mot); //envoyer au pere via stdout
        int valeurR;
        scanf("%d", mot);
    }

    else
    {
        dup2(d1[0], STDOUT_FILENO); 
        dup2(d2[1], STDIN_FILENO); 
        close(d1[0]);
        close(d1[1]);
        close(d2[0]);
        close(d2[1]);
        
        char mot[100];
        scanf("%s", mot); //depuis le fils

        
        FILE *fp = fopen("fichier.txt", "r");
        if(fp == NULL)
        {
            printf("Erreur lors de l'ouverture du fichier\n");
            exit(1);
        }

        int found = 0;
        char mot_fichier[100];

        while(fscanf(fp, "%s", mot_fichier) != EOF)
        {
            if(strcmp(mot, mot_fichier) == 0)
            {
                found = 1;
                break;
            }
        }

        fclose(fp);
        printf("%d\n", found);
        wait(NULL);
    }
    
    return 0;
}
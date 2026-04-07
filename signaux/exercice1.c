#include<stdio.h>
#include<stdlib.h>
#include<unistd.h>
#include<signal.h>
#include<sys/types.h>

int main() 
{
    pid_t pid;
    char choix;

    pid = fork();

    if (pid < 0) 
    {
        perror("Erreur");
        exit(1);
    }

    if (pid == 0) 
    {
        printf("Fils (PID %d) : Début du calcul infini\n", getpid());
        unsigned long i = 0;

        while (1) 
        {
            i++; 
        }
    } 
    else 
    {
        do 
        
        {
            printf("s : Endormir le fils (SIGSTOP)\n");
            printf("r : Redémarrer le fils (SIGCONT)\n");
            printf("q : Tuer le fils et quitter (SIGKILL)\n");
            printf("Votre choix : ");
            
            scanf(" %c", &choix);

            switch (choix) 
            {
                case 's':
                    if (kill(pid, SIGSTOP) == 0)
                        printf("Signal SIGSTOP envoyé au fils.\n");
                    break;
                case 'r':
                    if (kill(pid, SIGCONT) == 0)
                        printf("Signal SIGCONT envoyé au fils.\n");
                    break;
                case 'q':
                    if (kill(pid, SIGKILL) == 0) 
                    {
                        printf("Fils éliminé. Fermeture du programme.\n");
                    }
                    break;
                default:
                    printf("Option invalide.\n");
            }
        } 
        while (choix != 'q');
    }

    return 0;
}
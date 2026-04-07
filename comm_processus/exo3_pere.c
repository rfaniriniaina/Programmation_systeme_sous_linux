
#include<unistd.h>
#include<stdio.h>
#include<stdlib.h>
#include<sys/types.h>
#include<string.h>
#include<sys/wait.h>

int main(int argc, char *argv[])
{
    int t[2];
    pipe(t);

    int d1 = t[0];
    int d2 = t[1];

    pid_t pid = fork();
    if( pid == 0)
    {
        close(d2);

        char fd[20];
        sprintf(fd, "%d", d1); //transforme d1 en texte fd
        char *args[] = {"./fils", fd, NULL};
        execv(args[0], args);

        perror("Erreur");
        exit(1);
    }

    else
    {
        close(d1);

        char *m = "Salut le fils";
        write(d2, m, strlen(m)+1);

        close(d2);
        wait(NULL);
    }
    return 0;
}
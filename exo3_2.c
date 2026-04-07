#include<stdio.h>
#include<stdlib.h>
#include<unistd.h>

int main(int argc, char *argv[])
{
    if( argc<2 )
    {
        puts("Le programme n'a recu aucun argument. ");
        exit(1);
    }
    execlp("cp", "cp", "-r", argv[1], ".", NULL);
    perror("Problème : cette partie du code ne doit jamais être exécutée");
    return 1;
}
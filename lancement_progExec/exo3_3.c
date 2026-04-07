#include<stdio.h>
#include<stdlib.h>
#include<unistd.h>

int main()
{
    char file[100];
    printf("Saisissez un nom de fichier texte : ");
    scanf("%s", file);
    execl("/usr/bin/emacs", "emacs", file, NULL);
    perror("Erreur");
    return 1;
}
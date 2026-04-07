
#include<fcntl.h>
#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<sys/stat.h>
#include<sys/types.h>


int main()
{
    int d1[2]; //fils -> pere
    int d2[2]; //pere -> fils

    pipe(d1);
    pipe(d2);

    pid_t pid = fork();
    if( pid == 0)
    {
        close(d1[0]);
        close(d2[1]);

        char mot[100];
        printf("Entrez un mot : ");
        scanf("%s", mot);

        write(d1[1], mot, sizeof(mot)); //envoyer au pere
        int valeurR;
        read(d2[0], &valeurR, sizeof(valeurR)); //recevoir le resultat

        close(d1[1]);
        close(d2[0]);
    }

    else
    {
        close(d1[1]);
        close(d2[0]);  
        
        char mot[100], mot_fichier[100];
        int found = 0;
        read(d1[0], mot, sizeof(mot)); //recevoir du fils

        FILE *fp = fopen("fichier.txt", "r");
        if(fp == NULL)
        {
            printf("Erreur lors de l'ouverture du fichier\n");
            exit(1);
        }

        while(fscanf(fp, "%s", mot_fichier) != EOF)
        {
            if(strcmp(mot, mot_fichier) == 0)
            {
                found = 1;
                break;
            }
        }

        fclose(fp);

        write(d2[1], &found, sizeof(found)); //envoyer le resultat au fils

        close(d1[0]);
        close(d2[1]);
    }
    
    return 0;
}
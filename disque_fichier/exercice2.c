#include<stdio.h>
#include<stdlib.h>
#include<dirent.h>
#include<sys/stat.h>
#include<sys/types.h>
#include<string.h>

#define MO (1024*1024)

int main(int argc, char **argv)
{
    int i , retour , taille;
    DIR *dir;
    struct dirent *contenu;
    struct stat st;
    char *chemin;

    for(i=1 ; i<argc ; i++)
    {
        dir = opendir(argv[i]);
        if(!dir)
        {
            printf("Erreur d'ouverture du dossier %s .\n"  , argv[i]);
            continue;
        }
        contenu  = readdir(dir) ;

        while(contenu != NULL)
        {
            taille = strlen(argv[i]) + strlen(contenu->d_name) + 1;
            chemin = malloc(taille * sizeof(char));

            sprintf(chemin , "%s/%s" , argv[i] , contenu->d_name);

            contenu  = readdir(dir) ;
            retour = stat(chemin, &st);
            if(retour != 0)
            {
                free(chemin);
            }

            else if(S_ISREG(st.st_mode) && (st.st_size >= MO))
            {
                printf("%s taille=%ldMo UID=%d\n" , chemin , (long)st.st_size / MO , (int)st.st_uid);
                free(chemin);
            }
        }
        closedir(dir);
    }
    return (0);
}
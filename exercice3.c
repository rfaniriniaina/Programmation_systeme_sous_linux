#include<stdio.h>
#include<stdlib.h>
#include<fcntl.h>
#include<unistd.h>

int main()
{
    int n , i , fd;
    int *tab;

    printf("Nombre d'entiers : ");
    scanf("%d", &n);

    tab = malloc(n * sizeof(int));
    for(i = 0; i < n; i++)
    {
        printf("tab[%d] = ", i);
        scanf("%d", &tab[i]);
    }
    fd = open("entiers.bin" , O_WRONLY | O_CREAT | O_TRUNC , 0644); /* rw-r--r-- */
    if(fd < 0)
    {
        printf("Erreur d ouverture du fichier .\n");
    }
    else
    {
        write(fd , tab , (n*sizeof(int)) );
        printf("Ecrit dans entiers.bin .\n");
    }

    close(fd);
    free(tab);
    return (0);
}
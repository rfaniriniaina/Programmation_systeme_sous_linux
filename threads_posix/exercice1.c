#include <stdio.h>
#include <stdlib.h>
#include <pthread.h>

typedef struct
{
    int *tab;
    int taille;
} Affiche;

void *generate_tab(void *arg)
{
    Affiche *p = (Affiche *)arg;
    
    printf("Tableau : ");
    for( int i=0 ; i<p->taille ; i++ )
    {
        printf("%d ", p->tab[i]);
    }
    printf("\n");
    return NULL;
}

int main()
{
    int tab[10] = {1, 2, 3, 4, 5, 6, 7, 8, 9, 10};
    pthread_t tid;
    Affiche p = {tab, 10};

    pthread_create(&tid, NULL, generate_tab, &p);
    pthread_join(tid, NULL);
    return 0;
}
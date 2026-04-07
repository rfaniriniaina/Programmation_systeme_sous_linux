#include<stdio.h>
#include<stdlib.h>
#include<pthread.h>
#include<time.h>

typedef struct{
    int *tab;
    int n;
    int x;    
} TypeTableau;

void* generate_tab(void* arg);
void *find(void* arg);

void* generate_tab(void* arg)
{
    TypeTableau *t = (TypeTableau*) arg;
    t->tab = malloc(t->n * sizeof(int));

    srand(time(NULL));
    for( int i=0 ; i<t->n ; i++ )
    {
        t->tab[i] = rand() % 100;
    }
    return NULL;
}

//chercher x dans le tableau
void *find(void* arg)
{
    TypeTableau *t = (TypeTableau*) arg;
    for( int i=0 ; i<t->n ; i++ )
    {
        if( t->tab[i] == t->x )
        {
            return (void*)1;
        }
    }
    return (void*)0;
}

int main()
{
    pthread_t tid1, tid2;
    TypeTableau t;

    printf("Donner la taille du tableau : ");
    scanf("%d", &t.n);
    printf("Donner la valeur de x (à rechercher) : ");
    scanf("%d", &t.x);

    pthread_create(&tid1, NULL, generate_tab, &t);
    pthread_join(tid1, NULL);

    printf("Tableau rempli : ");
    for( int i=0 ; i<t.n ; i++ )
    {
        printf("%d ", t.tab[i]);
    }
    printf("\n");

    void *result;
    pthread_create(&tid2, NULL, find, &t);
    pthread_join(tid2, &result);
    if( result == (void*)1 )
    {
        printf("%d est dans le tableau.\n", t.x);
    }
    else
    {
        printf(" %d n'est pas dans le tableau.\n", t.x);
    }   

    free(t.tab);
    return 0;
}

#include<stdio.h>
#include<stdlib.h>
#include<pthread.h>
#include<time.h>

#define N 10

void *generate_tab(void* arg)
{
    srand(time(NULL));
    int *tab = malloc(N * sizeof(int));

    for( int i=0 ; i<N ; i++)
    {
        tab[i] = rand() % 100;
    }
    return tab;
}

int main()
{
    pthread_t tid;
    int n = 5;
    int *result;

    pthread_create(&tid, NULL, generate_tab, &n);
    pthread_join(tid, (void**)&result);

    for( int i=0 ; i<N ; i++ )
    {
        printf("%d ", result[i]);
    }
    printf("\n");
    free(result);
    
    return 0;
}
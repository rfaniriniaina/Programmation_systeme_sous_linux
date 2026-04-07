#include<stdio.h>
#include<stdlib.h>
#include<pthread.h>
#include<time.h>

#define TAILLE1 8
#define TAILLE2 15

typedef struct 
{
    int *tab;
    int taille;
}Tableau;

typedef struct 
{
    Tableau *T1;
    Tableau *T2;
}Inclus;

void *generate_tab(void *arg) 
{
    Tableau *t = (Tableau *)arg;
    t->tab = malloc(t->taille * sizeof(int));

    for (int i = 0; i < t->taille; i++)
    {
        t->tab[i] = rand() % 20; 
    }
    return NULL;
}

void *inclusion(void *arg) 
{
    Inclus *p = (Inclus *)arg;
    int *result = malloc(sizeof(int));
    *result = 1;

    for (int i = 0; i < p->T1->taille; i++) 
    {
        int trouve = 0;
        for (int j = 0; j < p->T2->taille; j++) 
        {
            if (p->T1->tab[i] == p->T2->tab[j]) 
            { 
                trouve = 1; 
                break; 
            }
        }
        if (!trouve) 
        {
             *result = 0; 
             break; 
        }
    }
    pthread_exit(result);
}

void *cancel(void *arg) 
{
    char c;
    while (1) {
        c = getchar();
        if (c == 'A' ) {
            printf("\nAnnulatio...\n");
            exit(0);
        }
    }
    return NULL;
}

int main() {
    srand(time(NULL));

    Tableau T1 = {NULL, TAILLE1};
    Tableau T2 = {NULL, TAILLE2};
    pthread_t tid1, tid2, tid_kb, tid_incl;

    /* Générer T1 et T2 en parallèle */
    pthread_create(&tid1, NULL, generate_tab, &T1);
    pthread_create(&tid2, NULL, generate_tab, &T2);

    /* Surveillance clavier en parallèle */
    pthread_create(&tid_kb, NULL, cancel, NULL);
    pthread_detach(tid_kb);

    pthread_join(tid1, NULL);
    pthread_join(tid2, NULL);

    printf("T1 (%d elements) : ", T1.taille);
    for (int i = 0; i < T1.taille; i++) printf("%d ", T1.tab[i]);
    printf("\nT2 (%d elements) : ", T2.taille);
    for (int i = 0; i < T2.taille; i++) printf("%d ", T2.tab[i]);
    printf("\n(Appuyez sur 'A' + Entrée pour annuler)\n");

    Inclus param = {&T1, &T2};
    pthread_create(&tid_incl, NULL, inclusion, &param);

    int *res;
    pthread_join(tid_incl, (void **)&res);

    if (*res)
        printf("T1 est inclus dans T2.\n");
    else
        printf("T1 n'est pas inclus dans T2.\n");

    free(res);
    free(T1.tab);
    free(T2.tab);
    return 0;
}

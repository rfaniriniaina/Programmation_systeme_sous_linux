#include<stdio.h>
#include<stdlib.h>
#include<math.h>

//exo 3.1
int somme(int a, int b)
{
    printf("%d + %d = %d\n",a, b, a+b);
}

int main(int argc, char *argv[])
{
    int a = atoi(argv[1]);
    int b = atoi(argv[2]);
    int s = somme(a, b);
    if( argc == 1)
    {
        puts("Le programme n'a recu aucun argument.\n");
        exit(1);
    }
    return 0;
}
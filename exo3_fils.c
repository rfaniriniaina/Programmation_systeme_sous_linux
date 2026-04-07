#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>

int main(int argc, char *argv[])
{
    if( argc < 2 )
    {
        perror("Erreur");
        return 1;
    }

    int d1 = atoi(argv[1]);
    char m[100];
    read(d1, m, sizeof(m));
    printf("Fils: Message recu : %s\n", m);
    close(d1);
    return 0;
}
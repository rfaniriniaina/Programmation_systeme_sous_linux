#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>

int main(int argc, char *argv[])
{
    char *s = getenv("DESCRIPTEUR");
    
    int d1 = atoi(argv[1]);
    char m[100];
    read(d1, m, sizeof(m));
    printf("Fils: Message recu : %s\n", m);
    close(d1);
    return 0;
}
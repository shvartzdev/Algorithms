#include <stdio.h>
#include <string.h>
#include <stdlib.h>

void substring(char *s, char *p)
{
    int i, j;
    unsigned long N, M;
    N = strlen(s);
    M = strlen(p);

    int *d =(int*)malloc(M * sizeof(int));

    d[0] = 0;
    for(i = 1, j = 0;i < M;i++)
    {
        while(j > 0 && p[j]!=p[i])
            j = d[j-1];
        if(p[j] == p[i])
            j++;
        d[i] = j;
    }

    for(i = 0,j = 0;i < N; i++)
    {
        while(j > 0 && p[j]!=s[i])
            j = d[j-1];
        if(p[j] == s[i])
            j++;
        if (j == M) printf("%d ", i-j+1);
    }
    free (d);
}

int main(int argc, char **argv)
{
    char *p = argv[1];
    char *t = argv[2];
    substring(t,p);
}

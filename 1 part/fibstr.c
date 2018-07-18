#include <stdio.h>
#include <stdlib.h>
#include <string.h>

char *fibstr(int n);

int main() {
    int n;
    scanf("%d", &n);
    char *s = fibstr(n);
    printf("%s\n", s);
    free(s);
    return 0;
}

char *fibstr(int n)
{
    int a[n], i = 0,size;
    for (i = 0; i < n; i++) {
        if (i == 0) a[i] = 1; else if (i == 1) a[i] = 1; else
            a[i] = a[i-1] + a[i-2];
    }
    size = a[n-1] + 1;
    
    char *s1 = (char*) malloc(size * sizeof(char));
    char *s2 = (char*) malloc(size * sizeof(char));
    char *s3 = (char*) malloc(size * sizeof(char));
    
    strcpy(s1, "a");
    strcpy(s2, "b");
    
    if (n == 1) strcpy(s3, s1); else if (n == 2)
        strcpy(s3, s2);
    
    for(int i = 3; i <= n; i++) {
        strcat(s1, s2);
        strcpy(s3, s1);
        strcpy(s1, s2);
        strcpy(s2, s3);
    }
    free(s1);
    free(s2);
    return s3;
}

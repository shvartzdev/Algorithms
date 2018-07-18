#include <stdio.h>
#include <stdlib.h>
#include <math.h>
//решето Эратосфена

int main()
{
    long long n = 0;
    unsigned long long  i = 0, j = 0, k = 0;
    scanf ("%lld", &n);
    if (n < 0) n = n*(-1);
    unsigned long long m = n;
    long long h = sqrt(n);
    
    long a[h+1];
    for (i = 0; i <= h; i++) a[i] = 0;
    i = 2;
    while (i <= h)
    {
        if (a[i] == 0 ) {j = 2*i;
        while (j <= h){
            a[j] = 1;
            j+=i;
            }
        }
        i++;
        
    }
    for (i = 2; i<= sqrt(m); i++){
        if ((a[i]==0) && ((n % i) == 0)) {
            n /= i;
            if (i > k) k = i; i = 1;
        }
    }
    if (n == 1) printf("%llu\n", k); else printf("%llu\n", n);
    
    return 0;
}

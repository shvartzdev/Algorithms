#include <stdio.h>

int main()
{
    unsigned long long int a[100],n=0;
    a[0]=1;
    a[1]=1;
    int i;
    scanf("%llu",&n);
    for (i=2;a[i-1]<n;i++) {
        a[i]=a[i-2]+a[i-1];
    }
    i=i-1;
    if(n==0){
        printf("0");
    }
    else if(n==1){
        printf("1");
    }
    else{
        if(a[i]>n)
            i--;
        for( ; i > 0; i--) {
            if (a[i]>n) {
                printf("0");
            }
            if (a[i] <= n) {
                printf("1");
                n = n-a[i];
            }
        }
    }
    return 0;
}

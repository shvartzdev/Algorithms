#include <stdio.h>
#include <stdlib.h>
int main()
{
    int *a;
    
    int i=0, k=0, n=0;
    
    int max=0,sum1=0,sum2=0;
    
    scanf("%d", &n);
    
    a = (int *)malloc(n * sizeof(int));
    
    for (i = 0; i < n; i++) {
        scanf("%d", &a[i]);
    }
    
    scanf("%d", &k);
    
    for (i = 0; i < k; i++) {
        sum1=sum1+a[i];
        max=sum1;
    }
    
    for (i=k;i<n;i++){
        sum2=sum1+a[i]-a[i-k];
        if(max<sum2){
            max=sum2;
        }
        sum1=sum2;
    }
    
    if(k==n)
        max=sum1; 
        
    printf("%d\n",max);
    free(a);
    return 0;
}

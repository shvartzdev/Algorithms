#include <stdio.h>
int main()
{
    int a=0,b=0, q = 1;
    int n,m,i,c,d;
    scanf("%d", &n);
    
    for (i = 0;i < n; i++) {
        scanf("%d", &c);
        q = 1 << c;
        a = a+q;
    }
    
    scanf("%d", &m);
    for (i = 0; i < m; i++) {
        scanf("%d", &d);
        q=1 << d;
        b = b+q;
    }
    
    a = (a & b);
    
    for (i = 0; i <=31; i++) {
        if (a & (1 << i)) printf("%d ", i);
    }
    
    return 0;
}

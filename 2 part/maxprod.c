#include <stdio.h>
#include <stdlib.h>
#include <math.h>

void kadane (double *mas, int n)
{
    double maxsum = *mas, sum = 0;
    int  l = 0, r = 0, i = 0, start = i;
    while (i < n) {
        sum += mas[i];
        if (sum > maxsum) {
            maxsum = sum;
            l = start;
            r = i;
        }
        if (sum < 0) {
            sum = 0;
            start = i + 1;
        }
        i++;
    }
    printf("%d\n",l);
    printf("%d\n",r);
}


int main()
{
    int n, i = 0;
    scanf("%d", &n);
    double *arr = calloc(n, sizeof (double));
    double a,b;
    for (i = 0; i < n; i++)  {
        scanf("%lf/%lf", &a, &b);
        arr[i] = log2(a/b);
    }
    //printf("\n");
    //for (i = 0; i < n; i++) printf("%lf", arr[i]);
    kadane(arr, n);
    free(arr);
}

void shellsort (unsigned long nel, int(*compare) (unsigned long i, unsigned long j), void (*swap) (unsigned long i, unsigned long j))
{
    int a[1000], i, j = 2;
    a[0] = 1;
    if (nel >= 1) a[1] = 1;
    while (nel > a[j - 1]){
        a[j] = a[j - 1] + a[j - 2];
        j++;
    }
    int k = j--;
    int max = a[k - 1];
    int t = 0;
    
    for (j = 0; j < k/2 ; j++) {
        t = a[j];
        a[j] = a[k - j - 1];
        a[k - j -1] = t;
    }
    int loc = 0;
    j = 1;
    while (j < k) {
        i = 1;
        while (i < nel)  {
            loc = i - max;
            while ((loc >= 0)  && (compare (loc, loc+max) == 1) ) {
                swap (loc, loc+max);
                loc -= max;
            }
            i++;
        }
        max = a[j];
        j++;
    }
}

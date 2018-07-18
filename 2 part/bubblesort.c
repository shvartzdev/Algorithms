void bubblesort (unsigned long nel, int (*compare) (unsigned long i, unsigned long j), void (*swap)(unsigned long i, unsigned long j))
{
    unsigned long left = 0, right = nel - 1, key = 0, i = 0;
    while (left != right) {
        for (i = left = key; i < right; ++i){
                if (compare (i, i+1) == 1) {
                    swap (i, i+1);
                    key = i;
                }
            }
        
        for (i = right = key; i > left; --i) {
            if (compare (i, i-1)  == -1) {
                swap (i, i-1);
                key = i;
            }
        }
    }
}

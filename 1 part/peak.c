unsigned long peak(unsigned long nel, int (*less)(unsigned long i, unsigned long j))
{
    int i = 0;
    for (i = 0; i < nel; i++){
        if ((i == 0) && (less (i, i+1) == 0)) return i;
        if ((i == (nel - 1) && (less (i, i -1)) == 0)) return i;
        if (less(i, i+1) == 0) return i;
    }
}

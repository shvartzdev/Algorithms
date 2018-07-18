unsigned long binsearch(unsigned long nel, int (*compare)(unsigned long i))
{
    unsigned long h = nel - 1, l =0;
    unsigned long middle = (l + h)/2;
    unsigned long middle2 = 0;
    
    if (compare(l) == 0) return l;
    if (compare(h) == 0) return h;
    
    for (;;) {
        middle = (l + h)/2;
        if (middle == middle2) {
            return nel;
        }
        middle2 = middle;
        
        if (compare (middle) < 0) {
            l = middle;
        }
        else if (compare (middle) > 0) {
            h = middle;
        }
        else if (compare(middle) == 0)
            return middle;
    }
}

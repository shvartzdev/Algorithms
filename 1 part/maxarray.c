int maxarray(void *base, unsigned long nel, unsigned long width,
             int (*compare)(void *a, void *b))
{
    
    char* arr=(char*)base;
    char* ar;
    int i = 0;
    int j=0;
    for (i = 0; i < nel; i++) {
        ar=base+i*width;
        if (compare(arr, ar) < 0){
            arr = ar;
            j=i;
        }
    }
    
    
    return j;
}

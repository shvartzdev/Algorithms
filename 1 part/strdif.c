int strdiff(char *a, char *b)
{
    unsigned long minlen = 0;
    
    if (strlen(a) > strlen(b)) minlen = strlen(b); else minlen = strlen(a);
    
    int count = 0, i = 0, key =0;
    
    for (i = 0; i <= minlen; i++) {
        if (a[i] != b[i]) {
            key = 1;
            while ((a[i] % 2) == (b[i] % 2)) {
                a[i] = a[i]/2;
                b[i] = b[i]/2;
                count++;
            }
            break;
        }}
    if ((key == 0) && (strlen(a) == strlen(b))) return -1;
    else if ((key == 0) && (strlen(a) != strlen(b))) return (minlen*8 - 1);
    else return (i*8 + count);
    return 0;
}

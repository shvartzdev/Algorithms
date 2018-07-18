#include <stdlib.h>
#include <stdio.h>
#include "elem.h"

struct Elem *searchlist(struct Elem *list, int k)
{
    struct Elem *m;
    if (list == NULL) return NULL;
    if (((*list).tag == INTEGER) && ((*list).value.i == k)) return list;
    else if ((*list).tag == LIST) {
        
        m = searchlist((*list).value.list, k);
        if (m != NULL) return m;
        if ((*list).tail == NULL) return NULL;
        else return searchlist((*list).tail, k);
    }
    if ((*list).tail == NULL) return NULL;
    else return searchlist((*list).tail, k);
    return 0;
    
}

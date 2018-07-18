#include <stdio.h>
#include <stdlib.h>
//сортировка прямым выбором и быстрая сортировка
void swap (int i, int j, int *items);
void quicksort (int n, int *items);
void quicksortrec(int low, int high, int *items);
void selectsort (int n, int *items);

int main() {
    int n,m;
    scanf ("%d", &n);
    scanf("%d", &m);
    int a[n], i = 0;
    for (i = 0; i < n; i++) scanf("%d", &a[i]);
    int *p = a;
    if (n <= m) selectsort(n, p);
    else quicksort (n, p);
    for (i = 0; i < n; i++) printf("%d ", a[i]);
}

int partition (int low, int high, int *items){
    int i,j;
    i = j = low;
    while (j < high) {
        if (items[j] > items[high]) swap (j,high,items);
        i++;
        j++;
    }
    swap(i, high, items);
    return i;
}

void quicksort (int n, int *items){
    quicksortrec(0, n - 1, items);
}

void quicksortrec (int low, int high, int *items){
L:  if (low < high) {
        int q = 0;
        q = partition(low, high, items);
        quicksortrec(low, q-1, items);
    low = q+1;
    goto L;
    }
}

void selectsort (int n, int *items){
    int j = n - 1;
    while (j > 0) {
        int k = j;
        int i = j - 1;
        while (i >= 0) {
            if (items[k] < items[i]) {
                k = i;
                 i--;
            }
            swap(j,k,items);
        }
        j--;
    }
    
}

void swap (int i, int j, int *items)
{
    int t = items[i];
    items[i] = items[j];
    items[j] = t;
}

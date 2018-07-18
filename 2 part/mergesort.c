#include <stdio.h>
#include <stdlib.h>

void insertionsort (int *items, int count);
void Merge(int *A,int *L,int leftCount,int *R,int rightCount);
void MergeSort(int *A,int n);

int main() {
    //размер массива
    int n;
    scanf("%d", &n);
    int a[n], i = 0;
    
    for (i = 0; i < n; i++) scanf("%d", &a[i]);

    //указатель для передачи массива функции
    int *A = a;
    if (n <= 5) insertionsort (A, n);
    else MergeSort(A, n);
    
    for (i = 0; i < n; i++) printf("%d ", a[i]);
}
//алгоритм сортировки вставками
void insertionsort (int *items, int count){
    int elem = 0, loc = 0, i = 1;
    
    while (i < count) {
        elem = items[i];
        loc = i - 1;
        while ((loc >= 0) && (abs(items[loc]) > abs(elem))){
            items[loc + 1] = items[loc];
            loc--;
        }
        items[loc + 1] = elem;
        i++;
    }
}
void Merge(int *A,int *L,int leftCount,int *R,int rightCount) {
    
    int i,j,k;
    i = 0; j = 0; k =0;
    
    while(i<leftCount && j< rightCount) {
        if(abs(L[i])  <= abs(R[j])) A[k++] = L[i++];
        else A[k++] = R[j++];
    }
    while(i < leftCount) A[k++] = L[i++];
    while(j < rightCount) A[k++] = R[j++];
}

//деление массива на две примерно равные части
void MergeSort(int *A,int n) {
    int mid,i, *L, *R;
    if(n < 2) return;
    
    mid = n/2;
    
    L = (int*)malloc(mid*sizeof(int));
    R = (int*)malloc((n- mid)*sizeof(int));
    
    for(i = 0; i<mid; i++) L[i] = A[i];
    for(i = mid; i<n; i++) R[i-mid] = A[i];
    //сортировка каждой части
    MergeSort(L,mid);
    MergeSort(R,n-mid);
    //слияние отсортированных частей
    Merge(A,L,mid,R,n-mid);
    
    free(L);
    free(R);
}

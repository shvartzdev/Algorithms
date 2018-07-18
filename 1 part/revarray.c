#include <stdio.h> 
 
int array[] = { 
        1000000000, 
        2000000000, 
        3000000000, 
        4000000000, 
        5000000000 
}; 
 
void revarray(void *base, unsigned long nel, unsigned long width) 
{ 
  
	unsigned char *LastElems, *FirstElems;
	long long middle;
	unsigned long i = 0, j = 0;
	FirstElems = base;
	LastElems = FirstElems + (nel - 1)*width;
	nel = nel / 2; 
	
	for (i = 0; i < nel; i++){
		for (j = 0; j < width; j++){ 
				middle = *FirstElems;
				*FirstElems = *LastElems;
				*LastElems = middle;
				FirstElems +=1; 
				LastElems += 1;
			}
			LastElems -= 2*width; 
		} 
} 
 
void revarray(void*, unsigned long, unsigned long); 
 
int main(int argc, char **argv) 
{ 
        revarray(array, 5, sizeof(int)); 
 
        int i; 
        for (i = 0; i < 5; i++) { 
                printf("%d\n", array[i]); 
        } 
 
        return 0; 
}

#include <stdio.h>

int main()
{
        
      int a[8], b[8], el[8];
	int i=0,j=0,k=0,m=1, n=0;	

	for (i = 0; i < 8; i++) scanf ("%d", &a[i]); 
	for (j = 0; j < 8; j++) scanf ("%d", &b[j]); 
	for (k = 0; k < 8; k++) (el[k] = 0); 

	for (i = 0; i < 8; i++) { 	
		for (j = 0; j < 8; j++) {			
			if ((a[i] == b[j]) && (el[j] != 1)) {
						el[j] = 1; break;
				} 
		}
	}	
	for (k = 0; k < 8; k++) {
		if (el[k] == 0) m = 0; else n = 1;
		}
	if (m == 0) printf("no\n"); else if (n == 1) printf("yes\n");
	return 0;
}

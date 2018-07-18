#include <stdio.h>

int main()
{
        int m=0,n=0; 	
	scanf ("%d%d", &m, &n);
	
	int i=0,j=0, a[m][n];  
	for (i = 0; i < m; i++) {
		for (j = 0; j < n; j++) 
		scanf ("%d", &a[i][j]); 
		}

	int maximum[m],minimum[n], st = 0; 

	for (i = 0; i < m; i++) {
		for (j = 0; j < n; j++) {
			maximum[i] = a[i][0];
			minimum[j] = a[0][j];
		}
	}

	for (i = 0; i < m; i++)  	 
		for(j = 0; j < n; j++) {	
			st = a[i][j];
		if (st > maximum[i]) maximum[i] = st;
		if (st < minimum[j]) minimum[j] = st;	
		}

	int b =0;
	for (i = 0; i < m; i++) {
		for (j = 0; j < n; j++) {
		if (maximum[i] == minimum[j]) {
					b = 1;
					printf("%d %d \n", i,j); }
		}
	}

	if (b != 1) printf("none"); 
	return 0;
}

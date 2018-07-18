unsigned long peak(unsigned long nel, int (*less)(unsigned long i, unsigned long j))
{
  
	unsigned long long LeftBorder = 0, RightBorder = nel - 1; 
	unsigned long long middle = 0;

	while (LeftBorder < RightBorder) {
	    middle = LeftBorder/2 + RightBorder/2;
		if  (less (middle, middle + 1) == 1) LeftBorder = middle + 1;
		else if  (less(middle, middle - 1) == 1) RightBorder = middle - 1;
		else return middle;
	}

   }

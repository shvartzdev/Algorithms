
#include <stdio.h>

int main()
{
        long long FirstMn,SecondMn,Del; 
        scanf("%lld%lld%lld", &FirstMn, &SecondMn, &Del);
        

        long long MassivForS[65], Schet = 0;
        
        for (Schet = 0; SecondMn >= 1; Schet++) {
		MassivForS[Schet] = SecondMn % 2;
		SecondMn = SecondMn/2;
	}
	                

	long long i = 0, Pr = 0;
	for (i = Schet-1; i > 0; i--) {
		Pr = (((Pr + (FirstMn * MassivForS[i]) % Del) % Del) * 2) % Del;
		}
	Pr = (Pr + ((MassivForS[0] * FirstMn)% Del)) % Del;
	printf("%lld\n", Pr);
	return 0;
}

#include <stdio.h>
#define N 100

int main()
{
	long long unsigned sum, sum_of_squares;
	int i=1;
	for (i=1; i<N; ++i)
	{
		sum+=i;
		sum_of_squares+=(i*i);
	}
	 long long int diff = sum*sum - sum_of_squares;
    printf("\nAz elso %d szam osszegenek negyzete - Az elso %d negyzetszam osszege = %lld\n",N,N,diff);
    
}

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#define LIMIT 1000
#define LOGGING 0

int fract[LIMIT];
int remainders[LIMIT];

int get_reciprocal_cycle_length(int denominator, char need_log)
{
	int numerator = 1;
	int length = 0;
	
	if (need_log)
	  printf("%d : %d = %d.", numerator, denominator, numerator/denominator);
	
	int i = 0, j = 0, found = 0;
	while (numerator != 0 && length < LIMIT && !found)
	{
		numerator %= denominator;
		numerator *= 10;

		//store remainders and fracture digits	
		remainders[length] = numerator;
		fract[length] = numerator/denominator;
		
		//check for repeats
		for (j=0; j<length; ++j)
		{
			if (remainders[j] == numerator)
				found = 1;
		}		

		++length;
	}
	
	if (need_log)
	{
		//print fracture
		for (i=0; i<length; ++i)
		{
			printf("%d", fract[i]);
		}
		
		//print the remainders
		for (i=0; i<length; ++i)
		{
			printf("\n");
			for (j=0; j<i; ++j)
				printf(" ");
			printf("%d", remainders[i]);
		}
		printf("\n\n");	
	}

	return length;
}

int main(int argc, char ** argv)
{	
	int num = 1, length = 1, max_length = 1, max_num = 1;
	
	for (num = 1; num <= LIMIT; ++num)
	{
		length = get_reciprocal_cycle_length(num, LOGGING);
		
		if (max_length < length)
		{
			max_num = num;
			max_length = length;
		}
	}
	
	printf("Max n=%d Max lenght=%d\n", max_num, max_length);
	return 0;
}
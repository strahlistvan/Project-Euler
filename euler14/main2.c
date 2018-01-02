#include <stdio.h>
#include <stdlib.h>
#define LIMIT 1000000

long long int cache[LIMIT+1]={0};
long long int Collatz(long long int);

int main()
{
    long long int i, max_value=0, max_number=0;
    
    /** LIMIT alatti leghosszabb Collatz-sorozat hossza */
    for (i=1; i<LIMIT; ++i)
    {
        if (Collatz(i)>max_value)
        {
            max_value=Collatz(i);
            max_number = i;
        }
    }
    printf("%llu adja leghosszabb, %llu hosszu sorozatot.\n",max_number, max_value);
    return 0;
}

/** Visszaadja a megadott szamtol indulo Collatz-sorozat hosszat */
long long int Collatz(long long int number)
{
    long long int length=1, start_number = number;
    while (number!=1)
    {
        if (number&1)
            number=3*number+1;
        else 
        	 number>>=1;
        	 
        if (number<LIMIT && cache[number]!=0)
    	  {
    	  	  cache[start_number] = cache[number]+length;
 			  return cache[start_number];
    	  }
    	  ++length;   	  
    }
  cache[start_number] = length;
  return length;
}

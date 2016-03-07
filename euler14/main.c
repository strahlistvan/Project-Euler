#include <stdio.h>
#include <stdlib.h>
#define LIMIT 1000000

long long int Collatz(long long int);

int main()
{
    long long int i, max_value=0, max_number=0;
    for (i=1; i<LIMIT; ++i)
    {
        if (Collatz(i)>max_value)
        {
            max_value=Collatz(i);
            max_number = i;
            printf("%d az eddigi leghosszabb %d",max_number);
            printf("%d\n ertekkel\n",max_value);
        }
    }

    return 0;
}

long long int Collatz(long long int number)
{
    long long int length=0;
    while (number!=1)
    {
        if (number&1)
            number=3*number+1;
        else number>>=1;
        //printf("%d ",number);
        ++length;
    }
  return length;
}

#include <stdio.h>
#include <stdlib.h>
#define N 1000

int main()
{
    int i=1;
    int sum=0;
    for (i=1; i<N; ++i)
    {
        if (!(i%3) || !(i%5))
            sum+=i;
    }
    printf("\n%d alatti 3-mal es 5-tel oszthatok osszege: %d\n",N,sum);
    return 0;
}

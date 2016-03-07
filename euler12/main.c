#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#define N 500

int main()
{
    int divisors = 0;
    unsigned long long int i, num=1, tri_num=0;
    while (divisors<N)
    {
        divisors = 0;
        for (i=1; i<=sqrt(tri_num); ++i)
        {
            if (tri_num%i==0)
                divisors+=2;
        }
        if (divisors>N) break;
        tri_num+=num;
        //printf("%d\n",divisors);
        ++num;
    }
    printf("%d\n", tri_num);
    return 0;
}

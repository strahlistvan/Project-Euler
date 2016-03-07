#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <limits.h>
#define N 1000000
char is_prime(unsigned long long);

int main()
{
    unsigned long long i,j;
    unsigned long long sum=0;
    char * not_prime = (char*) calloc(N,sizeof(char));
    for (i=2; i<N; ++i)
    {
        if (!not_prime[i] && is_prime(i))
        {
            for (j=i; j<N; j+=i)
                not_prime[j]=1;
            sum+=i;
        }
    }

    printf("\nA %d alatti primek osszege: %d\n",N,sum);
    return 0;
}

char is_prime(unsigned long long number)
{
    if (number==0 || number==1) return 0;
    if (number==2 || number==3) return 1;
    unsigned long long i;
    unsigned long long root = sqrt(number)+1;
    for (i=2; i<root; ++i)
    {
        if (number%i==0)
        {
            return 0;
        }
    }
    return 1;
}

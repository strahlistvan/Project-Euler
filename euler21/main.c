#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#define N 10000

int properDivisorSum(int number);
int slowMethod();
char isPrime(int number);

int main()
{

    int sum = slowMethod();
    printf("eredmeny: %d", sum);
    return 0;
}

char isPrime(int number)
{
    int index=0;
    for (index=2; index < sqrt(number); ++index)
    {
        if (number%index==0)
            return 0;
    }
    return 1;
}

/** Eredeti 2 ciklussal --> nagyon lassu... */
int slowMethod()
{
    int i=0, j=0;
    int sum = 0;
    for (i=2; i<=N; ++i)
    {
        for (j=i+1; j<=N; ++j)
        {
            int divSum1 = properDivisorsSum(i);
            int divSum2 = properDivisorsSum(j);
            //csak hogy latszon valami:
         //   if (i%100==0 && j==i+1)
         //    printf("%d ",i);
            if (i==divSum2 && j==divSum1)
            {
                printf("\n%d <-> %d\n", divSum1, divSum2);
                sum += i;
                sum += j;
            }
        }
    }
    return sum;
}

/** Minden szamot csak egyszer nez: jobb megoldas*/
int fasterMethod()
{
    int i, sum = 0;
    for (i=2; i<=N; ++i)
    {
            int divSum1 = properDivisorsSum(i);
            //Megnezi, hogy a kapott szam (i osztoinak szama) osztoinak szama vajon i ?
            if (divSum1<N && divSum1>i)
            {
                int divSum2 = properDivisorsSum(divSum1);
                if (i==divSum2)
                {
                    printf("\n%d <-> %d\n", divSum1, divSum2);
                    sum += i;
                    sum += divSum1;
                }
            }

    }
    return sum;
}

/** Visszaadja a szam valodi osztoinak osszeget. */
int properDivisorsSum(int number)
{
    int index=-1, sum=1;
    int sqrtNumber = sqrt(number);
    //Negyzetszamot csak egyszer osszegez:
    if (number == sqrtNumber*sqrtNumber)
    {
        sum+=sqrtNumber;
        --sqrtNumber;
    }
    //Megkeresi a valodi osztoit (negyzetgyokig: felsot+alsot)
    for (index=2; index<=sqrtNumber; ++index)
    {
        if (number%index==0)
        {
            sum+= index + (number/index);
        }
    }
    return sum;
}

/** Euler-fele azonossag: nem talalja meg az osszeset. */
int badMethod()
{
    int n=1;
    int a=0, b=0;
    //minden n-re:
    while (a<N || b<N)
    {
        int k=0, f=0;
        // f = 2^k + 1 alaku szorzoszam...
        for (k=1; k<n; ++k)
        {
            int f = (1<<k)+1;

            int x = f*(1<<n)-1;
            int y = f*(1<<(n-1))-1;
            int z = f*f*(1<<(2*n-1))-1;
            //Ha x,y,z primek, akkor 'a' es 'b' baratsagosak
            if (isPrime(x) && isPrime(y) && isPrime(z))
            {
                a = (1<<n)*x*y;
                b = (1<<n)*z;
                printf("a=%d b=%d\n", a, b);
            }
        }
        ++n;
    }
}

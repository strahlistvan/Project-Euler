#include <stdio.h>
#include <stdlib.h>
#define LIMIT 1000

char isPrime(int number);

/** N^2 + aN + b formulahoz keres egyutthatot, amibol a legtobb primszam generalhato N=0,1,2... helyettesites eseten */
int main()
{
    int a,b;
    int max_n = 0, max_a = 0, max_b = 0;
    for (a=-LIMIT; a<LIMIT; ++a)
    {
         for (b=-LIMIT; b<LIMIT; ++b)
         {
            int n=0;
            int formula = n*n+a*n+b;
            while( isPrime(abs(formula)) )
            {
                ++n;
                 formula = n*n+a*n+b;
            }
            //Maximum kivalasztas
            if (n > max_n)
            {
                max_n = n;
                max_a = a;
                max_b = b;
            }
          //  printf("\n\n Jelenlegi legnagyobb n=%d\n",max_n);
         }
    }
    printf("a=%d b=%d n=%d\n", max_a, max_b, max_n);
    printf("Eredmeny: %d\n", max_a*max_b);
    return 0;
}

/** Eldonti, hogy az adott szam prim-e */
char isPrime(int number)
{
    if (number==1 || number==0)
        return 0;
    int index=0;
    for (index=2; index < sqrt(number)+1; ++index)
    {
        if (number%index==0)
            return 0;
    }
    return 1;
}

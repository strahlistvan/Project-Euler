#include <stdio.h>
#include <stdlib.h>
#include <math.h>

char is_prime(int number);

/**Feladat megoldasa a spiral eloallitasa es tarolasa nelkul.
 Sprial gyuruinek 4 sarka: (2n+1)^2, (2n+1)^2-2n, (2n+1)^2-4n, (2n+1)^2-6n alakuak, es a spiralgyuru merete 2n+1 **/
int main(int argc, char ** argv)
{
    int n, SIZE, prime_count = 0;
    double rate = 1;

    for (n=1; rate > 0.1; ++n)
    {
        SIZE = 2*n+1; //'gyuru' merete
        int k, number=SIZE*SIZE;
        //gyuru harom(!) oldalanak vizsgalata (a bal also negyzetszam -> nem prim)
        for (k=0; k<3; ++k)
        {
            number-=2*n;
            if (is_prime(number))
                ++prime_count;
        }
        rate = (double)prime_count / (2*(SIZE-1));
    }
    printf("%d meretu spiral eseten a primek aranya: %f\n", SIZE, rate);
    return 0;
}

/** Primteszt fuggveny */
char is_prime(int number)
{
    if (number==2)
        return 1;
    if (number<2 || number%2==0)
        return 0;

    int i;
    for (i=3; i<=sqrt(number); i+=2)
    {
        if (number%i==0)
            return 0;
    }
    return 1;
}

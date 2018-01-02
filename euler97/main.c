#include <stdio.h>
#include <stdlib.h>
//Mersenne-prime: 28433×2^7830457+1 (last 10 digits)

int main()
{
    int exp = 7830457, base = 2;
    unsigned long long number = 1, modulo = 10000000000;

    while (exp > 0)
    {
        number*=base;
        --exp;
        number%=modulo;
    }

    number = (28433*number+1) % modulo;
    printf("A szam: %llu\n", number);
    return 0;
}

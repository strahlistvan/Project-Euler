#include <stdio.h>
#include <stdlib.h>

int Euler_phi(int number);

int main()
{
    int i;
    for (i=1; i<100000; ++i)
       Euler_phi(i);

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

int gcd(int a, int b)
{
    while (a!=b)
    {
        if ( !(a&1) && !(b&1))
        {
            a/=2;
            b/=2;
        }

        if (a>b)
            a-=b;
        else
            b-=a;
    }
    return b;
}

/** Euler-phi fuggveny primfelbontassal */
int Euler_phi(int number)
{
   int prime_divider = 2;
   double prod = number;
   while (number > 1)
	{
		if (number%prime_divider == 0)
		{
			while (number%prime_divider==0)
                number/=prime_divider;
			prod*=(1 - 1/((double)prime_divider) );
		}
		else
		{
			++prime_divider;
		}
	}
	return prod;
}

/** Euler-fi fuggveny (hagyomanyos valtozat) */
/*int Euler_phi(int number)
{
    if (is_prime(number))
        return number-1;

    int i, rel_primes = 0;
    for (i=1; i<number; ++i)
    {
        if (gcd(number, i)==1)
            ++rel_primes;
    }
    return rel_primes;
}
*/

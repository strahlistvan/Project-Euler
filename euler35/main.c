#include <stdio.h>
#include <stdlib.h>
#define LIMIT 1000000

char isAllRotationPrime(int number);

int main(int argc, char ** argv)
{
    int i, count = 0;
    for (i=0; i<LIMIT; ++i)
    {
        if (isAllRotationPrime(i))
            ++count;
    }
    printf("%d", count);
    return 0;
}

int getLowerPower10(int number)
{
    int back = 1;
    while (back <= number/10)
    {
        back*=10;
    }
   return back;
}

char isPrime(int number)
{
    if (number == 2)
        return 1;
    if (!(number&1) || number<2)
        return 0;

    int i;
    for (i=3; i<number-1; i+=2)
    {
        if (number%i == 0)
            return 0;
    }
   return 1;
}

char isAllRotationPrime(int number)
{
    int n = number;
    int power10 = getLowerPower10(number);

    do
    {
        int firstDigit = (n%(10*power10)) / power10;
        int innerDigits = (n - (firstDigit*power10)) / 10;
        int lastDigit = n%10;
        n = (lastDigit*power10) + (firstDigit*(power10/10)) + innerDigits;

        if (!isPrime(n))
            return 0;
    }
    while (n!=number);
    return 1;
}

/*#include <stdio.h>
#include <math.h>

char isSumOfDigitPowers(int number, int exp);

int main(int argc, char ** argv)
{
    //Hatar keresese
    int exp=1, c=pow(9, 5);
    while ( pow(10, exp-1) < c*exp)
        ++exp;

    int i, sum=0, LIMIT = LIMIT = c*exp;;
    //Minden szam tesztelese a hatarig
    for (i=2; i<=LIMIT; ++i)
    {
        if (isSumOfDigitPowers(i, 5))
            sum+=i;
    }
    printf("Az eredmeny: %d", sum);
    return 0;
}

char isSumOfDigitPowers(int number, int exp)
{
    int n = number;
    int sum = 0;
    while (sum<=number && n>0)
    {
       sum += pow(n%10, exp);
       n/=10;
    }
    if (sum == number)
        return 1;
    return 0;
}
*/

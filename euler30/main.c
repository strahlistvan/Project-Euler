#include <stdio.h>
#include <math.h>

char isSumOfDigit5thPowers(int number);

int main(int argc, char ** argv)
{
    //Hatar keresese
    int exp=1, c=pow(9, 5);
    while ( pow(10, exp-1) < c*exp)
        ++exp;

    int i, sum=0, LIMIT = c*exp;
    //Minden szam tesztelese a hatarig
    for (i=2; i<=LIMIT; ++i)
    {
        if (isSumOfDigit5thPowers(i))
            sum+=i;
    }
    printf("Az eredmeny: %d", sum);
    return 0;
}

int pow5th(int base)
{
    switch (base)
    {
        case 1:
            return 1;
        case 2:
            return 32;
        case 3:
            return 243;
        case 4:
            return 1024;
        case 5:
            return 3125;
        case 6:
            return 7776;
        case 7:
            return 16807;
        case 8:
            return 32768;
        case 9:
            return 59049;
        default:
            return 0;
    }
}

char isSumOfDigit5thPowers(int number)
{
    int n = number;
    int sum = 0;
    while (sum<=number && n>0)
    {
       sum += pow(n%10, 5);
       n/=10;
    }
    if (sum == number)
        return 1;
    return 0;
}

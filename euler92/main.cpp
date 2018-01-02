#include <iostream>
using namespace std;

//is unhappy number? :'(
bool isChainEnds89(int number);

int main()
{
    const int LIMIT = 10000000;
    int count = 0;
    for (int i=2; i<LIMIT; ++i)
    {
        if (isChainEnds89(i))
            ++count;
    }
    cout<<count<<" number chains ends 89 below "<<LIMIT<<endl;
    return 0;
}

/** Get the sum of the square of the given number's digits */
int getSumOfDigitSquare(int num)
{
    int sum = 0;
    while (num > 0)
    {
        sum+=(num%10)*(num%10);
        num/=10;
    }
    return sum;
}

/** Generates number chain, start with the given number */
bool isChainEnds89(int number)
{
    while (number!=89 && number!=1)
    {
       // cout<<number<<"->";
        number = getSumOfDigitSquare(number);
    }
    if (number==89)
        return true;
    return false;
}

#include <iostream>
#include <cmath>
#include <ctime>
using namespace std;

//is unhappy number? :'(
bool isChainEnds89(int number);
int getSumOfDigitSquare(int num);

int getUnhappyCount(int limit);
int getUnhappyCountCache(int limit);

int main(int argc, char ** argv)
{
    const int LIMIT = 10000000;

    time_t t = time(NULL);
    cout<<getUnhappyCount(LIMIT)<<" number chains ends 89 below "<<LIMIT<<endl;
    cout<<"Running time [NO CACHE] : " << (time(NULL) - t) <<" seconds "<< endl;
    t = time(NULL);
    cout<<getUnhappyCountCache(LIMIT)<<" number chains ends 89 below "<<LIMIT<<endl;
    cout<<"Running time [CACHE] : " << (time(NULL) - t) <<" seconds "<< endl;

    cout<<"\n1009 is a really "<<((isChainEnds89(1009))?"un":"")<<"happy number"<<endl;

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

    return (number==89);
}

int getUnhappyCount(int limit)
{
    int count = 0;
    for (int i=2; i<limit; ++i)
    {
        if (isChainEnds89(i))
            ++count;
    }
    return count;
}

int getUnhappyCountCache(int limit)
{
    const int CACHE_SIZE = 81*log10(limit)+1;
    bool cache[CACHE_SIZE] = {false};

    int count = 0;
    for (int i=2; i<CACHE_SIZE; ++i)
    {
        if (isChainEnds89(i))
        {
            ++count;
            cache[i] = true;
        }
    }
    for (int i=CACHE_SIZE; i<limit; ++i)
    {
        if (cache[getSumOfDigitSquare(i)])
            ++count;
    }
    return count;
}

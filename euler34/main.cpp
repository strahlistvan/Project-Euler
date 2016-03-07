#include <iostream>
#include <climits>
using namespace std;

unsigned factorial(unsigned n);
bool isCuriousNumber(unsigned n);

int main()
{
    for (unsigned i=0; !bounded && i<UINT_MAX; ++i)
    {
        if (isCuriousNumber(i))
            cout<<i<<endl;
    }
    return 0;
}

unsigned factorial(unsigned n)
{
    if (n==0 || n==1)
        return 1;
    else
        return  n*factorial(n-1);
}

bool isCuriousNumber(unsigned n)
{
    unsigned sumOfFactorials = 0, number = n;
    while (n>0)
    {
        sumOfFactorials += factorial(n%10);
        n/=10;
    }
    return (sumOfFactorials==number);
}

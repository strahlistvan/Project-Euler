#include <iostream>
#include "bignum.h"
using namespace std;

int main()
{
    const int LIMIT = 1000;
    BigInteger last1("1");
    BigInteger last2("1");
    BigInteger current("2");
    int index;
    for (index=2; current.getNumbers().size()<LIMIT; ++index)
    {
        current = last1+last2;
        last2 = last1;
        last1 = current;
    }
    cout<<current<<endl;
    cout<<index<<". Fibonacci szam az elso "<<LIMIT<<" szamjegyu"<<endl;
    return 0;
}

#include <iostream>
#include <cmath>
#include "bignum.h"
using namespace std;

int main()
{
    const int LIMIT = 1000;
    BigInteger sum = 0;
    for (int i=1; i<=LIMIT; ++i)
    {
        BigInteger bi(i);
        BigInteger power = bigIntPower(bi, bi);
        sum = sum + power;
    }
    int lenght = sum.getNumbers().size();
    cout<<"A szam hossza: "<<lenght<<endl;
    cout<<"Utolso 10 szamjegy: "<<sum.getNumbers().substr(lenght-10, 10)<<endl;


    return 0;
}


#include <iostream>
#include "bignum.h"
using namespace std;

int main()
{
    const int POWER = 1000, BASE = 2;
    int currentPower = POWER;
    BigInteger result(BASE);

    while (currentPower>1)
    {
        result*=BASE;
        --currentPower;
    }
    cout<<result<<endl;
    int sum = 0;
    for (int i=0; i<result.getNumbers().size(); ++i)
        sum+=result.getNumbers()[i]-'0';
    cout<<"A szamjegyek osszege: "<<sum<<endl;
    return 0;
}

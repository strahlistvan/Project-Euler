#include <iostream>
#include "bignum.h"
using namespace std;

int main()
{
    const int N = 100;
    BigInteger result("1");
    for (int i=1; i<=N; ++i)
    {
        result*=i;
    }

    cout<<result<<endl;
    int sum = 0;
    for (int i=0; i<result.getNumbers().size(); ++i)
        sum+=result.getNumbers()[i]-'0';
    cout<<"A szamjegyek osszege: "<<sum<<endl;
    return 0;
}

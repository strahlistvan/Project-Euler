#include <iostream>
#include <cmath>
#include <vector>
using namespace std;

int main()
{
   const int LIMIT = 2000000;

   vector<bool> isPrime(LIMIT+1, true);
   isPrime[0] = isPrime[1] = false;
    for (int n=2; n<sqrt(isPrime.size()); ++n)
    {
        if (isPrime[n]) //Ha a megadott szam prim
        {
            //Kihuzni a tobbszoroseit
            for (int m=n*n; m<isPrime.size(); m+=n)
       		{
                isPrime[m] = false;
            }
        }
    }

    unsigned long long sum = 0;
    for (int i=2; i<isPrime.size(); ++i)
    {
        if (isPrime[i])
            sum+=i;
    }
    cout<<"Az osszeg: "<<sum<<endl;
    return 0;
}

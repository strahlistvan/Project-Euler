#include <iostream>
#include <cmath>
using namespace std;
typedef unsigned long long uint64;
bool isTruncPrime(uint64 num);
bool isTruncPrimeFromLeft(uint64 num);

int main()
{
    int count = 0;
    uint64 sum = 0;
    for (uint64 n=11; count!=11; ++n)
    {
        if (isTruncPrime(n) && isTruncPrimeFromLeft(n) )
        {
            cout<<n<<endl;
            sum+=n;
            ++count;
        }
    }
    cout<<"SUM: "<<sum<<endl;
    return 0;
}



bool isPrime(uint64 num)
{
	if (num==2)
		return true;
	if (num%2==0 || num<2)
		return false;

	for (uint64 i=3; i<=sqrt(num); i+=2)
	{
		if (num%i==0)
			return false;
	}
	return true;
}

uint64 revNumber(uint64 num)
{
    uint64 revNum = 0;
    while(num > 0)
    {
        revNum*=10;
        revNum += num%10;
        num/=10;
    }
    return revNum;
}

bool isTruncPrime(uint64 num)
{
    uint64 back_num = 0, mult = 1;
    while (num > 0)
    {
        back_num += mult*(num%10);
        if (!isPrime(back_num))
            return false;
        mult*=10;
        num/=10;
    }
    return true;
}

bool isTruncPrimeFromLeft(uint64 num)
{
    uint64 divider = round(pow(10, (uint64)log10(num)));
    uint64 front_num = 0;
    while (num > 0)
    {
        front_num += (num/divider);
        if (!isPrime(front_num))
            return false;
        front_num*=10;
        num = num%divider;
        divider/=10;
    }
   return true;
}

#include <iostream>
#include <cmath>
#include <set>
#include <algorithm>
using namespace std;

typedef unsigned long long uint64;
bool isPrime(uint64 num);
set<uint64> getPrimeFactor(uint64 number);

int main()
{
    bool found = false;
    for (uint64 i=3; !found; ++i)
    {
        if (!isPrime(i) && !isPrime(i+1) && !isPrime(i+2) && !isPrime(i+3))
        {
            set<uint64> s1 = getPrimeFactor(i);
            set<uint64> s2 = getPrimeFactor(i+1);
            set<uint64> s3 = getPrimeFactor(i+2);
            set<uint64> s4 = getPrimeFactor(i+3);

            if (s1.size()==4 && s2.size()==4 && s3.size()==4 && s4.size()==4)
            {
                set<uint64> intersect;
                set_intersection(s1.begin(),s1.end(),s2.begin(),s2.end(),
                              inserter(intersect, intersect.begin()) );

                set_intersection(s3.begin(), s3.end(), intersect.begin(), intersect.end(), inserter(intersect, intersect.begin()) );

                set_intersection(s4.begin(), s4.end(), intersect.begin(), intersect.end(), inserter(intersect, intersect.begin()) );
                if (intersect.empty())
                {
                    cout<<i<<"-"<<(i+1)<<"-"<<(i+2)<<"-"<<(i+3)<<endl;
                    found = true;
                }
            }
        }
    }
    return 0;
}

bool isPrime(uint64 num)
{
	if (num==2)
		return true;
	if (num%2==0 || num<2)
		return false;

	for (int i=3; i<=sqrt(num); i+=2)
	{
		if (num%i==0)
			return false;
	}
	return true;
}

set<uint64> getPrimeFactor(uint64 number)
{
    uint64 divider = 2;
    set<uint64> primeFactor;
	while (number > 1)
	{
		if (number%divider == 0)
		{
		    primeFactor.insert(divider);
			number/=divider;
        }
		else
		{
			++divider;
		}
	}
	return primeFactor;
}

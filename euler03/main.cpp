#include <iostream>
#include <vector>
#include <cmath>
#define NUM 600851475143
using namespace std;

typedef vector<unsigned long long> vec;
vec find_primes(unsigned long long LIMIT);
vec prime_factor(unsigned long long number);
bool isPrime(unsigned long long num);
unsigned long long nextPrime(unsigned long long num);

int main(int argc, char ** argv)
{
	unsigned long long divider = 2, biggestFactor = 2;
	unsigned long long number = 600851475143;
	while (number > 1)
	{
		if (number%divider == 0)
		{
			number/=divider;
			biggestFactor = divider;
		}
		else 
		{
			divider = nextPrime(divider);
		}
	}
	cout<<"A legnagyobb primfaktor: "<<biggestFactor<<endl;
	return 0;
}

/*int main(int argc, char ** argv)
{
	 unsigned long long result = 0;
	 bool found = false;
	 const unsigned long long NUM = 600851475143;
	 unsigned long long start = NUM&1? NUM-2: NUM-1;
	 for (unsigned long long i=start; !found && i>0; i-=2)
	 {
	 	 if (NUM%i==0 && isPrime(i))
	 	 {
	 	 	result = i;
	 	 	found = true;
	 	 }
	 } 
	 cout<<result<<endl;
    return 0;
} */

unsigned long long nextPrime(unsigned long long num)
{
	unsigned long long i;
	for (i=num+1; !isPrime(i); ++i);
	return i;
}

bool isPrime(unsigned long long num)
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

/** Eratoszthenesz szitaja LIMIT alatt */
vec find_primes(unsigned long long LIMIT)
{
    vector<bool> isPrime(LIMIT, true);
    isPrime[0] = false;
    
    vec primes_back; //visszateresi vektor
    for (unsigned long long i=1; i<isPrime.size(); ++i)
    {
        if (isPrime[i]) //Ha a megadott szam prim
        {
            primes_back.push_back(i+1);
            //Kihuzni a tobbszoroseit
            for (unsigned long long j=i; j<isPrime.size(); j+=(i+1))
       		{
                isPrime[j] = false;
            }
        }
    }
    return primes_back; 
}

/** A szam primtenyezos felbontasa */
vec prime_factor(unsigned long long number)
{
	 vec primes = find_primes(number);
    unsigned long long primeIndex = 0;
    vec factor_back;
    while (number>1)
    {
        unsigned long long p = primes[primeIndex];
        if (number%p == 0)
        {
            factor_back.push_back(p);
            number/=p;
        }
        else
            ++primeIndex;
    }
    return factor_back; 
}
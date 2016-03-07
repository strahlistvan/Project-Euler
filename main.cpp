#include <iostream>
#include <vector>
#include <cmath>
#define NUM 600851475143
using namespace std;

typedef vector<long long> vec;
vec find_primes(long long LIMIT);
vec prime_factor(long long number);


int main(int argc, char ** argv)
{
	 vec factor = prime_factor(NUM);
	 cout<<NUM<<" primfelbontasa: ";
	 for (int i=0; i<factor.size(); ++i)
	 	cout<<factor[i]<<',';
	 cout<<endl;
    return 0;
}

/** Eratoszthenesz szitaja LIMIT alatt */
vec find_primes(long long LIMIT)
{
    vector<bool> isPrime(LIMIT, true);
    isPrime[0] = false;
    
    vec primes_back; //visszateresi vektor
    for (long long i=1; i<isPrime.size(); ++i)
    {
        if (isPrime[i]) //Ha a megadott szam prim
        {
            primes_back.push_back(i+1);
            //Kihuzni a tobbszoroseit
            for (long long j=i; j<isPrime.size(); j+=(i+1))
       		{
                isPrime[j] = false;
            }
        }
    }
    return primes_back; 
}

/** A szam primtenyezos felbontasa */
vec prime_factor(long long number)
{
	 int limit = sqrt(number)+1;
	 vec primes = find_primes(limit);
	 
    long long primeIndex = 0;
    vec factor_back;
    while (number>1)
    {
        long long p = primes[primeIndex];
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

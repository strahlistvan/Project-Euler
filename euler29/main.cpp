#include <iostream>
#include <vector>
#include <algorithm>
#include <set>
using namespace std;

typedef vector<int> vec;
const int LIMIT = 100;
vec primes;

vec find_primes();
vec prime_factor(int number);
vec power_with_primes(vec base_in_factor, int exp);

int main(int argc, char ** argv)
{
    primes = find_primes();
    vec factors[LIMIT+1];
    for (int i=2; i<=LIMIT; ++i)
        factors[i] = prime_factor(i);

    set<vec> differents;
    for (int a=2; a<=LIMIT; ++a)
    {
        for (int b=2; b<=LIMIT; ++b)
        {
            vec res = power_with_primes(factors[a], b);
            differents.insert(res);
        }
    }
    cout<<"Az eredmeny: "<<differents.size()<<endl;
    return 0;
}

/** Eratoszthenesz szitaja */
vec find_primes()
{
    bool isNotPrime[LIMIT] = {0} ;
    isNotPrime[0] = false;
    vec primes_back; //visszateresi vektor

    for (int i=1; i<LIMIT; ++i)
    {
        if (!isNotPrime[i]) //Ha a megadott szam prim
        {
            primes_back.push_back(i+1);
            //Kihuzni a tobbszoroseit
            for (int j=i; j<LIMIT; j+=(i+1))
                isNotPrime[j] = true;
        }
    }
    return primes_back;
}

/** A szam primtenyezos felbontasa */
vec prime_factor(int number)
{
    int primeIndex = 0;
    vec factor_back;
    while (number>1)
    {
        int p = primes[primeIndex];
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

/** Primtenyezos reprezentacioval torteno hatvanyozas */
vec power_with_primes(vec base_in_factor, int exp)
{
    if (exp < 1) //Hibakezeles
        return vec();

    //kitevoszor beszurja a vegere sajat magat:
    vec insertVec = base_in_factor;
    for (int n=1; n<exp; ++n)
    {
        vec::iterator end_it = base_in_factor.end();
        base_in_factor.insert(end_it, insertVec.begin(), insertVec.end());
    }
    sort(base_in_factor.begin(), base_in_factor.end()); //rendezes!
    return base_in_factor;
}

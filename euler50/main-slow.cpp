#include <iostream>
#include <vector>

using namespace std;
typedef vector<int> vec;
const int LIMIT = 1000;
vector<bool> is_prime(LIMIT+1, true); //globalis vektor eratosztheneszhez+primteszthez
vec find_primes(int LIMIT);

int main()
{
    vec primes =find_primes(LIMIT);

    int max_sum = 0, max_sum_count = 0;
    for (int terms=2; terms<primes.size(); ++terms)
    {
        for (int index=0; index<primes.size()-terms; ++index)
        {
            int sum = 0, sum_count = 0;
            for (int j=0; sum<LIMIT && j<terms; ++j)
            {
                sum+=primes[index+j];
                ++sum_count;
            }
            if (sum<LIMIT && is_prime[sum] && sum_count > max_sum_count)
            {
                max_sum = sum;
                max_sum_count = sum_count;
            }
        }
    }
    cout<<"Max osszeg: "<<max_sum<<"\nEnnyi tagbol all: "<<max_sum_count<<endl;
    return 0;
}

/** Eratoszthenesz szitaja  */
vec find_primes(int LIMIT)
{
    is_prime[0] = is_prime[1] = false;
    vec primes_back; //visszateresi vektor
    for (int i=2; i<is_prime.size(); ++i)
    {
        if (is_prime[i]) //Ha a megadott szam prim
        {
            primes_back.push_back(i);
            //Kihuzni a tobbszoroseit
            for (int j=2*i; j<is_prime.size(); j+=i)
       		{
                is_prime[j] = false;
            }
        }
    }
    return primes_back;
}

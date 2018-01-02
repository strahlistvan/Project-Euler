#include <iostream>
#include <cstdlib>
#include <sstream>
#include <vector>
#include <algorithm>
using namespace std;

const int LIMIT = 10000;
vector<bool> is_prime(LIMIT+1, true); //globalis vektor eratosztheneszhez+primteszthez
vector<int> find_primes(int LIMIT);
vector<int> getPremutations(int num);

int main()
{
    vector<int> primes = find_primes(LIMIT);
    for (int i=0; i<primes.size(); ++i)
    {
            if (primes[i] > 999)
            {
                vector<int> perms = getPremutations(primes[i]);
                //Ha legalabb 3 permutacioja van:
                if (perms.size() >= 3)
                {
                    int curr_diff = 0, prev_diff = 0;
                    for (int j=0; j<perms.size()-1; ++j)
                    {
                        curr_diff = perms[j]-perms[j+1];
                        if (curr_diff==prev_diff)
                        {
                            cout<<"Megvannak: "<<perms[j-1]<<perms[j]<<perms[j+1]<<endl;
                            //return 0;
                        }
                        prev_diff = curr_diff;
                    }
                }
            }
    }

    return 0;
}

string num2string(int num)
{
   stringstream ss;
   ss<<num;
   return ss.str();
}

vector<int> getPremutations(int num)
{
    string str = num2string(num);
    bool hasMorePerm = true;
    vector<int> perms;
    //Amig van permutacio:
    while(hasMorePerm)
    {
        //Megkeresi a string kovetkezo permutaticojat:
        hasMorePerm = next_permutation(str.begin(), str.end());
        int n = atoi(str.c_str());
        perms.push_back(n);
    }
    sort(perms.rbegin(), perms.rend());
    return perms;
}

/** Eratoszthenesz szitaja  */
vector<int> find_primes(int LIMIT)
{
    is_prime[0] = is_prime[1] = false;
    vector<int> primes_back; //visszateresi vektor
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

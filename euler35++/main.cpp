#include <iostream>
#include <cstdlib>
#include <sstream>
#include <vector>
using namespace std;

const int LIMIT = 1000000;
bool isNotPrime[LIMIT+1] ={};
vector<int> primes;

void eratosthenes();
bool isAllRotationPrime(int number);

int main(int argc, char ** argv)
{
    eratosthenes();
    int count = 0;
    for (int i=0; i<primes.size(); ++i)
    {
        if (isAllRotationPrime(primes[i]))
            ++count;
    }
    cout<<"Eredmeny: "<<count<<endl;
    return 0;
}

void eratosthenes()
{
  isNotPrime[0] = isNotPrime[1] = true;
  for (int i=2; i<LIMIT+1; ++i)
  {
      if (!isNotPrime[i])
      {
          primes.push_back(i);
          for (int j=2*i; j<LIMIT+1; j+=i)
              isNotPrime[j] = true;
      }
  }
}

bool isAllRotationPrime(int number)
{
    stringstream ss;
    ss<<number;
    string numStr = ss.str();
    int n = atoi(numStr.c_str());
    do
    {
        numStr = numStr[numStr.size()-1] + numStr.substr(0, numStr.size()-1);
        n = atoi(numStr.c_str());
        //cout<<n<<endl;
        if (isNotPrime[n])
            return 0;
    }
    while (n!=number);
    return 1;
}

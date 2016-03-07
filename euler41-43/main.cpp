#include <iostream>
#include <cstdlib>
#include <algorithm>
#include <iomanip>
using namespace std;


bool isPrime(long long number);
bool isOK(string num_str);
void euler41();

/** Szamok osszes permutacioja (pandigital) */
int main()
{
    string num_str = "9876543210";
    bool morePerm = true;
    double sum = 0.0;
     while (morePerm)
    {
        if (isOK(num_str))
        {
            cout<<num_str<<" megfelelo"<<endl;
            if (sum<0) cout<<"Tulcsordult"<<endl;
            sum+=atof(num_str.c_str());
        }
        morePerm =  prev_permutation(num_str.begin(), num_str.end());
    }
    cout.precision(20);
    cout<<setw(20)<<sum<<endl;

}


void euler41()
{
    string num_str = "987654321";
    long long number = 0L;
    bool prime = false, morePerm = true;
     while (!prime && morePerm)
    {
         number = atol(num_str.c_str());
         prime = isPrime(number);
         morePerm =  prev_permutation(num_str.begin(), num_str.end());
         if (!morePerm && !num_str.empty())
         {
             num_str = num_str.substr(1, num_str.size()-1);
             morePerm = true;
         }
    }
    cout<<number<<endl;
}

/** Euler 43 tesztfuggvenye */
bool isOK(string num_str)
{
    for (int i=0; i<num_str.size(); ++i)
        num_str[i]-='0';

    //szuro feltetelek:
 /*   if (num_str[3]&1)
        return false;
    if ( (num_str[2]+num_str[3]+num_str[4])% 3)
        return false;
    if (num_str[5]%5 )
        return false; */

    const int SIZE = 7;
    int primes[SIZE] = {2, 3, 5, 7, 11, 13, 17};
    for (int i=0; i<SIZE; ++i)
    {
        if ((100*num_str[i+1]+10*num_str[i+2] +num_str[i+3])%primes[i])
            return false;
    }
  /*  if ( (100*num_str[4]+10*num_str[5] +num_str[6])%7 )
        return false;
    if ( (100*num_str[5]+10*num_str[6] +num_str[7])%11 )
        return false;
    if ( (100*num_str[6]+10*num_str[7] +num_str[8])%13 )
        return false;
    if ( (100*num_str[7]+10*num_str[8] +num_str[9])%17 )
        return false; */

    return true;
}

/** Euler 41 */
bool isPrime(long long number)
{
     for (long long i=2; i<number-1; ++i)
     {
         if (number%i==0)
            return false;
     }
     return true;
}

#include <iostream>
#include <stdio.h>
#include <stdlib.h>
#include <cmath>
#include <climits>
using namespace std;
char is_prime(unsigned long long);

int main()
{
    unsigned long long i,j;
    const long long int N = 10;
    unsigned long long sum=0;
    char not_prime[N]={};
    for (i=2; i<N; ++i)
    {
        if (/*!not_prime[i] && */is_prime(i))
        {
           // for (j=i; j<N; j+=i)
           //     not_prime[j]=1;
           cout<<i<<" ";
            sum+=i;
        }
    }
    cout<<sum<<endl;
   cout<<"Max meret: "<<LLONG_MAX<<endl;
    printf("\nA %d alatti primek osszege: %d\n",N,sum);
    return 0;
}

char is_prime(unsigned long long number)
{
    if (number==0 || number==1) return 0;
    if (number==2 || number==3) return 1;
    unsigned long long i;
    for (i=2; i<(unsigned long long)sqrt(number)+1; ++i)
    {
        cout<<i<<" ";
        if (number%i==0)
        {
            return 0;
        }
    }
    return 1;
}

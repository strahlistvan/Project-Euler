#include <iostream>
#include <cmath>
#include <sstream>
#include "bignum.h"

using namespace std;
typedef long long uint64;
uint64 revNumber(uint64 num);
bool isPalindrome(uint64 num);
bool isPalindrome(string str);
string revStr(string str);
bool isLychrel(BigInteger number);

int main()
{
    const int LIMIT = 10000;
    int LychrelCount = 0;
    for (int n=1; n<LIMIT; ++n)
    {
        BigInteger number(n);
        if (isLychrel(number))
            ++LychrelCount;
    }
    cout<<LIMIT<<" alatt "<<LychrelCount<<" Lychrel-szam van."<<endl;

    return 0;
}

bool isPalindrome(string str)
{
    return str==string(str.rbegin(), str.rend());
}

string revStr(string str)
{
    return string(str.rbegin(), str.rend());
}

bool isPalindrome(uint64 num)
{
    while (num > 0)
    {
        uint64 divider = round(pow(10, (uint64)log10(num)));
        if ((num/divider) != (num%10))
            return false;
        num = num%divider;
        divider/=10;
        num/=10;
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

bool isLychrel(BigInteger number)
{
    int iterCount = 0;
    while (iterCount < 50)
    {
        BigInteger revNum(revStr(number.getNumbers()));
        number = number + revNum;
          //  if (number < 0)
          //      cout<<"tulcsordult!\n";
        if (isPalindrome(number.getNumbers()))
            return false;
        ++iterCount;
    }
    return true;
}

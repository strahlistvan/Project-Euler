#include <iostream>
#include <sstream>
#include <bitset>
using namespace std;

string num2string(int num);
bool is_palindrome(string text);
string num2bitString(int num);

int main()
{
    const int LIMIT = 1000000;
    int sum = 0;
    for (int i=0; i<LIMIT; ++i)
    {
        string bin = num2bitString(i);
        string dec = num2string(i);
        if ( is_palindrome(bin) && is_palindrome(dec) )
        {
            sum+=i;
        }
    }
    cout<<sum<<endl;
    return 0;
}

string num2bitString(int num)
{
    bitset<32> binary(num);
    stringstream ss;
    ss<<binary;
    string numStr = ss.str();
    while (numStr[0]=='0')
        numStr.erase(0, 1);
    return numStr;
}

string num2string(int num)
{
   stringstream ss;
   ss<<num;
   return ss.str();
}

bool is_palindrome(string text)
{
 return text==string(text.rbegin(), text.rend());
}

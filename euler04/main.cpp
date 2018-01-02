/** A legnagyobb palindrom szamot keresi meg, ami ket haromjegyu szam szorzatakent allithato elo. */
#include <iostream>
#include <sstream>
#include <string>
using namespace std;

bool is_palindrome(string text);

int main()
{
    int max =0;
    for (int i=100; i<1000; ++i)
        for (int j=100; j<1000; ++j)
        {
            int prod = i*j;
            stringstream ss;
            ss<<prod;
           string prod_str = ss.str();

           if (is_palindrome(prod_str) && prod>max )
           {
               max = prod;
           }
        }
    cout<<"Max: "<<max<<endl;
    return 0;
}

bool is_palindrome(string text)
{
    int N = text.size();
    for (int i=0; i<N/2; ++i)
    {
        if (text[i]!=text[N-1-i])
            return 0;
    }
    return 1;
}

#include <iostream>
#include <string>
#include <vector>
using namespace std;

class BigInteger
{
        string number;
        bool isNegative;

    public:
        BigInteger();
        BigInteger(string str);
        void inc();
        void dec();

        void operator ++ ();
        void operator -- ();

        void operator += (int num);
        void operator -= (int num);

        friend ostream & operator << (ostream & os, BigInteger number);
        friend BigInteger operator + (BigInteger & right, BigInteger & left);
        void operator = (BigInteger value);

};

ostream & operator << (ostream & os, BigInteger bigInt);
BigInteger operator + (BigInteger & right, BigInteger & left);

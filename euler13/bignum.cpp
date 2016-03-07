#include <iostream>
#include <string>
#include <vector>
#include "bignum.h"
using namespace std;


        BigInteger::BigInteger()
        {
            this->number = "0";
            isNegative = false;

        }
        BigInteger::BigInteger(string str)
        {
            if (str[0]=='-')
            {
                isNegative = true;
                str.erase(0,1);
            }
            else
                isNegative = false;
            this->number = str;
        }

        void BigInteger::inc()
        {
            int N = number.size()-1;
            //Amig kilences az utolso jegy, a helyere 0 kerul
            if (number[N]=='9')
            {
                while (number[N]=='9')
                {
                    number[N]='0';
                    --N;
                }
                //Helyiertek novelese 1-es beszurasaval, ha kell
                if (N==-1)
                   number.insert(0,1,'1');
                else
                    ++number[N];
            }
            //Egyebkent az utolso jegy novelese
            else
                ++number[N];
        }

        void BigInteger::dec()
        {
            int N = number.size()-1;
            //Amig nulla az utolso jegy, 9-es kerul a helyere
            if (number[N]=='0')
            {
                while (number[N]=='0')
                {
                    number[N]='9';
                    --N;
                }
                if (number[0]!='0')
                    --number[N];
            }
            //Egyebkent az utolso jegy csokkentese
            else
                --number[N];

            //Megmaradt nullak letorlese
            while (number[0]=='0' && number!="0")
                number.erase(0, 1);
        }


        void BigInteger::operator ++ ()
        {
            if (this->isNegative)
                this->dec();
            else this->inc();

            if(this->number == "0")
                this->isNegative = false;
        }

        void BigInteger::operator -- ()
        {
            if (this->isNegative)
                this->inc();
            else this->dec();

            if(this->number == "1")
                this->isNegative = true;
        }

        void BigInteger::operator += (int num)
        {
            for (int i=0; i<num; ++i)
                ++(*this);
        }

        void BigInteger::operator -= (int num)
        {
            for (int i=0; i<num; ++i)
                --(*this);
        }

        void BigInteger::operator = (BigInteger value)
        {
           this->number =  value.number;
           this->isNegative = value.isNegative;
        }

ostream & operator << (ostream & os, BigInteger bigInt)
{
    if (bigInt.isNegative)
        os<<"-";
    for (int i=0; i<bigInt.number.size(); ++i)
        os<<bigInt.number[i];
    return os;
}

BigInteger operator + (BigInteger & right, BigInteger & left)
{
    int right_size = right.number.size();
    int left_size = left.number.size();
    if (left_size>right_size)
    {
        swap(right, left);
        swap(right_size, left_size);
    }
    //Kisebb ele kiegeszito nullak:
    while (left.number.size()!=right_size)
    {
        left.number.insert(0,1,'0');
    }
    //Osszeadas algoritmus: legkisebb helyiertektol, atvitelekkel
    string result_str;
    int carry = 0;
    for (int i=right_size-1; i>=0; --i)
    {
        int a = right.number[i]-'0';
        int b = left.number[i]-'0';
        int c = (a+b+carry)%10;
        carry = (a+b+carry)/10;
        result_str.push_back(c+'0');
    }
    if (carry)
        result_str.push_back(carry+'0');
    result_str = string(result_str.rbegin(), result_str.rend());
    return BigInteger(result_str);
}

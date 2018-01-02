#include <iostream>
#include <string>
#include <vector>
#include <sstream>
#include "bignum.h"
using namespace std;

        BigInteger::BigInteger()
        {
            this->number = "0";
            isNegative = false;
        }

        BigInteger::BigInteger(int num)
        {
            stringstream sout;
            sout<<num;
            string str = sout.str();
            if (str[0]=='-')
            {
                isNegative = true;
                str.erase(0,1);
            }
            else
                isNegative = false;
            this->number = str;
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
            while (str[0]=='0') //szam eleji nullak
                str.erase(0, 1);
            this->number = str;
        }
        /** Paratlan-e a nagyszam ?*/
        bool BigInteger::isOdd()
        {
            int lastDigit = this->number[number.size()-1]-'0';
            return (lastDigit%2!=0);
        }
        bool BigInteger::isEven()
        {
            return !this->isOdd();
        }
        /** Visszaadja a nagy szam felet. */
        BigInteger BigInteger::half()
        {
            int N = number.size();
            string half;
            half.resize(N);
            int carry = 0;
            for (int i=0; i<N; ++i)
            {
                int digit = number[i]-'0';
                half[i] = (10*carry + digit)/2 + '0';
                carry = (number[i]-'0')%2;
            }
            return BigInteger(half);
        }


        /**Eggyel noveli a szam abszoluterteket */
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
        /**Eggyel csokkenti a szam abszoluterteket */
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

        /**Eggyel noveli a szam erteket */
        void BigInteger::operator ++ ()
        {
            if (this->isNegative)
                this->dec();
            else this->inc();

            if(this->number == "0")
                this->isNegative = false;
        }

        /**Eggyel csokkenti a szam erteket */
        void BigInteger::operator -- ()
        {
            if (this->isNegative)
                this->inc();
            else this->dec();

            if(this->number == "1")
                this->isNegative = true;
        }

        /**Noveli a nagy szam erteket a megadott szammal */
        void BigInteger::operator += (int num)
        {
            for (int i=0; i<num; ++i)
                ++(*this);
        }

        /**Csokkenti a nagy szam erteket a megadott szammal */
        void BigInteger::operator -= (int num)
        {
            for (int i=0; i<num; ++i)
                --(*this);
        }

        /** Megszorozza a nagy szam erteket a megadott szammal */
        void BigInteger::operator *= (int num)
        {
            BigInteger self(*this);
            for (int i=1; i<num; ++i)
                (*this)=(*this)+(self);
        }

        /**Ertekadas nagy szamokra */
        void BigInteger::operator = (BigInteger value)
        {
           this->number =  value.number;
           this->isNegative = value.isNegative;
        }
        /** Kis szam ertekadas */
        void BigInteger::operator = (int value)
        {
            (*this) = BigInteger(value);
        }

/** Ket nagy szam egyenlo-e? */
bool operator == (BigInteger left, BigInteger right)
{
    //Egyforma hosszu szamok-e?
    if (left.number.size()!=right.number.size())
        return false;
    //Egyforma elojelu szamok-e?
    if (left.isNegative != right.isNegative)
        return false;
    //Minden szamjegyuk egyezik-e?
    for (int i=0; i<left.number.size(); ++i)
    {
        if (left.number[i]!=right.number[i])
            return false;
    }

    return true;
}

bool operator != (BigInteger left, BigInteger right)
{
    return !(left==right);
}

/** Eldonti 2 nagy szamrol, hogy a bal kisebb-e a jobbnal */
bool operator < (BigInteger left, BigInteger right)
{
    bool isBothPositive = true;
    if (left==right)
        return false;
    if (left.isNegative && !right.isNegative)
        return true;
    if (!left.isNegative && right.isNegative)
        return false;

    //Negativ szamok eseten a nagyobb abszolut erteku a kisebb!
    if (!left.isNegative && !right.isNegative)
        isBothPositive = false;

    if ( left.countDigits() > right.countDigits() )
        return isBothPositive;
    if ( left.countDigits() > right.countDigits() )
        return (!isBothPositive);

    for (int i=0; i<left.countDigits(); ++i)
    {
        if (left.number[i] > right.number[i])
            return isBothPositive;
    }
    return !isBothPositive;
}

bool operator > (BigInteger left, BigInteger right)
{
    if (left==right)
        return false;
    return !(left<right);
}

/** Kimeno adatfolyamra iranyitas operator */
ostream & operator << (ostream & os, BigInteger bigInt)
{
    if (bigInt.isNegative)
        os<<"-";
    for (int i=0; i<bigInt.number.size(); ++i)
        os<<bigInt.number[i];
    return os;
}

/** Ket nagy szam osszeadasa. Visszateres: az osszeg (Nagy szam) */
BigInteger operator + (BigInteger & left, BigInteger & right)
{
    int right_size = right.number.size();
    int left_size = left.number.size();
    if (left_size>right_size)
    {
        swap(right, left);
        swap(right_size, left_size);
    }
    //Kisebb ele kiegeszito nullak:
    while (left.number.size() != right_size)
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

/** Ket nagy szam szorzasa. Visszateres: az szorzat (Nagy szam) */
BigInteger operator * (BigInteger & left, BigInteger & right)
{
    int N = left.number.size();
    int M = right.number.size();
    vector<int> a, b, res;
    res.resize(N+M);
    fill(res.begin(), res.end(), 0);
    //szamjegyek vektorokba nagyegeszekbol
    for (int i=0; i<N; ++i)
        a.push_back(left.number[i]-'0');
    for (int i=0; i<M; ++i)
        b.push_back(right.number[i]-'0');

    //Ciklus vegig a jobb oldali szamon
    for(int i=N-1; i>=0; --i)
    {   //ciklus a bal oldali szamon
        for(int j=M-1; j>=0; --j)
        {
          res[i+j+1] += a[i]*b[j]; //nem foglalkozik a maradekkal
        }
    }
  //maradek kezelese (az atualis maradek hozzadasa a elotte levohoz)
  for(int i=N+M-1; i>0; --i)
  {
    res[i-1] += res[i]/10;
    res[i] = res[i]%10;
  }
  //stringge alakitas:
  stringstream ss;
  //kulonbozo elojel eseten negativ szorzat
  if (left.negative()!=right.negative())
    ss<<"-";
  for (int i=0; i<res.size(); ++i)
  {
      if (res[i]<10 && res[i]>=0)
        ss<<res[i];
  }
  return BigInteger(ss.str());
}

/** balra Bitshift 'szeru' operator */
BigInteger operator >> (BigInteger base, int count)
{
    BigInteger result = base;
    for (int i=0; i<count; ++i)
    {
        result = result.half();
    }
    return result;
}

/** Nagy egesz alap integer kitevovel
*  parameterek: alap, kitevo (pozitiv!), visszateres: hatvany (Nagy szam) */
BigInteger bigIntPower(BigInteger base, int exp)
{
       if (exp==0) return 1;
       BigInteger power = 1;
       while(exp > 0)
       {
          if (!(exp&1))
          {
            exp>>=1;
            base = base*base;
          }
          else
          {
            --exp;
            power = power*base;
          }
       }
       return power;
}

/** Nagy egesz alap nagy egesz kitevovel
*  parameterek: alap, kitevo (pozitiv!), visszateres: hatvany ([NAGYON] Nagy szam) */
BigInteger bigIntPower(BigInteger base, BigInteger exp)
{
       if (exp==0) return 1;
       BigInteger power = 1;
       while(exp > 0)
       {
          if (exp.isEven())
          {
            exp = exp>>1;
            base = base*base;
          }
          else
          {
            --exp;
            power = power*base;
          }
       }
       return power;
}

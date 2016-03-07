using namespace std;

class BigInteger
{
        string number;
        bool isNegative;

    public:
        BigInteger();
        BigInteger(string str);
        BigInteger(int num);

        void inc();
        void dec();
        bool isOdd();
        bool isEven();
        BigInteger half();
        string getNumbers()
        {
            return this->number;
        }
        bool negative()
        {
            return this->isNegative;
        }
        int countDigits()
        {
            return this->number.size();
        }

        void operator ++ ();
        void operator -- ();
        void operator += (int num);
        void operator -= (int num);
        void operator *= (int num);
        void operator = (BigInteger value);
        void operator = (int value);

        friend ostream & operator << (ostream & os, BigInteger number);
        friend BigInteger operator + (BigInteger & right, BigInteger & left);
        friend BigInteger operator * (BigInteger & right, BigInteger & left);
        friend bool operator == (BigInteger left, BigInteger right);
        friend bool operator != (BigInteger left, BigInteger right);
        friend bool operator <  (BigInteger left, BigInteger right);
        friend bool operator > (BigInteger left, BigInteger right);
};

ostream & operator << (ostream & os, BigInteger bigInt);
BigInteger operator + (BigInteger & right, BigInteger & left);
BigInteger operator * (BigInteger & right, BigInteger & left);
BigInteger operator >> (BigInteger base, int count);

BigInteger bigIntPower(BigInteger base, int exp);
BigInteger bigIntPower(BigInteger base, BigInteger exp);


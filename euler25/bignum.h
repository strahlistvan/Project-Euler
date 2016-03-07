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

        void operator ++ ();
        void operator -- ();

        void operator += (int num);
        void operator -= (int num);
        void operator *= (int num);
        void operator = (BigInteger value);

        friend ostream & operator << (ostream & os, BigInteger number);
        friend BigInteger operator + (BigInteger & right, BigInteger & left);
        friend BigInteger operator * (BigInteger & right, BigInteger & left);
        friend bool operator == (BigInteger left, BigInteger right);
        friend bool operator != (BigInteger left, BigInteger right);

        string getNumbers()
        {
            return this->number;
        }
        bool negative()
        {
            return this->negative();
        }

};

ostream & operator << (ostream & os, BigInteger bigInt);
BigInteger operator + (BigInteger & right, BigInteger & left);

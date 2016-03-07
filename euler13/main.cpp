#include <iostream>
#include <fstream>
#include "bignum.h"
using namespace std;

int main()
{
    ifstream fin("number.txt");
    string number_str, line;
    BigInteger sum_bigint;
    cout<<sum_bigint<<endl;
    while (!fin.eof())
    {
        getline(fin, line);
        BigInteger current_bigint(line);
        cout<<current_bigint<<endl;
        sum_bigint = sum_bigint + current_bigint;
    }
    fin.close();
    cout<<sum_bigint<<endl;

    return 0;
}

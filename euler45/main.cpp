#include <iostream>
#include <cmath>
using namespace std;

bool isTriangular(uint64_t number);
bool isPentagonal(uint64_t number);
bool isHexagonal(uint64_t number);
bool isHexPent(uint64_t number);

int main()
{
    uint64_t number = 40756;
    bool found = false;
    while (!found)
    {
        if (isPentagonal(number) && isHexagonal(number))
        {
            cout<<number<<" is triangular, pentagonal and hexagonal!"<<endl;
            found = true;
        }
  //      if (number < 9999)
  //          cout<<"Owerflow alert!\n";
        ++number;
    }
    return 0;
}

//bad bad function!
bool isHexPent(uint64_t number)
{
    uint64_t intResult = (1+sqrt(8*number+9))/2;
    double realResult = (1.0+sqrt(8*number+9))/2.0;
    return (intResult==realResult);
}

bool isTriangular(uint64_t number)
{
    uint64_t intResult = (-1+sqrt(1+8*number))/2;
    double realResult = (-1.0+sqrt(1+8*number))/2.0;
    return (intResult==realResult);
}

bool isPentagonal(uint64_t number)
{
    //uint64_t intResult = (1+sqrt(1+24*number))/6;
    double realResult = (1.0+sqrt(1+24*number))/6.0;
    return (realResult==(uint64_t)realResult);
}

bool isHexagonal(uint64_t number)
{
   // uint64_t intResult = (1+sqrt(1+8*number))/4;
    double realResult = (1.0+sqrt(1+8*number))/4.0;
    return (realResult==(uint64_t)realResult);
}

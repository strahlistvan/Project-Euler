#include <iostream>
#include <cmath>
using namespace std;

int karacuba(int num1, int num2);

int main()
{
    cout << "Hello world!" << endl;
    karacuba(68,50);
    return 0;
}

int size_base10(int n)
{
    int size=0;
    while ( n>=pow(10,size++) );
    return size-1;

}

int * split_at(int number, int place)
{
    int power10 = pow(10, place);
    int low = number%power10;
    int up = number/power10;
    static int back[2] = {low, up};
    return back;
}

int karacuba(int num1, int num2)
{
    if (num1 < 10 || num2<10)
        return num1*num2;
    /* calculates the size of the numbers */
    int sizeOfNumbers = max(size_base10(num1), size_base10(num2));
   // cout<<sizeOfNumbers<<endl;
    int middle = sizeOfNumbers/2;
    /* split the digit sequences about the middle */
    int * firstSplit = split_at(num1, middle);
    int * secondSplit = split_at(num2, middle);
    cout<<firstSplit[0]<<"--"<<firstSplit[1]<<endl;

    int z0 = karacuba(firstSplit[0], secondSplit[0]);
   int z1 = karacuba((firstSplit[1]+secondSplit[0]),(firstSplit[1]+secondSplit[0]));
   int z2 = karacuba(secondSplit[0],secondSplit[1]);

    return (z2*pow(10, 2*middle))+((z1-z2-z0)*pow(10, middle))+(z0);
}


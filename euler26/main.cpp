#include <iostream>
#include <sstream>
#include <iomanip>
using namespace std;

string maxCycleSize(string num_str);

int main()
{
    for (int i=2; i<=10; ++i)
    {
        string num_str=""; //tizedesjegyek (max 16 jegyig)
        ostringstream sout;
        sout<<setprecision(16)<<(double)1/i;
        num_str = sout.str().substr(2, -2);
        cout<<num_str<<endl; //tizedes
        cout<<maxCycleSize(num_str)<<endl;
    }
    return 0;
}

string maxCycleSize(string num_str)
{
    for (int i=0; i<num_str.size(); ++i)
    {

    }
}

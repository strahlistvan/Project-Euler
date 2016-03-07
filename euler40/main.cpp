#include <iostream>
#include <sstream>
#include <cmath>
using namespace std;

//Chamernowne konstans kiszamitasa 1000000 tizedesjegyig
int main(int argc, char ** argv)
{
    string champernowne ="";
    const int LIMIT = 1000000;
    ostringstream sstream;
    for (int n=1; champernowne.size()<LIMIT; ++n)
    {
        sstream<<n;
        champernowne += sstream.str();
        //sstream tisztitasa:
        sstream.str(string());
        sstream.clear();
    }

  //  cout<<champernowne.substr(0, 100)<<endl;
  //  cout<<champernowne.substr(LIMIT-100, 100)<<endl;

   int product = 1; //vegeredmeny
   for (int exp = 0; exp<=log10(LIMIT); ++exp)
   {
       int index = pow(10, exp);
       cout<<"champ["<<index<<"] = "<<champernowne[index-1]<<endl;
       product *= (champernowne[index-1]-'0');
   }
    cout<<"\nA megadott tizedesjegyek szorzata: "<<product<<endl;
    return 0;
}

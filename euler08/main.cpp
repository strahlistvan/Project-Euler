#include <iostream>
#include <fstream>
using namespace std;

int main()
{
    // Szam beolvasasa
    ifstream fin("number.txt");
    string number;
    fin>>number;
    fin.close();

    //Feldolgozas
    const int N=13;
    int digits[N];
    long long prod = 1, maxprod=1;
    cout<<"Meret: "<<number.size()<<endl;
    for (int i=0; i<number.size(); ++i)
    {
        for (int j=0; j<N; ++j)
        {
            cout<<number[i+j]<<"*";
            prod*=(number[i+j]-'0');
        }
        cout<<"="<<prod<<endl;
        if (prod > maxprod)
        {
            maxprod = prod;
        }
        prod = 1;
    }

    cout<<endl<<N<<" szamjegy legnagyobb szorzata: "<<maxprod<<endl;

    return 0;
}

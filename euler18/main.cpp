#include <iostream>
#include <fstream>
#include <cmath>
using namespace std;

const int SIZE = 15;
int ** read_matrix(string fileName);

int main()
{
    int ** Matrix = read_matrix("triangle.txt");
    int powerOfTwo = pow(2, SIZE); //SIZE bites szam
    int sum = 0, tempSum, index;

    //Minden lehetoseg vizsgalata:
    for (int i=0; i<powerOfTwo-1; ++i)
    {
        tempSum = Matrix[0][0];
        index = 0;
        //Vegig a nagy hatvany bitjein (SIZE)
        for (int j=0; j<SIZE-1; ++j)
        {
            //index: a j. bit alapjan dontjuk el, hogy jobbra vagy balra (+1 vagy +0)
            index = index + (i >> j & 1);
            tempSum += Matrix[j+1][index];
        }
        //Maximum kivalasztas
        if (tempSum > maxSum)
        {
           // cout<<tempSum<<endl;
            maxSum = tempSum;
        }
    }
    cout<<"A legnagyobb osszeg: "<<maxSum<<endl;
    return 0;
}

int ** read_matrix(string fileName)
{
    ifstream fin(fileName.c_str());
    if (!fin.is_open())
    {
        cerr<<"Hiba "<<fileName<<" megnyitasakor!"<<endl;
        return NULL;
    }

    static int ** Matrix = new int * [SIZE];
    for (int row=0; row<SIZE; ++row)
    {
        Matrix[row] = new int[SIZE];
        for (int col=0; col<=row; ++col)
        {
            if (fin.eof()) //Hibakezeles
            {
                cerr<<"Vege a filenak. Nem sikerult "<<SIZE<<"sort beolvasni"<<endl;
                return NULL;
            }
            fin>>Matrix[row][col];
            cout<<Matrix[row][col]<<" ";
        }
     cout<<endl;
    }

    fin.close();
    return Matrix;
}

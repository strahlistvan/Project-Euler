#include <iostream>
#include <fstream>
using namespace std;

const int SIZE = 100;
int ** read_matrix(string fileName);

int main()
{
    int ** Matrix = read_matrix("big_triangle.txt");

    //Utolso elotti sortol indul:
    for (int i=SIZE-2; i>=0; --i)
    {
        //Vegigmegy az i. soron:
        for (int j=0; j<=i; ++j)
        {
            //A megadott elemhez hozzaadja a 2 szomszed kozul a nagyobbat
            Matrix[i][j] += max(Matrix[i+1][j], Matrix[i+1][j+1]);
        }
      }
    //A haromszog 'csucsara' az osszeg maximalis lesz!
    cout<<Matrix[0][0]<<endl;
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

#include <iostream>
#include <algorithm>
#include <ctime>
using namespace std;

void permute(string completed, string notCompleted);
void permute2(string str);
int counter = 0; //szamlalja a permutaciokat

int main()
{
    double t1 =clock();
    permute("0123456789", "");
    double t2 = clock();

    cout<<(t2-t1)/CLOCKS_PER_SEC<<endl;
    counter = 0;
    double t3 = clock();
    permute2("0123456789");
    double t4 = clock();
    cout<<(t4-t3)/CLOCKS_PER_SEC<<endl;

    return 0;
}

/** Megkeresi a megadott string osszes lehetseges permutaciojat
 *  Elso parameter: permutalando string, 2. parameter: ures string*/
void permute(string notCompleted, string completed)
{
    if (notCompleted.size()==0)
    {
        ++counter; //szamolja a permutaciokat
        cout<<completed<<endl;
        if (counter==1000000)
        {
            cout<<completed<<endl;
        }
        return;
    }
    //Permutalas:
    for (int i=0; i<notCompleted.size(); ++i)
    {
        string next = completed + notCompleted[i];
        string remaining = notCompleted.substr(0, i) + notCompleted.substr(i+1);
       // cout<<"next:"<<next<<" remaining: "<<remaining<<endl;
        permute(remaining, next);
    }
}

/** Megkeresi a megadott string osszes lehetseges permutaciojat */
void permute2(string str)
{
    bool hasMorePerm = true;
    //Amig van permutacio:
    while(hasMorePerm)
    {
        ++counter; //szamlalo
        if (counter==1000000)
            cout<<str<<endl;
        //Megkeresi a string kovetkezo permutaticojat:
        hasMorePerm = next_permutation(str.begin(), str.end());
    }
}

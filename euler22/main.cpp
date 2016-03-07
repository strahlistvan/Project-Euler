#include <iostream>
#include <fstream>
#include <vector>
using namespace std;

void sort_names(vector<string> & names);

int main()
{
    ifstream fin("names.txt");
    vector<string> names;
    if (!fin)
    {
        cerr<<"Hiba a file megnyitasakor"<<endl;
        return -1;
    }
    while (!fin.eof())
    {
        string str;
        getline(fin,str,',');
        str = str.substr(1,str.size()-2);
        names.push_back(str);
    }
    fin.close();
    cout<<"Sikeresen beolvasva!"<<endl;

    sort_names(names);
    for (int i=0; i<100; ++i)
        cout<<names[i]<<endl;

    //Pontszamok osszegenek kiszamolasa
    long long int sum_score = 0;
    for (int i=0; i<names.size(); ++i)
    {
        int score = 0; //i. szo pontszama
        //Betuk pozicioinak osszege
        for (int j=0; j<names[i].size(); ++j)
        {
            score+=names[i][j]-'A'+1;
        }
        score*=(i+1); //sorszammal megszorozva

        if (names[i]=="COLIN")
            cout<<"COLIN'S: "<<score<<endl;
        sum_score += score;
    }
    cout<<"Sum of all scores: "<<sum_score<<endl;
    return 0;
}

/** Kisse primitiv, lassu, de mukodo abc-rendezes*/
void sort_names(vector<string> & names)
{
    for (int i=0; i<names.size(); ++i)
    {
        for (int j=i; j<names.size(); ++j)
        {
            int min_size = names[i].size()<names[j].size()?names[i].size():names[j].size();

            bool done = false;
            //Ha a rovidebb resze egy hosszabbnak, a hosszabb hatrabb
            if (names[j].substr(0,min_size)==names[i].substr(0,min_size)
                && names[j].size()==min_size)
            {
                swap(names[i], names[j]);
                done = true;
            }
            //Amig egyeznek a betuik, vagy a kisebb veget nem er
            for (int k=0; !done && k<min_size; ++k)
            {
                //Ha a k. betu szerint rossz a sorrend, csere, es kesz.
                if (names[i][k]>names[j][k])
                {
                    swap(names[i], names[j]);
                    done = true;
                }
                //Ha megfelelo a sorrend, kesz
                else if (names[i][k]<names[j][k])
                    done = true;
                //Egyenloseg eseten k novelese
            }
        }
    }
}

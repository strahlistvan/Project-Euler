#include <iostream>
#include <fstream>
#include <cstdlib>
#include <vector>
using namespace std;

string read_ecnrypt_text(string fileName);
vector<string> gen_keys();

int main()
{
    string ciphertext = read_ecnrypt_text("cipher.txt");
    cout<<ciphertext.size()<<endl;
    vector<string> keys = gen_keys();
    cout<<keys.size()<<endl;

    ofstream fout("plains.txt");
    if (!fout.is_open())
        cerr<<"Hiba a megnyitaskor"<<endl;
    for (int i=0; i<keys.size(); ++i)
    {
        string key = keys[i];
        string plaintext = "";
        for (int j=0; j<ciphertext.size()-3; j+=3)
        {
            plaintext.push_back(key[0]^ciphertext[j]);
            plaintext.push_back(key[1]^ciphertext[j+1]);
            plaintext.push_back(key[2]^ciphertext[j+2]);
        }
       // fout<<i<<". plain:"<<endl;

     //  string commonWords[10]={"that", "have", "with", "this", "from", "they", "what", "when", "make", "time"};
     //  string commonWords2[10] = {"and", "for", "not", "you", "but", "she", "say", "her", "will", "one"};
     for (int j=0; j<plaintext.size()-3; ++j)
       {
         //   for (int k=0; k<10; ++k)
                if (plaintext.substr(j, 1)=="a" )
                     fout<<plaintext<<endl<<endl<<endl;
       }
    }

    cout << "Hello world!" << endl;
    fout.close();
    return 0;
}

/** Osszes  lehetseges kulcs eloallitasa */
vector<string> gen_keys()
{
    vector<string> keys;
    for (char i='a'; i<='z'; ++i)
        for (char j='a'; j<='z'; ++j)
            for (char k='a'; k<='z'; ++k)
            {
                string key;
                key[0] = i;
                key[1] = j;
                key[2] = k;
                keys.push_back(key);
            }
     return keys;
}

string read_ecnrypt_text(string fileName)
{
    ifstream fin(fileName.c_str());
    string num, ciphertext;
    while (!fin.eof())
    {
        getline(fin, num, ',');
        //cout<<num<<",";
        char c = (char) atoi(num.c_str());
        ciphertext.push_back(c);
    }
    fin.close();
    //cout<<ciphertext<<endl;
    return ciphertext;
}

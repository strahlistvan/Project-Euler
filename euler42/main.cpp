#include <iostream>
#include <fstream>
#include <vector>
#include <cmath>
using namespace std;

vector<string> readWords(string fileName);
bool isTriangleNumber(int number);
int getWordValue(string word);

int main()
{
    vector<string> words = readWords("words.txt");
    cout<<"Sikeresen beolvasva!"<<endl;
    if (words.empty())
    {
        cerr<<"Ures vektor."<<endl;
        return -1;
    }
    int count = 0;
    for (int i=0; i<words.size(); ++i)
    {
       int wordValue = getWordValue(words[i]);
       if (isTriangleNumber(wordValue))
        ++count;
    }
    cout<<"Triangle words count: "<<count<<endl;
    return 0;
}


vector<string> readWords(string fileName)
{
    ifstream fin(fileName.c_str());
    vector<string> words;
    if (!fin)
    {
        cerr<<"Hiba a file megnyitasakor"<<endl;
        return words;
    }
    while (!fin.eof())
    {
        string str;
        getline(fin,str,',');
        str = str.substr(1,str.size()-2);
        words.push_back(str);
    }
    fin.close();
    return words;
}

int getWordValue(string word)
{
    int wordValue = 0;
    for (int j=0; j<word.length(); ++j)
    {
        wordValue += word[j]-'A'+1;
    }
    return wordValue;
}

bool isTriangleNumber(int number)
{
    //use the triangular invers function!
    double result = (sqrt(8*number+1)-1.0)/2.0;
    //if the result is integer, then number is triangle
    return (result==(int)result);
}

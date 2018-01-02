#include <iostream>
#include <fstream>
using namespace std;

string BigIntStrAdd(string left_str, string right_str)
{
    //A bal oldali tag legyen a nagyobb
    if (right_str.size() > left_str.size())
        swap(right_str, left_str);

    int numSize = left_str.size();
    //Kisebb ele kiegeszito nullak:
    while (right_str.size() != numSize)
    {
        right_str.insert(0,1,'0');
    }

    //Osszeadas algoritmus: legkisebb helyiertektol, atvitelekkel
    string result_str;
    int carry = 0;
    for (int i=numSize-1; i>=0; --i)
    {
        int a = left_str[i]-'0';
        int b = right_str[i]-'0';
        int c = (a+b+carry)%10;
        carry = (a+b+carry)/10;
        result_str.push_back(c+'0');
    }
    if (carry)
        result_str.push_back(carry+'0');
    result_str = string(result_str.rbegin(), result_str.rend());
    return result_str;
}


int main()
{
    ifstream fin("number.txt");
    string number_str, line;

    string sum_str = "";
    while (!fin.eof())
    {
        getline(fin, line);
     //   cout<<line<<endl;
        sum_str = BigIntStrAdd(sum_str, line);
    }
    fin.close();
    cout<<sum_str.substr(0, 10)<<endl;

    return 0;
}

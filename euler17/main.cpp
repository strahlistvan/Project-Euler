#include <iostream>
#include <climits>
using namespace std;

unsigned howManyCharacters(unsigned number);

int main(int argc, char ** argv)
{
    const int LIMIT = 20;
    unsigned sum = 0;

    for (int i=1; i<=LIMIT; ++i)
    {
        sum+=howManyCharacters(i);
    }
    cout<<"1 es "<<LIMIT<<" kozotti osszes szam angol neveben leve betuk szama: "<<sum<<endl;
    return 0;
}

/** Visszaadja a parameterkent megadott pozitiv egesz angol neveben szereplo betuk szamat. */
unsigned howManyCharacters(unsigned number)
{
    int number0 = number;
    if (number<=0 && number >= INT_MAX)
    {
        cerr<<"Hibas bemenet! Pozitiv egesz szamnak kell lennie (32 bites)"<<endl;
        return -1;
    }
    const unsigned digitsSize=9, toTwentySize=10, tensSize=8, prefixSize=4;

    string digits[digitsSize] = {"one","two","three","four","five","six","seven","eight","nine"};
    string toTwenty[toTwentySize] = {"ten","eleven","twelve", "thirteen", "fourteen","fifteen","sixteen","seventeen","eighteen","nineteen"};
    string tens[tensSize] = {"twenty","thirty","forty","fifty","sixty","seventy","eighty","ninety"};
  //  string prefixes[prefixSize] = {"","thousand","million","billion"};

    //0-9 kozotti szam eseten
    if (number>=1 && number<=digitsSize)
    {
        return digits[number-1].size();
    }
    //10-19 kozotti szam eseten
    else if (number>=digitsSize+1 && number<=digitsSize+toTwentySize)
    {
        return toTwenty[number%10].size();
    }

    string resultString = "", tenString="";
    int counter = 0;
    while (number>0)
    {
        //Kerek szazasokra kulon figyelni
        if (number%100==0)
        {
            resultString = digits[number/100-1]+" hundred";
            return resultString.size();
        }

        //resultString += prefixes[counter++];
        //A szam vegzodese 'teen'
        if (number/10%10==1)
        {
            tenString += toTwenty[number%10];
        }
        //a szam vegzodese 0x
        else if (number/10%10==0 && number%10!=0)
        {
            tenString += digits[number%10-1];
        }
        //Ha a szam vege 20-99 kozott van
        else
        {
            tenString+=tens[number/10%10-2];
            if (number%10!=0)
            {
                tenString+="-"+digits[number%10-1];
            }
        }

        number/=100;
        //Szazasok:
        if (number%10!=0)
            resultString += digits[number%10-1] + " hundred ";
        number/=10;

        resultString += tenString;
    }
   cout<<number0<<": "<<resultString<<endl;
  return resultString.size();
}

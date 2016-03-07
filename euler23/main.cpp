#include <iostream>
#include <vector>
#include <cmath>
using namespace std;

bool isAbundant(int number);

//Find the sum of all the positive integers which cannot be written as the sum of two abundant numbers!
int main()
{
    const int LIMIT = 28123; //'by mathematical analysis'
    vector<int> abNums;
    //find all abundant numbers (under 28123)
    for (int i=1; i<=LIMIT; ++i)
    {
       if (isAbundant(i))
        abNums.push_back(i);
    }
    cout<<"Bovelkedo szamok megtalalva: "<<abNums.size()<<" db\n";

    //all possible sums:
    bool isSumOf2abNums[LIMIT+1] = {}; //flag array
    for (int i=0; i<abNums.size(); ++i)
    {
        for (int j=i; j<abNums.size(); ++j)
        {
            int sum = abNums[i] + abNums[j];
            if (sum <= LIMIT)
                isSumOf2abNums[sum] = true;
            else
                break;
        }
    }

    //sum the 'good numbers'
    int total = 0;
    for (int num=1; num<=LIMIT; ++num)
    {
        if (!isSumOf2abNums[num])
            total += num;
    }

    cout<<"Result: "<<total<<endl;
    return 0;
}

/** Eldonti egy szamrol, hogy bovelkedo szam-e */
bool isAbundant(int number)
{
    if (number<=1)
        return 0;
    int sum = 1; //az 1 mindig oszto;
    int sqrtNumber = sqrt(number);
    //Negyzetszamot csak egyszer osszegez:
    if (number == sqrtNumber*sqrtNumber)
    {
        sum+=sqrtNumber;
        --sqrtNumber;
    }
    //Megkeresi a valodi osztoit (negyzetgyokig: felsot+alsot)
    for (int index=2; index<=sqrtNumber; ++index)
    {
        if (number%index==0)
        {
            sum+= index + (number/index);
        }
    }
    return (sum>number);
}

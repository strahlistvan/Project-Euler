#include <iostream>
#include <vector>
#include <algorithm>
#include <climits>
using namespace std;

vector<int> getPentagonals(int LIMIT);
bool isInVector(vector<int> vec, int key);

int main()
{
    const int LIMIT = 1000000;
    vector<int> pentagonals = getPentagonals(LIMIT);
    bool found = false;
    for (int i=0; i<pentagonals.size() && !found; ++i)
    {
        for (int j=0; j<pentagonals.size() && !found; ++j)
        {
            int add  = pentagonals[j]+pentagonals[i];
            int subs = abs(pentagonals[i]-pentagonals[j]);
            if (isInVector(pentagonals, subs) && isInVector(pentagonals, add))
            {
                cout<<pentagonals[i]<<" and "<<pentagonals[j]<<"ok\n";
                found = true;
            }
        }
    }
    return 0;
}

bool isInVector(vector<int> vec, int key)
{
    vector<int>::iterator result;
    result = find(vec.begin(), vec.end(), key);
    return (result < vec.end());
}

vector<int> getPentagonals(int LIMIT)
{
    int currPent = 1;
    vector<int> pentagonals;
    for (int n=2; currPent<LIMIT && pentagonals.size()<pentagonals.max_size(); ++n)
    {
        pentagonals.push_back(currPent);
        currPent = n*(3*n-1)/2;
    }
    return pentagonals;
}

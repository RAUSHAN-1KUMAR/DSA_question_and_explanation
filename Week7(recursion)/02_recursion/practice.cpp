

#include<iostream>
#include<vector>
#include<limits.h>
using namespace std;

vector<int> findIndex(int num)
{   
    vector<int> ans;
    if(num==0) return ans;

    vector<int> aggeka = findIndex(num/10);

    
    for(auto each:aggeka)
    {
        ans.push_back(each);
    }
    ans.push_back(num%10);

    return ans;
}

int main()
{
    int number = 4215;

    vector<int> indexes = findIndex(number);

    for(auto ele:indexes)
    {
        cout << ele << " ";
    }
    return 0;
}
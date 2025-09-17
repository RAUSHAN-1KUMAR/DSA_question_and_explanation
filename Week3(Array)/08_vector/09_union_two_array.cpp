     
// duplicates may be present

#include<iostream>
#include<vector>
#include<limits.h>
using namespace std;
 
int main()
{   
    vector<int> arr{1,2,3,4,6,8};
    vector<int> brr{3,3,4,9,10};

    vector<int> ans;

    for(int i = 0 ; i<arr.size() ; i++)
    {
        for(int j = 0 ; j<brr.size() ; j++)
        {
            if(arr[i] == brr[j])
            {
                brr[j] = INT_MIN;
            }
        }
    } 

    for(int i = 0 ; i<arr.size() ; i++)
    {
        ans.push_back(arr[i]);
    } 

    for(int i = 0 ; i<brr.size() ; i++)
    {
        if(brr[i]!=INT_MIN)
            ans.push_back(brr[i]);
        else
            continue;
    } 

    for(auto value: ans)
    {
        cout << value << " ";
    } 
    
    return 0;
}





/* -> 1636

Given an array of integers nums, sort the array in increasing order based on the frequency of the values. If multiple values have the same frequency, sort them in decreasing order.

Return the sorted array.

 

Example 1:
    Input: nums = [1,1,2,2,2,3]
    Output: [3,1,1,2,2,2]
    Explanation: '3' has a frequency of 1, '1' has a frequency of 2, and '2' has a frequency of 3.


Example 2:
    Input: nums = [2,3,1,3,2]
    Output: [1,3,3,2,2]
    Explanation: '2' and '3' both have a frequency of 2, so they are sorted in decreasing order.

Example 3:
    Input: nums = [-1,1,-6,4,5,-6,1,4,1]
    Output: [5,-1,4,4,-6,-6,1,1,1]
*/

#include<iostream>
#include<vector>
#include<map>
#include<algorithm>
using namespace std;

bool customSorting(pair<int,int> a, pair<int,int> b)
{
    if(a.second == b.second)
    {
        return a.first > b.first;
    }

    return a.second < b.second;
}

vector<int> frequencySort(vector<int>& nums) 
{
    // making table of data and its frequency
    map<int, int> mp;
    for(int num:nums)
    {
        mp[num]++;
    }

    // storing the data into vector of pairs to apply sorting
    vector<pair<int,int>> vec;
    for(auto it = mp.begin() ; it!=mp.end() ; it++)
    {
        vec.push_back({it->first, it->second});
    }

    // sorting the formed vector using custom comparator
    sort(vec.begin(), vec.end(), customSorting);

    // forming answer array
    vector<int> ans;
    for(int i=0 ; i<vec.size() ; i++)
    {
        auto it = vec[i];

        if(it.second == 1){
            ans.push_back(it.first);
        }
        else{
            int data = it.second;
            while(data){
                ans.push_back(it.first);
                data--;
            }
        }
    }

    return ans;
}

int main()
{
    vector<int> nums = {1,5,0,5};

    vector<int> ans = frequencySort(nums);

    for(int num:ans)
    {
        cout << num << " ";
    }

    return 0;
}
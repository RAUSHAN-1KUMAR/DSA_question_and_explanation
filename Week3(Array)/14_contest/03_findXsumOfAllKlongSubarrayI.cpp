/* 3318

You are given an array nums of n integers and two integers k and x.

The x-sum of an array is calculated by the following procedure:
    1. Count the occurrences of all elements in the array.
    2. Keep only the occurrences of the top x most frequent elements. If two elements have the same number of occurrences, the element with the bigger value is considered more frequent.
    3. Calculate the sum of the resulting array.

Note that if an array has less than x distinct elements, its x-sum is the sum of the array.

Return an integer array answer of length n - k + 1 where answer[i] is the x-sum of the subarray nums[i..i + k - 1].

 

Example 1:
    Input: nums = [1,1,2,2,3,4,2,3], k = 6, x = 2
    Output: [6,10,12]
    Explanation:
    For subarray [1, 1, 2, 2, 3, 4], only elements 1 and 2 will be kept in the resulting array. Hence, answer[0] = 1 + 1 + 2 + 2.

    For subarray [1, 2, 2, 3, 4, 2], only elements 2 and 4 will be kept in the resulting array. Hence, answer[1] = 2 + 2 + 2 + 4. Note that 4 is kept in the array since it is bigger than 3 and 1 which occur the same number of times.

    For subarray [2, 2, 3, 4, 2, 3], only elements 2 and 3 are kept in the resulting array. Hence, answer[2] = 2 + 2 + 2 + 3 + 3.
    

Example 2:
    Input: nums = [3,8,7,8,7,5], k = 2, x = 2
    Output: [11,15,15,15,12]
    Explanation: Since k == x, answer[i] is equal to the sum of the subarray nums[i..i + k - 1].
*/

/*
Approach: sliding window + hashing(using map)
*/


#include<bits/stdc++.h>
using namespace std;

vector<int> findXSum(vector<int> &nums, int k, int x)
{
    vector<int> result;

    unordered_map<int,int> mp;

    int start=0;
    int end=0;
    int wndSize=k;
    while(end<nums.size())
    {
        // map m element ka freq store kerte jao
        mp[nums[end]]++;


        if(end-start+1 == wndSize)
        {
            // Jaise hi window size hit hua mai apne map m pade data ko vector m store ker rha hun taake baad m usse sort ker sakun
            vector<pair<int,int>> temp;

            for(auto it = mp.begin() ; it!=mp.end() ; it++)
            {
                temp.push_back({it->first, it->second});
            }

            // sorting using lambda function
            sort(temp.begin(), temp.end(), [](pair<int,int> a, pair<int,int> b)
            {
                if(a.second==b.second)
                {
                    return a.first > b.first;
                }

                return a.second>b.second;
            });

            // vector m sort kerne ke baad ab x sum
            int times = x;
            int sum=0;
            for(auto eachEle:temp)
            {
                if(times==0) break;

                int sum1 = (eachEle.first)*(eachEle.second);
                sum+=sum1;
                times--;
            }

            result.push_back(sum);

            // now window ko ek decrease kerdo
            mp[nums[start]]--;
            start++;
        }

        end++;
    }

    return result;
}

int main()
{
    vector<int> nums = {3,8,7,8,7,5};
    int k = 2;
    int x = 2;

    vector<int> ans = findXSum(nums, k, x);

    for(int num:ans)
    {
        cout << num << " ";
    }

    return 0;
}
/* 3321

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
Appraoch: sliding window + hashing + set
    - set store the data in ascending order,
    - we will first mark the freq in map, than in set. so that set can store the freq also

Note:- this approach will give TLE, better solution -> see next solution
*/

#include<bits/stdc++.h>
using namespace std;

vector<long long> findXSum(vector<int> &nums, int k, int x)
{
    int n = nums.size();

    set<pair<long long, long long>> sums;// store the frequency in ordered way
    unordered_map<long long, long long> mp;// store the frequency
    vector<long long> ans;

    // first form k size window
    for(int i=0 ; i<k && i<n ; i++)
    {
        int to_add = nums[i];

        // erase the data in set, so that new data with inreased freq can be inserted again
        sums.erase({mp[to_add], to_add});

        mp[to_add]++;

        // now inserted the updated freq from map
        sums.insert({mp[to_add], to_add});
    }


    // now we finding the sum of top freq using the set
    auto calculate_top_x_sum = [&](int x) -> long long {
        long long sum = 0;
        int count = x;
        // calculating the sum from last of the set, because set sort the data in ascending order but we want data with highest freq
        for(auto it = sums.rbegin() ; it != sums.rend() && count>0 ; ++it, --count)
        {
            sum += it->first * it->second;
        }
        return sum;
    };

    ans.push_back(calculate_top_x_sum(x));


    // now left window
    for(int i=k ; i<n ; i++)
    {
        // window is shifting, so handling the (i-k)th  element's freq in both map and set
        int to_remove = nums[i-k];
        sums.erase({mp[to_remove], to_remove});
        mp[to_remove]--;

        if(mp[to_remove]>0){
            sums.insert({mp[to_remove], to_remove});
        }

        // new element is coming
        int to_add = nums[i];
        sums.erase({mp[to_add], to_add});
        mp[to_add]++;
        sums.insert({mp[to_add], to_add});

        ans.push_back(calculate_top_x_sum(x));
    }

    return ans;
}

int main()
{
    vector<int> nums = {3,8,7,8,7,5};
    int k = 2;
    int x = 2;

    vector<long long> ans = findXSum(nums, k, x);

    for(int num:ans)
    {
        cout << num << " ";
    }
    return 0;
}
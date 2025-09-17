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
    -- we are gonna use different appraoch in place of the function calculate_top_x_sum which we are calling to find the x sum in set.
    -- we will use two set, one is rightSet and other is leftSet
*/

#include<bits/stdc++.h>
using namespace std;

vector<long long> findXSum(vector<int> &nums, int k, int x)
{
    int n = nums.size();

    // we will have two set and a common sum variable, to remove the calculate_top_x_sum function
    set<pair<long long, long long>> left;
    set<pair<long long, long long>> right;
    long long sum = 0;

    unordered_map<long long, long long> freq;
    vector<long long> ans;


    auto add_right = [&](long long count, long long value) {
        right.insert({count, value}); 
        sum +=   count * value;   
        if (right.size() > x) {       \
            auto smallest = *right.begin();   
            sum -=  smallest.first * smallest.second; 
            left.insert(smallest);    
            right.erase(right.begin()); 
        }
    };

    auto remove_right = [&](long long count, long long value) {
        auto smallest = *right.begin(); 
        auto current = make_pair(count, value); 
        if (current >= smallest) {  
            sum -=  count * value; 
            right.erase(current);    
            if (left.size() && right.size() < x) { 
                auto largest = *left.rbegin(); 
                sum +=  largest.first * largest.second; 
                right.insert(largest); 
                left.erase(largest);   
            }
        } else {
            left.erase(current); 
        }
    };

    int i = 0; 
    for (int j = 0; j < n; j++) { 
            
        if (freq[nums[j]] > 0) {
            remove_right(freq[nums[j]], nums[j]); 
        }
        freq[nums[j]]++; 
        add_right(freq[nums[j]], nums[j]); 

            
        if (j - i + 1 > k) { 
            remove_right(freq[nums[i]], nums[i]); 
            freq[nums[i]]--; 
            if (freq[nums[i]] > 0) { 
                add_right(freq[nums[i]], nums[i]);
            }
            i++; 
        }

            
        if (j - i + 1 == k) {
            ans.push_back(sum); 
        }
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
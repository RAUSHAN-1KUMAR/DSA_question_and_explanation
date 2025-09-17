/*
You are given an integer array 'nums' consisting of n elements, and an integer k.

Find a contiguous subarray whose length is equal to k that has the maximum average value and return this value. Any answer with a calculation error less than 10-5 will be accepted.
 
Example 1:
    Input: nums = [1,12,-5,-6,50,3], k = 4
    Output: 12.75000
    Explanation: Maximum average is (12 - 5 - 6 + 50) / 4 = 51 / 4 = 12.75

Example 2:  
    Input: nums = [5], k = 1
    Output: 5.00000
*/

/*
Approach:- sliding window(our window is fixed).

Time Complexity:- O(n)
*/

#include<bits/stdc++.h>
using namespace std;

double findMaxAverage(vector<int>& nums, int k) 
{
    int startWindow = 0;
    int endWindow = 0;
    double sumWindow = 0.0;
    double resultSumAvgWindow = INT_MIN; // for negatice sum also

    // finding the sum of first window, 0 to k-1 index
    while(endWindow != k)
    {
        sumWindow += nums[endWindow];
        endWindow++;
    }

    // endwindow is now 4, means k size window has created i.e., from 0 to 3.
    if(sumWindow>resultSumAvgWindow) resultSumAvgWindow = sumWindow;

    while(endWindow < nums.size())
    {
        sumWindow += nums[endWindow++] - nums[startWindow++];
        if(sumWindow>resultSumAvgWindow) resultSumAvgWindow = sumWindow;
    }

    return resultSumAvgWindow/k;

}

int main()
{
    vector<int> arr = {1,12,-5,-6,50,3};
    double ans = findMaxAverage(arr, 4);

    cout << ans << endl;

    return 0;
}
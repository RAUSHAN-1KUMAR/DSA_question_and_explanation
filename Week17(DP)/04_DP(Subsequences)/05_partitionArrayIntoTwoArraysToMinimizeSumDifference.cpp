/* -> 2035 Hard++

You are given an integer array nums of 2 * n integers. You need to partition nums into two arrays of length n to minimize the absolute difference of the sums of the arrays. To partition nums, put each element of nums into one of the two arrays.

Return the minimum possible absolute difference.


Example 1:
    Input: nums = [3,9,7,3]
    Output: 2
    Explanation: One optimal partition is: [3,9] and [7,3].
    The absolute difference between the sums of the arrays is abs((3 + 9) - (7 + 3)) = 2.


Example 2:
    Input: nums = [-36,36]
    Output: 72
    Explanation: One optimal partition is: [-36] and [36].
    The absolute difference between the sums of the arrays is abs((-36) - (36)) = 72.


Example 3:
    Input: nums = [2,-1,0,4,-2,-9]
    Output: 0
    Explanation: One optimal partition is: [2,4,-9] and [-1,0,-2].
    The absolute difference between the sums of the arrays is abs((2 + 4 + -9) - (-1 + 0 + -2)) = 0.
*/


/*
Approach:- meet in the middle technique
    Logic:-
        -- Let say we have:--- sum1(n)+sum2(n) = totalSum(N)
                            => sum2 = totalSum-sum1 ------(i)

                    and we have to find abs(sum2-sum1), which will >=0

                            => abs(totalSum - 2*sum1) >= 0:  from(i)
                            => totalSum >= 2*sum1
                            => totalSum/2 >= sum1

        -- so ultimately we have find sum1 or sum2 in such a way that it should be as close to total/2.

        -- and we got to know that, we have to check for the availability of close sum to total/2 by using (2n)/2 = n elements.

        -- we are bound to find the sum using n elements, it would need some tweaking in meet in the middle technique 
            - we will generate the sum and also track the no. of elments used to generate that sum   

TC:- O(2^n * log(2^n)) = O(n*2^n)
SC:- O(2^n)

// there is one more approach of this question -> see next question
*/


#include<bits/stdc++.h>
using namespace std;


void calculateSum(vector<int> &nums, vector<vector<int>> &left, vector<vector<int>> &right, int n)
{
    int subset_ct = (1<<n);

    for(int mask=0 ; mask<subset_ct ; mask++)
    {
        int forLeft=0;
        int forRight=0;
        int size=0;

        for(int i=0 ; i<n ; i++)
        {
            if(mask & (1<<i))
            {
                size++;
                forLeft += nums[i];
                forRight += nums[i+n];
            }
        }

        left[size].push_back(forLeft);
        right[size].push_back(forRight);
    }
}


int minimumDifference(vector<int> &nums)
{   
    int N=nums.size();
    int res=0, totalSum=0;

    totalSum = accumulate(nums.begin(), nums.end(), 0);

    int n = N/2;

    // change1, for the specific size we are gonna store the vector of sum, that's why array length is not 2^n, its only n+1
    vector<vector<int>> left(n+1);
    vector<vector<int>> right(n+1);

    calculateSum(nums, left, right, n);

    // egde cases, 
    // right->0 and left->n = left[n][0] i.e., left sum nth wala ele
    // left->0 and right->n = right[n][0] i.e., right sum nth wala ele
    res = min(abs(totalSum-2*(left[n][0] + 0)), abs(totalSum-2*(0 + right[n][0])));


    // now baaki ke combination: left[size] and right[n-size] = n elements
    // so to find (a+b)=totalSum/2, we will pick a from left and then we will find b in right such that a+b as close to totalSum/2, it means now we are going to apply meet in the middle for totalSum/2
    for(int size=0 ; size<=n ; size++){
        sort(right[size].begin(), right[size].end());
    }

    for(int leftSize=1 ; leftSize<n ; ++leftSize) // already considered size=0/n as edge case
    {
        for(auto &a : left[leftSize])
        {
            int b = (totalSum-2*a)/2;
            int rightSize = n-leftSize;//{leftsize+rightsize = n}

            // searching as close as possible for b in right array
            auto &v = right[rightSize];
            auto itr = lower_bound(v.begin(), v.end(), b); // binarySearch

            // have to compare between two difference because lowerbound point to equal or greater, so what if lower is close to b
            if(itr!=v.end())// for equal or greater
            {
                res = min(res, abs(totalSum-2*(a+(*itr))));
            }

            if(itr!=v.begin())// for lower 
            {
                auto it = itr; // it's better to take a different pointer
                it--; // ek kam krdo
                res = min(res, abs(totalSum-2*(a+(*it))));
            }
        }
    }

    return res;
}


int main()
{
    vector<int> nums = {76,8,45,20,74,84,28,1};
    cout << minimumDifference(nums) << endl;
    return 0;
}


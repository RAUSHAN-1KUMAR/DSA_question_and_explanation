/* -> 503

Given a circular integer array nums (i.e., the next element of nums[nums.length - 1] is nums[0]), return the next greater number for every element in nums.

The next greater number of a number x is the first greater number to its traversing-order next in the array, which means you could search circularly to find its next greater number. If it doesn't exist, return -1 for this number.

 
Example 1:
    Input: nums = [1,2,1]
    Output: [2,-1,2]
    Explanation: The first 1's next greater number is 2; 
    The number 2 can't find next greater number. 
    The second 1's next greater number needs to search circularly, which is also 2.


Example 2:
    Input: nums = [1,2,3,4,3]
    Output: [2,3,4,-1,4]

*/

/*
Approach:-
    -- approach is same as we did in nextGreaterElementI, the only difference is that is use modulo if i exceeds n, and then loop will run 2*n-1 times at max.

TC:- (2n + 2n) => O(4n)
SC:- O(2n)
*/

#include<bits/stdc++.h>
using namespace std;

vector<int> nextGreaterElements(vector<int>& nums)
{
    int n=nums.size();

    stack<int> st;
    vector<int> nextGreater(n, -1);

    for(int i=0 ; i<2*n-1 ; i++)
    {
        while(!st.empty() && nums[i%n]>nums[st.top()%n])
        {
            nextGreater[st.top()%n] = nums[i%n];
            st.pop();
        }
        st.push(i);
    }

    return nextGreater;
}

int main()
{
    vector<int> nums = {1,2,3,4,3};

    vector<int> ans  = nextGreaterElements(nums) ;

    for(auto num:ans)
        cout << num << " ";
    cout << endl;
    
    return 0;
}
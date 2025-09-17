/* -> 496

The next greater element of some element x in an array is the first greater element that is to the right of x in the same array.

You are given two distinct 0-indexed integer arrays nums1 and nums2, where nums1 is a subset of nums2.

For each 0 <= i < nums1.length, find the index j such that nums1[i] == nums2[j] and determine the next greater element of nums2[j] in nums2. If there is no next greater element, then the answer for this query is -1.

Return an array ans of length nums1.length such that ans[i] is the next greater element as described above.

 
Example 1:
    Input: nums1 = [4,1,2], nums2 = [1,3,4,2]
    Output: [-1,3,-1]
    Explanation: The next greater element for each value of nums1 is as follows:
    - 4 is underlined in nums2 = [1,3,4,2]. There is no next greater element, so the answer is -1.
    - 1 is underlined in nums2 = [1,3,4,2]. The next greater element is 3.
    - 2 is underlined in nums2 = [1,3,4,2]. There is no next greater element, so the answer is -1.

Example 2:
    Input: nums1 = [2,4], nums2 = [1,2,3,4]
    Output: [3,-1]
    Explanation: The next greater element for each value of nums1 is as follows:
    - 2 is underlined in nums2 = [1,2,3,4]. The next greater element is 3.
    - 4 is underlined in nums2 = [1,2,3,4]. There is no next greater element, so the answer is -1.

*/

/*
Approach:
    -- used stack to store the next greater element
    -- we solve it from last to first index

TC:- O(n + m)

lets solve it from first index to last -> see next solution
*/

#include<bits/stdc++.h>
using namespace std;

vector<int> nextGreaterElement(vector<int>& nums1, vector<int>& nums2)
{
    stack<int> st;
    st.push(-1);

    unordered_map<int,int> mp;
    int i=nums2.size()-1;
    while (i>=0) //-> O(n)
    {
        int ele = nums2[i];

        if(st.top()>ele)
        {
            mp[ele] = st.top();
            st.push(ele);
        }
        else
        {
            while(st.top()!=-1 && st.top()<=ele)//-> O(m)
                st.pop();

            mp[ele]=st.top();
            st.push(ele);
        }
        i--;
    }
    
    // now forming answer with repect to nums1
    vector<int> ans(nums1.size());
    for(int i=0 ; i<nums1.size() ; i++)
    {
        ans[i] = mp[nums1[i]];
    }

    return ans;
}

int main()
{
    vector<int> nums1 = {2,4};
    vector<int> nums2 = {1,2,3,4};

    for(int num:nextGreaterElement(nums1, nums2))
    {
        cout << num << " ";
    }
    cout << endl;

    return 0;
}


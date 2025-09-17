/* -> 239

You are given an array of integers nums, there is a sliding window of size k which is moving from the very left of the array to the very right. You can only see the k numbers in the window. Each time the sliding window moves right by one position.

Return the max sliding window.

 

Example 1:
Input: nums = [1,3,-1,-3,5,3,6,7], k = 3
Output: [3,3,5,5,6,7]
Explanation: 
Window position                Max
---------------               -----
[1  3  -1] -3  5  3  6  7       3
 1 [3  -1  -3] 5  3  6  7       3
 1  3 [-1  -3  5] 3  6  7       5
 1  3  -1 [-3  5  3] 6  7       5
 1  3  -1  -3 [5  3  6] 7       6
 1  3  -1  -3  5 [3  6  7]      7

Example 2:
Input: nums = [1], k = 1
Output: [1]
*/

/*
Appraoch:- deque
    -- hame deque m index store krengen.
    -- ager deque empty h to push kerdo, ager empty nhi h to check kro ki kya deque ke back p pada element anne wale element se chota h, ager h to pop_back kerte jao, ager deque ek back p pada element anne wale element se bada h to jo new index h usko push_back kerdo(chote element ko push kyon ker rhe, kyunki ho sakta h ki aaga aane wale window ke liye ye bada element ho). aur her window ke baad jo deque ke front h wo uss window ka max element h
*/

#include<iostream>
#include<vector>
#include<deque>
using namespace std;

vector<int> maxSlidingWindow(vector<int>& nums, int k)
{
    vector<int> ans;
    deque<int> dq;

    // first window ko process kro
    for(int i=0 ; i<k ; i++)
    {
        int element = nums[i];

        // jitne bhi deque ke ander piche se chotte element h aane wale new element ke comparison m to usko remove kerdo
        while(!dq.empty() && element > nums[dq.back()]){
            dq.pop_back();
        }

        // now insert kardo-> ya to jab deque empty ho gya hoga ya element chota h deque ke back se
        dq.push_back(i);
    }


    // remaining window ka process
    for(int i=k ; i<nums.size() ; i++)
    {
        // jo window bna h uske liye answer store kerlo
        ans.push_back(nums[dq.front()]);

        // removal of two type
        
        // 1. outofwindow wale
        if(!dq.empty() && i-dq.front() >= k){
            dq.pop_front();
        }

        // 2. chote element
        int element = nums[i];
        while(!dq.empty() && element > nums[dq.back()]){
            dq.pop_back();
        }


        // addition
        dq.push_back(i);
    }


    // last window ka answer
    ans.push_back(nums[dq.front()]);

    return ans;
}


int main()
{
    vector<int> nums = {1,3,-1,-3,5,3,6,7};
    int k = 3;

    vector<int> ans = maxSlidingWindow(nums, k);

    for(int num:ans)
    {
        cout << num << " ";
    }
    cout << endl;

    return 0;
}



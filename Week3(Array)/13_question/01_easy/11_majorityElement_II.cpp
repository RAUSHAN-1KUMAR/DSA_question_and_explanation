/* -> 229

Given an integer array of size n, find all elements that appear more than ⌊ n/3 ⌋ times.

 

Example 1:
    Input: nums = [3,2,3]
    Output: [3]

Example 2:
    Input: nums = [1]
    Output: [1]

Example 3:
    Input: nums = [1,2]
    Output: [1,2]
*/

/*
Approach:- kind of similar to majorityElement_I
*/

#include<bits/stdc++.h>
using namespace std;

vector<int> majorityElement(vector<int> &nums)
{
    int ele1=INT_MIN, cnt1=0, ele2=INT_MIN, cnt2=0;
    for(int i=0 ; i<nums.size() ; i++){
        if(cnt1==0 && nums[i]!=ele2){
            cnt1=1;
            ele1=nums[i];
        }
        else if(cnt2==0 && nums[i]!=ele1){
            cnt2=1;
            ele2=nums[i];
        }
        else if(ele1==nums[i]) cnt1++;
        else if(ele2==nums[i]) cnt2++;
        else{
            cnt1--;
            cnt2--;
        }
    }

    // lets verify
    vector<int> ans;
    cnt1=0, cnt2=0;
    for(int i=0 ; i<nums.size(); i++){
        if(ele1==nums[i]) cnt1++;
        else if(ele2==nums[i]) cnt2++;
    }

    int mini=(int)(nums.size()/3)+1;
    if(cnt1>=mini) ans.push_back(ele1);
    if(cnt2>=mini) ans.push_back(ele2);

    sort(ans.begin(), ans.end());

    return ans;
}


int main()
{
    vector<int> nums={3,3,3,3,2,2,4,4,4,4};
    for(int num:majorityElement(nums)){
        cout << num << " ";
    }
    cout << endl;
    return 0;
}


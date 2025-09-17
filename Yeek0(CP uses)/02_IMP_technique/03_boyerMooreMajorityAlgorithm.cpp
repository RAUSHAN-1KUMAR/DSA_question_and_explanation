
/*
The Boyer-Moore voting algorithm is used to find the mojority element among the given elements that have more than N/2 occurences. This works perfectly fine for finding the majority element which takes 2 traversals over the given elements, which works in O(N) time complexity and O(1) space complexity.

The intuition behind this algorithm is the element occuring more than N/2 times will definately overpass other elements

Example:
    Input: {1,1,1,3,3,3,1,3,3}
    Output: 3
*/

#include<bits/stdc++.h>
using namespace std;

int votingAlgo(vector<int> &nums)
{
    int n=nums.size();

    int majEle=nums[0];
    int cnt=0;

    for(int &num:nums){
        if(num==majEle){
            cnt++;
        }else{
            cnt--;
        }

        if(cnt==0){
            majEle=num;
            cnt=1;
        }
    }

    return majEle;     // return the majority element.
}


int main()
{
    vector<int> nums = {2,3,4,3,3};

    cout << votingAlgo(nums) << endl;

    return 0;
}
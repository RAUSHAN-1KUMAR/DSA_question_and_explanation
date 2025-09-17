/*
implementation of upper bound-> we will return index
*/

#include<bits/stdc++.h> 
#include<algorithm>
using namespace std;

//optimal solution using BS
int upperBound(vector<int> &nums, int k)
{
    int s=0;
    int e=nums.size();

    int ans = nums.size();

    while(s<=e)
    {
        int mid=(s+e)/2;

        if(nums[mid]>k)
        {
            ans=mid;
            e=mid-1;
        }
        else
        {
            s=mid+1;
        }
    }

    return ans;
}

int main()
{
    vector<int> nums = {2,4,4,6,8,10,12};

    int ans = upperBound(nums, 8);

    cout << "At index: " << ans << endl;

    return 0;
}
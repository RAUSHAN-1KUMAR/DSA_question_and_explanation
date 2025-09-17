/* -> 81

Same question as previous one but in this case the elements can be dublicate

Example 1:
Input: nums = [2,5,6,0,0,1,2], target = 0
Output: true

Example 2:
Input: nums = [2,5,6,0,0,1,2], target = 3
Output: false
*/

/*
Appraoch: same as previous, the only difference is that now we can have dublicate elements
*/


#include<iostream>
#include<vector>
using namespace std;


bool search(vector<int> &nums, int target)
{
    int low=0;
    int high=nums.size()-1;

    while (low<=high)
    {
        int mid = (low+high)/2;

        if(nums[mid]==target) 
            return true;

        // ek aur case ko handle kerna padega, if it matches then do this...
        if(nums[mid]==nums[low] && nums[mid]==nums[high])
        {
            high=high-1;
            low=low+1;
            continue;
        }
        

        if(nums[low]<=nums[mid]) //-> left part is sorted
        {
            if(nums[low] <= target && target <= nums[mid])
                high = mid-1;
            else
                low = mid+1;
        }
        else //-> right part is sorted
        {
            if(nums[mid]<=target && target<=nums[high])
                low = mid+1;
            else
                high = mid-1;
        }

    }
    
    return false;
}

int main()
{
    vector<int> v = {1,0,1,1,1};
    int target = 0;

    cout << search(v,target) << endl;
    
    return 0;
}
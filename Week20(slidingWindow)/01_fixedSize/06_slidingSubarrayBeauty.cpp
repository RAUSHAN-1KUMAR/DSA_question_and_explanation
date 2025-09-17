/* -> 2653

Given an integer array nums containing n integers, find the beauty of each subarray of size k.

The beauty of a subarray is the xth smallest integer in the subarray if it is negative, or 0 if there are fewer than x negative integers.

Return an integer array containing n - k + 1 integers, which denote the beauty of the subarrays in order from the first index in the array.

A subarray is a contiguous non-empty sequence of elements within an array.

 

Example 1:
    Input: nums = [1,-1,-3,-2,3], k = 3, x = 2
    Output: [-1,-2,-2]
    Explanation: There are 3 subarrays with size k = 3. 
    The first subarray is [1, -1, -3] and the 2nd smallest negative integer is -1. 
    The second subarray is [-1, -3, -2] and the 2nd smallest negative integer is -2. 
    The third subarray is [-3, -2, 3] and the 2nd smallest negative integer is -2.

Example 2:
    Input: nums = [-1,-2,-3,-4,-5], k = 2, x = 2
    Output: [-1,-2,-3,-4]
    Explanation: There are 4 subarrays with size k = 2.
    For [-1, -2], the 2nd smallest negative integer is -1.
    For [-2, -3], the 2nd smallest negative integer is -2.
    For [-3, -4], the 2nd smallest negative integer is -3.
    For [-4, -5], the 2nd smallest negative integer is -4.

Example 3:
    Input: nums = [-3,1,2,-3,0,-3], k = 2, x = 1
    Output: [-3,0,-3,-3,-3]
    Explanation: There are 5 subarrays with size k = 2.
    For [-3, 1], the 1st smallest negative integer is -3.
    For [1, 2], there is no negative integer so the beauty is 0.
    For [2, -3], the 1st smallest negative integer is -3.
    For [-3, 0], the 1st smallest negative integer is -3.
    For [0, -3], the 1st smallest negative integer is -3.

*/

#include<iostream>
#include<algorithm>
#include<vector>
#include<map>
using namespace std;

vector<int> getSubarrayBeauty(vector<int>& nums, int k, int x) 
{   
    int startWindow=0;
    int endWindow=0;
    int windowSize=k;
    int size=nums.size();

    // we have to find the xth smallest window, that's why i am using ordered map, so that the key will be in ascending order
    int xth = x;
    map<int,int> mp;


    vector<int> ans;

    while(endWindow<size)
    {
        // ager element negative h to uske key pe ++ kerdo
        if(nums[endWindow]<0)
        {
            mp[nums[endWindow]]++;
            xth--;//-> negative mil gya to xth--, kyunki hame xth negative find kerna h
        }


        if(endWindow-startWindow+1==windowSize)
        {
            // ager window size achieve ho gya to kya xth jitna negative number store ho gya h map m, ager haa to xth will be less than or equal to 0 kyunki map m negative number mark kerne ke baad xth-- ker rhe h
            if(xth<=0)
            {
                // to get the xth negative number we are iterating to our map till the x(times) become negative or equal to zero
                int times = x;
                for(auto it=mp.begin(); it!=mp.end() ; it++)
                {
                    int secondData = it->second;
                    times -= secondData;
                    if(times<=0)
                    {
                        ans.push_back(it->first);
                        break;
                    }
                }
            }
            else
            { 
                // window size achieve hone ke baad bhi ager xth jitna negative number store nhi hua h to uss window size ke liye zero(0) push kerdo
                ans.push_back(0);     
            }


            // next time ab window aage badhega aur hame k size window maintain kerna h 
            if(nums[startWindow]<0)
            {
                // startWindow aage badhne se pehle uske occurence ko mao se hatao
                mp[nums[startWindow]]--;

                // ager wo zero ho gya to puri tarah se hatoa
                if(mp[nums[startWindow]]==0)
                {
                    mp.erase(mp[nums[startWindow]]);
                }

                // ek nagative ka occurence hat chika to xth increase hoga kyunki xth number of negative numbers ko bta rha h
                xth++;
            }

            startWindow++;
        }

        endWindow++;
    }

    return ans;
}

int main()
{
    vector<int> nums = {-3,1,2,-3,-2,-3};
    int k=3;
    int x=2;

    vector<int> ans = getSubarrayBeauty(nums, k , x);
    for(int num:ans){
        cout << num << " ";
    }

    return 0;
}
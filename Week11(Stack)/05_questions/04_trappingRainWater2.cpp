/* -> 42

Given n non-negative integers representing an elevation map where the width of each bar is 1, compute how much water it can trap after raining.


Example 1:
    Input: height = [0,1,0,2,1,0,1,3,2,1,2,1]
    Output: 6
    Explanation: The above elevation map (black section) is represented by array [0,1,0,2,1,0,1,3,2,1,2,1]. In this case, 6 units of rain water (blue section) are being trapped.


Example 2:
    Input: height = [4,2,0,3,2,5]
    Output: 9
*/

/*
Approach:- using two pointer + leftMax and rightMax variable
    -- two pointer means we have two options
        i) both pointer will be adjacent
        ii) one pointer at start and one at end -> (this will work)

    -- previously we were taking right max and left max and later one we were taking smallerOfThem - height[i], we we can see that we just need the smaller one from both of them. SO, that's what we are going to do that
    -- we will have one pointer at end and other at start and we are going to move the smallest of them

TC: O(n)
SC: O(1)
*/

#include<bits/stdc++.h>
using namespace std;


int trap(vector<int>& height)
{
    int n = height.size();
    int lMax=0, rMax=0, left=0, right=n-1;

    int total = 0;
    while(left<right)
    {
        if(height[left]<=height[right])// if left is smaller, proceed with the left
        {
            if(lMax > height[left])
                total += lMax-height[left]; // as height[left] was smaller than height[right], so water water will be filled with respect to height[left], if lMax is there to hold the water i.e., lMax > height[left]
            else
                lMax = height[left];

            left++;
        }
        else // if right is smaller, proceed with the right
        {
            if(rMax > height[right])
                total += rMax-height[right]; // as height[right] was smaller than height[left], so water water will be filled with respect to height[right], if rMax is there to hold the water i.e., rMax > height[right]
            else    
                rMax = height[right];

            right--;
        }
    }

    return total;
}

int main()
{
    vector<int> height = {4,2,0,3,2,5};

    cout << trap(height) << endl;
    return 0;
}




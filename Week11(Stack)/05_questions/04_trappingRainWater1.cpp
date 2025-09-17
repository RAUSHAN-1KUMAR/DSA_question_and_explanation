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
Approach:- 
    -- we were calculating area via calculating width, so that's why i need set for the unique area, but

    -- instead of calculating area for a width, we can just count the filled height for each calculative index, but for this we are gonna need prev max and next max for each index instead of prevLargest and nextLargest

    -- so prevously we had prevGreatest and nextLargest array, but now we will have prevMax/prefixMax and nextMax/suffixMax array. Or we will not need prevMax, because can calculate prev max using one single variable as we iterating linearly.

    -- so calculating prefixMax and suffixMax would not require stack, we can compare the adjacent element of computed prefixMax and suffixMax

TC:- O(n + n + n) => O(3n)
SC:- O(n) + O(n)

Optimizing SC -> see next solution
*/

#include<bits/stdc++.h>
using namespace std;


int trap(vector<int>& height)
{
    int n = height.size();

    vector<int> prefixMax(n);
    vector<int> suffixMax(n);

    prefixMax[0] = height[0];// initialized prefixMax
    for(int i=1 ; i<n ; i++)// now calculating prefixMax for other index
    {
        prefixMax[i] = max(prefixMax[i-1], height[i]);
    }

    suffixMax[n-1] = height[n-1]; // initialized suffixMax
    for(int i=n-2 ; i>=0 ; i--)
    {
        suffixMax[i] = max(suffixMax[i+1], height[i]);
    }

    // now calculating trapped water
    int waterTrapped = 0;
    for(int i=0 ; i<n ; i++)
    {
        waterTrapped += min(prefixMax[i], suffixMax[i]) - height[i];
    }

    return waterTrapped;
}

int main()
{
    vector<int> height = {3,0,2,1,0,1,3,2,1,2,1};

    cout << trap(height) << endl;
    return 0;
}

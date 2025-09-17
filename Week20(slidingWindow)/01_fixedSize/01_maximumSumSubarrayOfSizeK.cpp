/*
Question:- given an array of size n, and a value k = 3, we have to find the subarray of size k with having sum of its element maximum and we have to return that maximum sum.(subarray will be contigous)
*/

/*
Approach:- So in this question the size of subarrays is fixed(k) means our window is fixed.
*/

#include<iostream>
#include<vector>
#include<algorithm>

using namespace std;

int maximumSubSubarray(vector<int> &arr, int windowSize)
{
    int startWindow = 0;
    int endWindow = 0;
    
    int max=0;
    int sum=0;

    while(endWindow<arr.size())
    {
        sum += arr[endWindow];

        // expansion
        if(endWindow-startWindow+1 < windowSize) 
        {
            endWindow++;
        }
        else if(endWindow-startWindow+1 == windowSize)// mainting the size
        {
            sum > max ? max=sum : max=max;
            sum -= arr[startWindow];
            
            startWindow++;
            endWindow++;
        }
    }

    return max;
}


int main()
{
    vector<int> arr = {2,5,1,8,2,9,1};

    int sum = maximumSubSubarray(arr,3);

    cout << sum << endl;

    return 0;
}
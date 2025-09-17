/*
You are given an array consisting of n integers which denote the position of a stall. You are also given an integer k which denotes the number of aggressive cows. You are given the task of assigning stalls to k cows such that the minimum distance between any two of them is the maximum possible.

The first line of input contains two space-separated integers n and k.
The second line contains n space-separated integers denoting the position of the stalls.


Examples:
    Input: n=5, k=3, stalls = [1 2 4 8 9]
    Output: 3
    Explanation: The first cow can be placed at stalls[0], The second cow can be placed at stalls[2] and The third cow can be placed at stalls[3]. 
    The minimum distance between cows, in this case, is 3, which also is the largest among all possible ways.

    Input: n=5, k=3, stalls = [10 1 2 7 5]
    Output: 4
    Explanation: The first cow can be placed at stalls[0], the second cow can be placed at stalls[1] and the third cow can be placed at stalls[4].
    The minimum distance between cows, in this case, is 4, which also is the largest among all possible ways.
*/

/*
My Approach:- described in notecopy
    -- for first cow, i have looked for its each position on stalls: 0 1 2 3 4...., which is not necessory, as the array will be sorted so the first cow will always will be at index 0(solution is on next question).
*/

#include<iostream>
#include<numeric>
#include<vector>
#include<algorithm>
using namespace std;

// can we place k cows with at least 'sol' distance between them.
bool isPossibleSolution(int n, int k, vector<int> &A, int sol)
{
    for(int i = 0; i<n ; i++) 
    {
        int c = 1;
        int j = i+1;
        int current = A[i];
        while(j<n)
        {
            if(A[j]-current>=sol){
                current = A[j];
                c++;
                if(c==k) return true;
            }
            j++;
        }

    }

    return false;
}

int solve(int n, int k, vector<int> &stolls)
{
    sort(stolls.begin(), stolls.end());

    int start = 0;
    int end = stolls[n-1]; 
    int ans = -1;  

    while(start<=end){
        int mid = start+(end-start)/2;

        if(isPossibleSolution(n,k,stolls,mid)){
            ans = mid;
            start = mid+1;
        }
        else{
            end = mid-1;
        }   
    } 

    return ans;
}

int main()
{
    vector<int> arr = {1,2,4,8,9};
    int n = arr.size();
    int k = 3;

    cout << solve(n,k,arr) << endl;

    return 0;
}

/* The painter's partition problem

Dilpreet wants to paint his dog's home that has n boards with different lengths. the length of ith board is given by arr[i], where arr[] is an array of n integers. He hired k painters for this work and each painters takes 1 unit time to paint 1 unit of the board.
The problem is to find the minimum time to get this job done if all painters start together with the constraint that any painter will only paint continuous boards.


Examples: 
    Input: N = 4, A = {10, 10, 10, 10}, K = 2  
    Output : 20
    Explanation: Here we can divide the boards into 2 equal sized partitions (Painter 1 will paint boards A1 and A2, and Painter 2 will paint boards A3 and A4). So each painter gets 20 units of board and the total time taken is 20. 


    Input: N = 4, A = {10, 20, 30, 40}, K = 2 
    Output : 60
    Explanation: Since there are only 2 painters, therefore divide first 3 boards to painter 1 (A1, A2 and A3) with time = 60, and last board to painter 2 (A4) with time = 40. Therefore total time taken = 60, which is the minimum possible.(Please note the combination A1 and A4 to Painter 1 with time 50, and A2 and A3 to Painter 2 with time 50, will yield a smaller time (50 units). But this cant be considered due to the constraint that a painter cannot paint non-continuos series of boards.)

    Input: N=5, A={5,10,30,20,15}, k=3
    Output: 35
    Explanation: The most optimal way:
    painter 1 allocation : {5,10}
    painter 2 allocation : {30}
    painter 3 allocation : {20,15}
    Job will be done when all painters finish i.e., at time = max(5+10, 30, 20+15) = 35
*/

/*
Approach:- same as book allocation problem/split array into largest sum

Lets do with an another isPossibleSolution(), whose return type is int
*/


#include<bits/stdc++.h>
using namespace std;

bool isPossibleSolution(int A[], int N, int M, int sol)
{
    int totalTime=0;
    int painter=1;

    for(int i=0 ; i<N ; i++)
    {
        if(A[i]>sol) return false;// important condition

        if(totalTime+A[i]>sol)
        {
            painter++;
            totalTime=A[i];
            if(painter>M) return false;
        }
        else
        {
            totalTime+=A[i];
        }
    }

    return true;
}

long long minTime(int A[], int N, int M) 
{
    int start=1;
    int end=accumulate(A, A+N, 0);

    int ans = -1;

    while(start<=end)
    {
        int mid = (start+end)/2;

        if(isPossibleSolution(A, N, M, mid))
        {
            ans=mid;
            end=mid-1;
        }
        else
            start=mid+1;
    }

    return ans;
}


int main()
{
    int arr[] = {5,10,30,20,15};
    int n = sizeof(arr)/sizeof(arr[0]);
    int k = 3;

    cout << minTime(arr,n,k) << endl;

    return 0;
}



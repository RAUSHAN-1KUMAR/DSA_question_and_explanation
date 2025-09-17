/* Question

Given a set of n integers(n<=40) and each value is at most 10^12, determine the maximum Sum subset having sum<=S, where S<=10^18

Example:  
    Input  : set[] = {45, 34, 4, 12, 5, 2} and S = 42
    Output : 41
    Maximum possible subset sum is 41 which can be 
    obtained by summing 34, 5 and 2.

    Input  : Set[] = {3, 34, 4, 12, 5, 2} and S = 10
    Output : 10
    Maximum possible subset sum is 10 which can be 
    obtained by summing 2, 3 and 5.
*/


/*
Approaches:-

1. Brute Force:- 
    - A Brute Force approach to solve this problem would be find all possible subset sums of N integers and check if it is less than or equal S and keep track of such a subset with maximum sum. 
        -- The time complexity using this approach would be O(2^n) and n is at most 40. 2^40 will be quite large and hence we need to find more optimal approach.

2. Meet in the middle technique:- 
    - Meet in the middle is a search technique which is used when the input is small but not as small that brute force can be used. Like divide and conquer it splits the problem into two, solves them individually and then merge them. But we can’t apply meet in the middle like divide and conquer because we don’t have the same structure as the original problem.
        - Split the set of integers into 2 subsets say A and B. A having first n/2 integers and B having rest.

        - Find all possible subset sums of integers in set A and store in an array X. Similarly calculate all possible subset sums of integers in set B and store in array Y. Hence, Size of each of the array X and Y will be at most 2^(n/2).

        - Now merge these 2 subproblems. Find combinations from array X and Y such that their sum is less than or equal to S. 
            i) One way to do that is simply iterate over all elements of array Y for each element of array X to check the existence of such a combination. This will take O((2^(n/2))^2) which is equivalent to O(2^n). -> bad approach

            ii) To make it less complex, first sort array Y and then iterate over each element of X and for each element 'x' in X use binary search to find maximum element 'y' in Y such that x + y <= S.
                - Binary search here helps in reducing complexity from 2^n to 2^(n/2)log(2^n/2) which is equivalent to 2^(n/2)*n.
                
        - Thus our final running time is O(n * 2^(n/2)).

    - So in this approach, the devision of array takes place only one time.

    --What if question says you to find the no. of subset having sum exactly S:- It would be more easy, dono half ke sum find kro and for a perticular 'x' of A, find 'S-x' in y using BS, if we got it then count++

In this question it has said to find the sum<=S. So, there can be many variations of this question i.e., abs(S-sum)->0 or count all possible sum whose sum==S, etc..
*/

#include<bits/stdc++.h>
using namespace std;

void printArray(vector<int> &nums);

// bit manipulation way to find the all possible n length subset
void calculateSum(vector<int> &arr, vector<int> &halfes, int n, int offset)  
{
    int subset_ct = (1<<n);//: 1<<n => 1*2^n

    // we have to run the loop till total no. of subset, for all possible subset combination
    for(int i=0 ; i<subset_ct ; i++)
    {
        // let say i(76) -> 01001100(for n==8, 76th combination), then j will only add those elements from arr where bit of i is 1
        int sum=0;

        for(int j=0 ; j<n ; j++) // this loop iterates to arr array for each value of i
        {
            // i&(1<<j): checks whether the jth bit of i is 1 or 0
            if(i&(1<<j))
                sum+=arr[j+offset];
        }
        
        halfes.push_back(sum);
    }
}


int solveSubsetSum(vector<int> &arr, int &n, int &Sum)
{
    // computer all sums of fisrt and second halves
    vector<int> firstHalfSum;
    vector<int> secondHalfSum;

    calculateSum(arr, firstHalfSum, n/2, 0);
    calculateSum(arr, secondHalfSum, n-n/2, n/2);

    // sort one of them
    sort(secondHalfSum.begin(), secondHalfSum.end());

    // printArray(firstHalfSum);
    // printArray(secondHalfSum);


    // now for x in firstHalfSum, find y in such that x+y reach close to S
    int ans = INT_MIN;
    for(int i=0 ; i<firstHalfSum.size(); i++)
    {
        int x = firstHalfSum[i];

        int y = Sum-x; // is y ke liye index find kro

        // finding lowerBound of y=S-x, i.e., y se equal wala number ya phir just bada wala number
        int LB = lower_bound(secondHalfSum.begin(), secondHalfSum.end(), y) - secondHalfSum.begin();

        // if we don't get y, it will point to secondHalfSum.end()
        if(LB==secondHalfSum.size() || (secondHalfSum[LB]!=y && LB!=0))
            LB--;
    
        int gotTheSum = x + secondHalfSum[LB];// x + y(LB) 

        if(gotTheSum>ans && gotTheSum<Sum)
            ans = gotTheSum;
    }

    return ans;
}


int main()
{
    vector<int> arr = {7,-9,15,-2};
    int n = arr.size();
    int Sum = -5;

    cout << solveSubsetSum(arr, n, Sum) << endl;

    return 0;
}


void printArray(vector<int> &nums)
{
    cout << endl;
    for(auto num:nums)
        cout << num << " ";

    cout << endl;
}


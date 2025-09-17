/* To allocate minimum no. of pages.

You have N books, each with A[i] number of pages. M students need to be allocated contiguous books, with each student getting at least one book.In each permutation, one of the M students will be allocated the maximum number of pages. Out of all the permutations, the goal is to find the permutation where the sum of maximum number of pages in a book allotted to a student should be minimum, out of all possible permutations.

Each book will be allocated to exactly one student. Each student has to be allocated at least one book.

Note: Return -1 if a valid assignment is not possible, and allotment should be in contiguous order (see the explanation for better understanding).


Examples:
    Input: N = 4, A[] = {12,34,67,90}, M = 2
    Output:113
    Explanation:Allocation can be done in following ways:
    {12} and {34, 67, 90} Maximum Pages = 191
    {12, 34} and {67, 90} Maximum Pages = 157
    {12, 34, 67} and {90} Maximum Pages = 113.
    Therefore, the minimum of these cases is 113 which is selected as the output

    Input: N = 3, A[] = {15,17,20}, M = 2
    Output:32
    Explanation: Allocation is done as
    {15,17} and {20} Mazimum pages = 32
    {15} and {17,20} Maximum pages = 37
*/

/*
Approach:- discribed in notecopy

Note:- Question of Type: (Search space + predicate function)
    -- predicate function are those function that returns a boolean value, used to make decisions in algorithm. Often acting as conditions to filter or evaluate elements in a data structure.

New:-
    -- accumulate() function:- sums up all elements in the vector starting from 0 (initial value) and using the default addition operation.
*/

#include<iostream>
#include<numeric>
using namespace std;

bool isPossibleSolution(int A[], int N, int M, int sol)
{
    int pageSum = 0;
    int c = 1;

    for(int i=0 ; i<N ; i++)
    {
        if(A[i]>sol) return false;//-> important condition

        if(pageSum+A[i] > sol)
        {
            c++;
            pageSum = A[i];
            if(c>M) return false;
        }
        else{
            pageSum += A[i];
        }
    }

    return true;
}

int findPages(int A[], int N, int M)
{
    if(M>N) return -1;

    int start = 0;
    int end = accumulate(A, A+N, 0);
    int ans = -1;

    while(start<=end)
    {
        int mid = (start+end)/2;

        if(isPossibleSolution(A,N,M,mid)){
            ans = mid;
            end = mid-1;
        }
        else{
            start = mid+1;
        }
    }

    return ans;
}

int main()
{
    int arr[] = {12,34,67,90};
    int n = sizeof(arr)/sizeof(arr[0]);
    int m = 3;

    cout << findPages(arr,n,m) << endl;

    return 0;
}


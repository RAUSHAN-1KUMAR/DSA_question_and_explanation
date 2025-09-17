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
Approach:- apply BS in search space of max(pages[]) to sum(pagess[])

TC:- O(nlogn)
*/

#include<bits/stdc++.h>
using namespace std;

// Better approach
int countStudents(vector<int> &pages, int p)
{
    int totalPages=0;
    int count=1;
    for(int num:pages)
    {
        if(totalPages+num > p)
        {
            count++;
            totalPages=num;// totalPages = num: kerna h naki 0
        }
        else
        {
            totalPages += num;
        }
    }

    return count;
}

int findPages(vector<int> &pages, int n, int m)
{
    if(m>n) return -1;

    int start = *max_element(pages.begin(), pages.end());
    int end = accumulate(pages.begin(), pages.end(), 0);

    int ans = -1;

    while(start<=end)
    {
        int mid = (start + end)/2;

        if(countStudents(pages,mid)>m)
        {
            start=mid+1;
        }
        else
        {
            ans = mid;
            end = mid-1;
        }
    }

    return ans;
}

int main()
{
    vector<int> pages = {12,34,67,90};
    int n = pages.size();
    int m = 2;

    cout << findPages(pages,n,m) << endl;

    return 0;
}


/* count derangements => permutations such that no element appears in its original position

A Derangement is a permutation of n elements, such that no element appears in its original position. For example, a derangement of {0, 1, 2, 3} is {2, 3, 1, 0}.
Given a number n, find the total number of Derangements of a set of n elements.


Examples : 
    Input: n = 2
    Output: 1
    For two elements say {0, 1}, there is only one 
    possible derangement {1, 0}

    Input: n = 3
    Output: 2
    For three elements say {0, 1, 2}, there are two 
    possible derangements {2, 0, 1} and {1, 2, 0}

    Input: n = 4
    Output: 9
    For four elements say {0, 1, 2, 3}, there are 9
    possible derangements {1, 0, 3, 2} {1, 2, 3, 0}
    {1, 3, 0, 2}, {2, 3, 0, 1}, {2, 0, 3, 1}, {2, 3,
    1, 0}, {3, 0, 1, 2}, {3, 2, 0, 1} and {3, 2, 1, 0}
*/

/*
Approach:- full observation + logical based(just like fibonacci series i.e., depend on previous value)
*/ 

#include<iostream>
#include<vector> 
#include<algorithm>
using namespace std;

int countDer(int n)
{
    // base case;
    if(n==1) return 0;
    if(n==2) return 1;

    //RE
    int ans = (n-1)*(countDer(n-1)+countDer(n-2));

    return ans;
}

int main()
{
    int n = 4;

    cout << countDer(n) << endl;

    return 0;
}
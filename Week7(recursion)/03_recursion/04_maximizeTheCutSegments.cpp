/* Exploring all possible ways

GFG

Given an integer N denoting the Length of a line segment. You need to cut the line segment in such a way that the cut length of a line segment each time is either x , y or z. Here x, y, and z are integers.
After performing all the cut operations, your total number of cut segments must be maximum.

Note: if no segment can be cut then return 0.

Example 1:
Input: N = 4, x = 2, y = 1, z = 1
Output: 4
Explanation: Total length is 4, and the cut lengths are 2, 1 and 1.  We can make maximum 4 segments each of length 1.

Example 2:
Input: N = 5, x = 5, y = 3, z = 2
Output: 2
Explanation: Here total length is 5, and the cut lengths are 5, 3 and 2. We can make two segments of lengths 3 and 2.

*/

/*
Note:- Time complexity will be very large, so we will solve it usind DP later.
*/


#include<iostream>
#include<vector>
#include<climits>
#include<algorithm>
using namespace std;

int solve(int n, int x, int y, int z)
{
    //base case
    if(n==0) return 0;
    if(n<0) return INT_MIN;

    //option1: maine x length ka 1 segment cut ker liya h baaki recursion dekh lega
    int option1 = 1 + solve(n-x,x,y,z);

    //option2: maine y length ka 1 segment cut ker liya h baaki recursion dekh lega
    int option2 = 1 + solve(n-y,x,y,z);

    //option3: maine z length ka 1 segment cut ker liya h baaki recursion dekh lega
    int option3 = 1 + solve(n-z,x,y,z);

    int finalAns = max(option1, max(option2,option3));

    return finalAns;
}

int maximizeTheCuts(int n, int x, int y, int z)
{
    int ans = solve(n,x,y,z);

    return ans<0 ? 0 : ans;
}


int main()
{
    cout << maximizeTheCuts(6,2,3,6) << endl;
    return 0;
}
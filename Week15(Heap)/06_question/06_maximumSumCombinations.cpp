/* interviewBit

Given two equally sized 1-D arrays A, B containing N integers each

A sum combination is made by adding one element from array A and another element from array B

RETURN the maximum k valid Sum combinations from all the possible sum combinations


Input 1:
 A = [3, 2]
 B = [1, 4]
 K = 2
Output 1: [7, 6]

Input 2:
 A = [1, 4, 2, 3]
 B = [2, 5, 1, 6]
 K = 4
Output 1: [10, 9, 9, 8]
*/

/*
Approach:
    -- saare combination ka sum ko heap m push kero k limit tak and then ek ek kerke top se compare kerke push

Optimal Solution:- next solution
*/

#include<bits/stdc++.h>
using namespace std;

vector<int> solve(vector<int> &A, vector<int> &B, int K)
{
    priority_queue<int, vector<int>, greater<int> > pq;

    for(int i=0 ; i<A.size() ; i++)
    {
        for(int j=0; j<B.size() ; j++)
        {
            pq.push(A[i]+B[j]);
            if(pq.size()>K) pq.pop();
        }
    }

    vector<int> ans;
    while(!pq.empty() && K--)
    {
        ans.push_back(pq.top());
        pq.pop();
    }

    reverse(ans.begin(), ans.end());

    return ans;
}

int main()
{
    vector<int> A = {1,4,2,3};
    vector<int> B = {2,5,1,6};
    int K = 4;

    for(int &num:solve(A, B, K))
    {
        cout << num << " ";
    }
    cout << endl;

    return 0;
}
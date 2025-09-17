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
Approach: Optimal approach
    -- we have sorted our arrays in decending order then only we can optimise it, Otherwise we can't
*/

#include<bits/stdc++.h>
using namespace std;

vector<int> solve(vector<int> &A, vector<int> &B, int K)
{
    // sorting in descending order
    sort(A.begin(), A.end(), greater<int>());
    sort(B.begin(), B.end(), greater<int>());

    priority_queue<int, vector<int>, greater<int>> pq;

    int i = 0 , j = 0;

    // taking first K element
    int n = A.size();
    while(pq.size() < K)
    {
        pq.push(A[i] + B[j]);
        j++;
    }

    while(i < n)
    {
        //if j went to last or if sum of digits is less than the min value in heap then incremnent i and j will go to zero, becuase if j stays there then we are confirm that if jth+(prev_ith) sum is less than top then j+1 will also, So j=0 means lets start the new combination with i++;
        if(j == n || A[i] + B[j] < pq.top())
        { 
            i++;
            j = 0;

            // if sum of A[i] and with B[0](largest number in B) is less then top then there exist no combination further
            if(i < n && pq.top() >= A[i] + B[j]) // j is zero
                break; 
        }
        else{
            pq.pop(); // if sum of digits is greater then pop smallest value from q and add the new sum (poppin to maintain window size C)
            pq.push(A[i] + B[j]);
            j++;
        }
    }


    vector<int>res;
    while(!pq.empty())
    {
        res.push_back(pq.top());
        pq.pop();
    }

    reverse(res.begin(), res.end()); // reverse to get answer in decreasing order

    return res;
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
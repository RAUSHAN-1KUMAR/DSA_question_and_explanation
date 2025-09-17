/* GFG

Given a row-wise sorted matrix where the number of rows and columns is always odd, find the median of the matrix.

Examples:
    Input: mat = [[1, 3, 5],
                  [2, 6, 9],
                  [3, 6, 9]]
    Output: 5
    Explanation: Sorting matrix elements gives us {1,2,3,3,5,6,6,9,9}. Hence, 5 is median. 

    Input: mat = [[1],
                  [2],
                  [3]]
    Output: 2
    Explanation: Sorting matrix elements gives us {1,2,3}. Hence, 2 is median

    Input: mat = [[3],
                  [5],
                  [8]]
    Output: 5
    Explanation: Sorting matrix elements gives us {3,5,8}. Hence, 5 is median. 
*/

/*
Approach:- BS on search space
    -- given question asks us to find the first element who is greater than size(n*m)/2 number of elements of given matrix
    -- so first we need to figure out how many numbers which is <= element for each element, then we can find which is the first element who is greater then size/2 number of given elements in matrix
    -- our search space will be the min and max element of given matrix and whenever we get a mid, we will find how many numbers <= mid, and then we will move our BS accordingly

TC:- log(m*n)*m*(logn)
*/

#include<bits/stdc++.h>
using namespace std;

int upperBound(vector<int> &arr, int x, int n) {
    int low = 0, high = n - 1;
    int ans = n;

    while (low <= high) {
        int mid = (low + high) / 2;
        // maybe an answer
        if (arr[mid] > x) {
            ans = mid;
            //look for smaller index on the left
            high = mid - 1;
        }
        else {
            low = mid + 1; // look on the right
        }
    }

    return ans;
}

int countSmallEqual(vector<vector<int>> &matrix, int m, int n, int x) 
{
    int cnt = 0;
    for (int i = 0; i < m; i++) // on each row
    {
        // since row is sorted, so we can apply upperbound to count nu. of elments <= x on each row
        cnt += upperBound(matrix[i], x, n);
    }

    return cnt;
}

int median(vector<vector<int>> &matrix) 
{
    int n=matrix.size();
    int m=matrix[0].size();

    //assigning search spaces
    int low = INT_MAX, high = INT_MIN;
    for (int i = 0; i < m; i++) 
    {
        low = min(low, matrix[i][0]);
        high = max(high, matrix[i][n - 1]);
    }

    int req = (n * m)/2;//size/2: this will help to move our BS left or right

    while (low <= high) 
    {
        int mid = (low + high) / 2;

        // counting no. elemnts which are <= of that perticular element(mid)
        int smallestEqual = countSmallEqual(matrix, m, n, mid);

        // BS movement
        if (smallestEqual <= req) 
            low = mid + 1;
        else 
            high = mid - 1;
    }

    return low;
}

int main()
{
    vector<vector<int>> mat = {
        {1,3,5},
        {2,6,9},
        {3,6,9}
    };

    int ans = median(mat);

    cout << ans << endl;

    return 0;
}
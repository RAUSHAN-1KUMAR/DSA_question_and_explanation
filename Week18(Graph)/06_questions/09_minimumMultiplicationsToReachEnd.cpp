/* GFG

Given start, end and an array arr of n numbers. At each step, start is multiplied with any number in the array and then mod operation with 100000 is done to get the new start.

Your task is to find the minimum steps in which end can be achieved starting from start. If it is not possible to reach end, then return -1.

Example 1:
    Input: arr[] = {2, 5, 7} start = 3, end = 30
    Output: 2
    Explanation:
    Step 1: 3*2 = 6 % 100000 = 6
    Step 2: 6*5 = 30 % 100000 = 30


Example 2:
    Input: arr[] = {3, 4, 65} start = 7, end = 66175
    Output: 4
    Explanation:
    Step 1: 7*3 = 21 % 100000 = 21
    Step 2: 21*3 = 63 % 100000 = 63
    Step 3: 63*65 = 4095 % 100000 = 4095
    Step 4: 4095*65 = 266175 % 100000 = 66175
*/

/*
Approach:-
    -- i just applied dijkstra algo without using dist array, which was a mistake and it gave TLE
    -- apply dijkstra algo with dist array, we can use only queue as records will be already in increasing order
*/

#include <bits/stdc++.h>
using namespace std;

const int mod = 1e5;

int minimumMultiplications(vector<int> &arr, int start, int end)
{
    // edge case
    if(start==end) return 0;

    // {number, steps}
    queue<pair<int, int>> q;
    q.push({start, 0});

    // Create a dist array to store the no. of multiplications to reach a particular number from the start number.
    vector<int> dist(100000, 1e9);
    dist[start] = 0;


    while (!q.empty())
    {
        int node = q.front().first;
        int steps = q.front().second;

        q.pop();

        for (auto it : arr)
        {
            int num = (it * node) % mod;

            // If the no. of multiplications are less than before in order to reach a number, we update the dist array.
            if (steps + 1 < dist[num])
            {
                dist[num] = steps + 1;

                if(num==end)
                    return steps+1;

                q.push({num, steps + 1});
            }
        }
    }

    // If the end no. is unattainable.
    return -1;
}

int main()
{

    return 0;
}
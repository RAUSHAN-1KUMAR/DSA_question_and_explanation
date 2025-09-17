/* -> 1962

You are given a 0-indexed integer array piles, where piles[i] represents the number of stones in the ith pile, and an integer k. You should apply the following operation exactly k times:

Choose any piles[i] and remove floor(piles[i] / 2) stones from it.
Notice that you can apply the operation on the same pile more than once.

Return the minimum possible total number of stones remaining after applying the k operations.

floor(x) is the greatest integer that is smaller than or equal to x (i.e., rounds x down).

 
Example 1:
    Input: piles = [5,4,9], k = 2
    Output: 12
    Explanation: Steps of a possible scenario are:
    - Apply the operation on pile 2. The resulting piles are [5,4,5].
    - Apply the operation on pile 0. The resulting piles are [3,4,5].
    The total number of stones in [3,4,5] is 12.


Example 2:
    Input: piles = [4,3,6,7], k = 3
    Output: 12
    Explanation: Steps of a possible scenario are:
    - Apply the operation on pile 2. The resulting piles are [4,3,3,7].
    - Apply the operation on pile 3. The resulting piles are [4,3,3,4].
    - Apply the operation on pile 0. The resulting piles are [2,3,3,4].
    The total number of stones in [2,3,3,4] is 12.
*/

/*
Appraoch:- 
    -- using maxHeap to put max element in top and then modify it by top/2, and then insert it again, next time we will again have our next max at top.

Note:- we can see that in question they are saying to remove floor(x) form x not find the floor(x)

Overall TC: O(n + k*logn)
SC: O(n)
*/

#include<bits/stdc++.h>
using namespace std;

int minStoneSum(vector<int>& piles, int k)
{
    priority_queue<int> maxHeap;

    // remember this will take O(n) time, not O(nlogn)
    for(int num:piles)
        maxHeap.push(num);

    while(k--)
    {
        int topEle = maxHeap.top();
        maxHeap.pop();

        topEle = topEle-floor(topEle/2);

        maxHeap.push(topEle);
    }

    // forming answer
    int sum=0;
    while(!maxHeap.empty())
    {
        int topEle = maxHeap.top();
        maxHeap.pop();
        sum+=topEle;
    }

    return sum;
}


int main()
{
    int a = 9;
    cout << floor(9/2) << endl;
    cout << ceil(9.0/2) << endl;
    return 0;
}
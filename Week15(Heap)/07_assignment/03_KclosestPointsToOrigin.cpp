/* -> 973

Given an array of points where points[i] = [xi, yi] represents a point on the X-Y plane and an integer k, return the k closest points to the origin (0, 0).

The distance between two points on the X-Y plane is the Euclidean distance (i.e., √(x1 - x2)2 + (y1 - y2)2).

You may return the answer in any order. The answer is guaranteed to be unique (except for the order that it is in).



Example 1:
    Input: points = [[1,3],[-2,2]], k = 1
    Output: [[-2,2]]
    Explanation:
    The distance between (1, 3) and the origin is sqrt(10).
    The distance between (-2, 2) and the origin is sqrt(8).
    Since sqrt(8) < sqrt(10), (-2, 2) is closer to the origin.
    We only want the closest k = 1 points from the origin, so the answer is just [[-2,2]].


Example 2:
    Input: points = [[3,3],[5,-1],[-2,4]], k = 2
    Output: [[3,3],[-2,4]]
    Explanation: The answer [[-2,4],[3,3]] would also be accepted.

*/

/*
Approach:- question is similar to kth largest/smallest element
    -- we will create minHeap, and on the basis of its distance from the origin, we are gonna give preference to them
*/

#include<bits/stdc++.h>
using namespace std;

class compare
{
public:
    bool operator()(pair<int,int> &a, pair<int,int> &b)
    {
        int distA = a.first*a.first + a.second*a.second;
        int distB = b.first*b.first + b.second*b.second;

        return distA > distB;
    }
};

vector<vector<int>> kClosest(vector<vector<int>>& points, int k) 
{
    priority_queue<pair<int,int>, vector<pair<int,int>>, compare> pq;

    // pushed the points into minHeap
    for(auto each:points)
    {
        pq.push({each[0], each[1]});
    }   


    // lets build our answer
    vector<vector<int>> ans;
    while(k-- && !pq.empty())
    {
        ans.push_back({pq.top().first, pq.top().second});
        pq.pop();
    }

    return ans;
}

int main()
{
    vector<vector<int>> points = {
        {3,3},
        {5,-1},
        {-2,4},
    };

    int k=2;

    vector<vector<int>> ans = kClosest(points, k);

    for(auto num:ans)
    {
        for(auto n:num)
            cout << n << " ";
        cout << endl;
    }

    return 0;
}
/*
Given points, that lies on boundary of a Square, we have to sort it in clockwise or circular order

Example
    Input: side=6, points={(1,6), (0,3), (6,2), (0,5), (6,4), (3,0), (3,6), (6,6)}
    Output: {(0,3), (0,5), (1,6), (3,6), (6,6), (6,4), (6,2), (3,0)}
*/

#include<bits/stdc++.h>
using namespace std;

typedef vector<vector<int>> DVC;

DVC circularSort(DVC points, int side)
{
    auto order = [side](vector<int> &p){
        if(p[0]==0) return make_pair(0, p[1]);
        if(p[1]==side) return make_pair(1, p[0]);
        if(p[0]==side) return make_pair(2, -p[1]);
        return make_pair(3, -p[0]);
    };

    sort(points.begin(), points.end(), [&](vector<int> &a, vector<int> &b){
        return order(a) < order(b);
    });

    return points;
}


int main()
{
    DVC points={{1,6}, {0,3}, {6,2}, {0,5}, {6,4}, {3,0}, {3,6}, {6,6}};
    int side=6;

    DVC ans=circularSort(points, side);
    for(auto  &vec:ans){
        for(int &num:vec){
            cout << num << " ";
        }
        cout << endl;
    }

    return 0;
}


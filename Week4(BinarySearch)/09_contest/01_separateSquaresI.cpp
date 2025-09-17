/* -> 3453 (good question)
You are given a 2D integer array squares. Each squares[i] = [xi, yi, li] represents the coordinates of the bottom-left point and the side length of a square parallel to the x-axis.

Find the minimum y-coordinate value of a horizontal line such that the total area of the squares above the line equals the total area of the squares below the line.

Answers within 10^-5 of the actual answer will be accepted.

Note: Squares may overlap. Overlapping areas should be counted multiple times


Example 1:
    Input: squares = [[0,0,1],
                      [2,2,1]]
    Output: 1.00000
    Explanation: Any horizontal line between y = 1 and y = 2 will have 1 square unit above it and 1 square unit below it. The lowest option is 1.

Example 2:
    Input: squares = [[0,0,2],
                      [1,1,1]]
    Output: 1.16667
    Explanation:
    The areas are:
    Below the line: 7/6 * 2 (Red) + 1/6 (Blue) = 15/6 = 2.5
    Above the line: 5/6 * 2 (Red) + 5/6 (Blue) = 15/6 = 2.5
    Since the areas above and below the line are equal, the output is 7/6 = 1.16667.
*/

/*
Approach:- BS on answers
    -- first i find the search space, low and high(for y axis), and then then applied BS on it
    -- on each mid,, i traversed my vector squares to find the net area below and up of mid line, and then moved our BS left and right on that
*/

#include<bits/stdc++.h>
using namespace std;

void isValid(vector<vector<int>> &squares, double &mid, double &ad, double &au)
{
    // note:- & ka use kerna bhut jyada matter kerta h,, nhi to TLE ayega
    for(auto &eachVec:squares)
    {
        double y1 = eachVec[1];
        double len = eachVec[2];
        double y2 = y1+len;
        
        if(mid<=y1){
            au+=len*len;
        }
        else if(mid>=y2){
            ad+=len*len;
        }
        else{// mid>y1 && mid<y2
            double lend=mid-y1;
            double lenu=y2-mid;

            ad+=lend*len;
            au+=lenu*len;
        }
    }
}

double separateSquares(vector<vector<int>> &squares)
{
    // first lets find the search space
    double low=DBL_MAX;
    double high=-DBL_MAX;
    for(auto &eachVec:squares){
        double y1=eachVec[1];
        double len=eachVec[2];
        low=min(y1,low);
        high=max(y1+len, high);
    }

    // now BS on our search space
    double ans;
    while(high-low>1e-5)
    {
        double mid=(low+high)/2;
        
        double areaDown=0;
        double areaUp=0;
        isValid(squares, mid, areaDown, areaUp);

        if(areaDown>=areaUp){
            ans=mid;
            high=mid;// we have to look for the decimal precision, that's why i didn't do the mid-1e-5
        }
        else{
            low=mid;// same here
        }
    }

    return ans;
}

int main()
{
    vector<vector<int>> squares={
        {0,0,1},
        {2,2,1}
    };
    cout << separateSquares(squares) << endl;
    return 0;
}


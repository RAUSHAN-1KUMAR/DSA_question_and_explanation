/* -> 875

Koko loves to eat bananas. There are n piles of bananas, the ith pile has piles[i] bananas. The guards have gone and will come back in h hours.

Koko can decide her bananas-per-hour eating speed of k. Each hour, she chooses some pile of bananas and eats k bananas from that pile. If the pile has less than k bananas, she eats all of them instead and will not eat any more bananas during this hour.

Koko likes to eat slowly but still wants to finish eating all the bananas before the guards return.

Return the minimum integer k such that she can eat all the bananas within h hours.

 

Example 1:
Input: piles = [3,6,7,11], h = 8
Output: 4

Example 2:
Input: piles = [30,11,23,4,20], h = 5
Output: 30

Example 3:
Input: piles = [30,11,23,4,20], h = 6
Output: 23
*/

/*
Approach:- same as previous appraoch, but a light change in isPossibleSolution function.
*/

#include<iostream>
#include<vector>
#include<algorithm>
#include<cmath>
using namespace std;

bool isPosibleSolution(vector<int> &piles, int mid, int h)
{
    int c=0;
    for(int i=0 ; i<piles.size() ; i++)
    {
        c += ceil((float)piles[i]/(float)mid);//-> catch, instead of using next loop we can do this
        if(c>h) return false;
    }

    return true;
}

int minEatingSpeed(vector<int>& piles, int h) 
{
    int s=1;
    int e=*max_element(piles.begin(), piles.end());
    
    int ans = -1;
    while (s<=e)
    {
        int mid = s+(e-s)/2;

        if(isPosibleSolution(piles,mid,h)){
            ans = mid;
            e = mid-1;
        }
        else{
            s = mid+1;
        }
    }
    
    return ans;
}

int main()
{
    vector<int> piles = {1000000000};
    int h=2;

    cout << minEatingSpeed(piles, h) << endl;

    return 0;
}
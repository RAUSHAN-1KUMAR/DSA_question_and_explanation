/* -> GFG

We have a horizontal number line. On that number line, we have gas 'stations' at positions stations[0], stations[1], ..., stations[N-1], where n = size of the stations array. Now, we add k more gas stations so that d, the maximum distance between adjacent gas stations, is minimized. We have to find the smallest possible value of d. Find the answer exactly to 2 decimal places.

Example 1:
    Input: n = 10, stations = [1, 2, 3, 4, 5, 6, 7, 8, 9, 10], k = 9
    Output: 0.50
    Explanation: Each of the 9 stations can be added mid way between all the existing adjacent stations.


Example 2:
    Input: n = 10, stations = [3,6,12,19,33,44,67,72,89,95], k = 2 
    Output: 14.00 
    Explanation: Construction of gas stations at 8th(between 72 and 89) and 6th(between 44 and 67) locations.
*/

/*
Approach:-
        3. Optimal solution:- using binary search,
            -- In this case, our binary search will be slightly change due to we have asked for decimal point also, 
            -- Thoda confusion ho rha h ki BS lagaye kaise,, just think, BS matlab, nlogn, to ye nlogn kaise ata tha-> ek search space p BS lagate the and then given array m iterate kerte the:- To yahi chiz yanha bhi krengen
                i) Outer BS will be on our searchSpace: (minDis(0) to maxDisPossible)
                ii) ek function call to iterate through the given stations for that perticular diff

                Ex: we got mid=x on our searchSpace and then iss x jitne diff ka use kerke kitne stations ko place ker sakte h
                    a) if count>k, move right
                    b) if count<=k, move left

            -> see the solution below(Notice some changes in Binary search code)
*/

#include<bits/stdc++.h>
using namespace std;

// Optimal Solution 
int countOfGasStation(vector<int> &stations, double gap)
{
    int count=0;
    
    for(int i=0; i<stations.size()-1; i++)
    {
        // for given gap, calculating the number of stations we can place
        int currentGap = stations[i+1]-stations[i];

        if(currentGap > gap)
        {
            count += currentGap/gap;
        }
    }

    return count;
}


double findSmallestMaxDist(vector<int> &stations, int k)
{
    int n=stations.size();

    // low have to start form 0.00, becuase answer could be 0.15 or 0.01 also
    long double low=0.00;
    long double high=0.00;

    for(int i=0; i<n-1;i++)
        high = max(high, (long double)stations[i+1]-stations[i]);

    long double ans=-1;

    // high-low>0.01 is must
    long double diff = 1e-6;
    while(high-low > diff)
    {
        double mid=(low+high)/2.0;

        int count = countOfGasStation(stations, mid);

        if(count<=k) // search in left side
        {
            ans=mid;
            high=mid;
        }
        else // search in right side
        {
            low=mid;
        } 
    }

    return (ans==-1 ? high : round(ans*100)/100);
}


int main()
{
    vector<int> stations = {1,2,3,4,5,6,7,8,9,10};
    int k=5;

    cout << findSmallestMaxDist(stations, k) << endl;

    return 0;
}


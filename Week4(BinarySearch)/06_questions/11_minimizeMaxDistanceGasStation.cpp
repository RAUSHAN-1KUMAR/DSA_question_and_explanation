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
    Logic:- suppose we have gas station in x and y position: x<y and we have k station to place in between them, so we place k stations in equal gap ;- each station will be gap of -> (y-x)/k

        1. Brute force: we will have an array for the gaps: and then one by one we will calculate how many total stations are there in that gap at the end.
        And then we will use the that array to distribute the gas stations equally -> (y-x)/k

            -- TLE: TC-> O(n*k)+O(n)
                    SC-> O(n-1)

        2. Better approach:- we will optimise to find the no. of stations in the gap
            -- using maxHeap

            TC:- O(nlogk)+O(klogn)
            SC:- O(n-1) + O(n-1)

        3. Optimal solution:- using binary search,
            -- In this case, our binary search will be slightly change due to we have asked for decimal point also, 
            -- Thoda confusion ho rha h ki BS lagaye kaise,, just think, BS matlab, nlogn, to ye nlogn kaise ata tha-> ek search space p BS lagate the and then given array m iterate kerte the:- To yahi chiz yanha bhi krengen
                i) Outer BS will be on our searchSpace: (minDis(0) to maxDisPossible)
                ii) ek function call to iterate through the given stations for that perticular diff

                Ex: we got mid=x on our searchSpace and then iss x jitne diff ka use kerke kitne stations ko place ker sakte h
                    a) if count>k, move right
                    b) if count<=k, move left

            -> see the solution below(Notice some changes in Binary search code)
            -> code nhi samjh aaya-> check out next solution
*/

#include<bits/stdc++.h>
using namespace std;


// Brute force
double findSmallesMaxDist(vector<int> &stations, int k)
{
    int n=stations.size();

    // this array will keep track of no. of gasStations wihin a gap
    vector<int> howMany(n-1, 0);

    // pick and place k gas stations
    for(int gasSta=1 ; gasSta<=k ; gasSta++)
    {
        // initially both will be -1
        double maxGap = -1;
        int maxGapIndex = -1;

        // now lets find the first max, every time we are iterating to find the current max for current k
        for(int i=0 ; i<n-1 ; i++)
        {
            // got the gap
            double currStaGap = stations[i+1] - stations[i];

            // divide the gap if new stations are already there
            double sectionLength = currStaGap/double(howMany[i]+1);

            // update maxGap
            if(sectionLength > maxGap){
                maxGap = sectionLength;
                maxGapIndex = i;
            }
        }

        // after getting the current max gap, insert the station
        howMany[maxGapIndex]++;
    }


    // after placing all gas stations, now calculating the maxGap left
    double maxAns=-1;
    for(int i=0 ; i<n-1 ; i++)
    {
        double stationGap = stations[i+1]-stations[i];
        double sectionLength = stationGap / double(howMany[i]+1);
        maxAns = max(maxAns, sectionLength);
    }

    double ansTwoDecPoint = round(maxAns*100)/100;

    return ansTwoDecPoint;
}


// Better approach (using maxHeap)
double findSmallesMaxDist1(vector<int> &stations, int k)
{
    int n=stations.size();

    // this array will keep track of no. of gasStations within a gap
    vector<int> howMany(n-1, 0);

    // maxheap to store the maxGap at top
    priority_queue<pair<double,int>> maxHeap;

    // initalizing maxHeap
    for(int i=0 ; i<n-1 ; i++)
    {
        double stationGap = stations[i+1]-stations[i];
        maxHeap.push({stationGap, i});
    }

    // pick and place k gas stations
    for(int gasSta=1 ; gasSta<=k ; gasSta++)
    {
        auto tp = maxHeap.top();
        maxHeap.pop();

        int maxGapIndex = tp.second;

        howMany[maxGapIndex]++;

        double initialDiff = stations[maxGapIndex+1] - stations[maxGapIndex];

        double newSectLength = initialDiff/double(howMany[maxGapIndex]+1);

        maxHeap.push({newSectLength, maxGapIndex});
    }

    // answer will be at the top of heap
    double ansTwoDecPoint = round(maxHeap.top().first*100)/100;

    return ansTwoDecPoint;
}


// Optimal Solution (BS for doubles, will require some changes)
int countOfGasStation(vector<int> &stations, double gap)
{
    int count=0;
    
    for(int i=0; i<stations.size()-1; i++)
    {
        // for given gap, calculating the number of stations we can place
        int numberInBetween = (stations[i+1]-stations[i])/gap;

        // if division is whole number
        if((stations[i+1]-stations[i])/gap == numberInBetween*gap)
            numberInBetween--;

        count += numberInBetween;
    }

    return count;
}

double findSmallesMaxDist2(vector<int> &stations, int k)
{
    int n=stations.size();

    // low have to start form 0, becuase answer could be 0.15 or 0.01 also
    double low=0;
    double high=INT_MIN;
    for(int i=0; i<n-1;i++)
        high = max(high, (double)stations[i+1]-stations[i]);

    double ans=-1;

    // Change1
    while(high-low > 0.01)
    {
        double mid=(low+high)/2.0;

        int count = countOfGasStation(stations, mid);

        if(count<=k) // search in left side
        {
            ans=mid;
            high=mid;//change2, so that can we can maintain the decimal accuracy also.
        }
        else // search in right side
        {
            low=mid;//change3, so that can we can maintain the decimal accuracy also.
        } 
    }

    int answer = ans*100;

    return round(answer)/100;
} 


int main()
{
    vector<int> stations = {1,2,3,4,5,6,7,8,9,10};
    int k=5;

    cout << findSmallesMaxDist2(stations, k) << endl;

    return 0;
}


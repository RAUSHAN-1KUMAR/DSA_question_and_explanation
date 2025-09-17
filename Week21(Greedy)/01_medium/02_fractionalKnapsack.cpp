/* GFG

Given two arrays, val[] and wt[] , representing the values and weights of items, and an integer capacity representing the maximum weight a knapsack can hold, determine the maximum total value that can be achieved by putting items in the knapsack. You are allowed to break items into fractions if necessary.
Return the maximum value as a double, rounded to 6 decimal places.

Examples :
    Input: val[] = [60, 100, 120], wt[] = [10, 20, 30], capacity = 50
    Output: 240.000000
    Explanation: By taking items of weight 10 and 20 kg and 2/3 fraction of 30 kg. Hence total price will be 60+100+(2/3)(120) = 240

    Input: val[] = [500], wt[] = [30], capacity = 10
    Output: 166.670000
    Explanation: Since the item’s weight exceeds capacity, we take a fraction 10/30 of it, yielding value 166.670000.
*/

#include<bits/stdc++.h>
using namespace std;

double fractionalKnapsack(int capacity, vector<int> &wt, vector<int> &val)
{
    int n = val.size();

    // create a vector of pairs to store value/weight ratio and weight of each item
    vector<pair<double,int>> ratio(n);

    for(int i=0 ; i<n ; i++)
    {
        ratio[i].first = (double)val[i]/(double)wt[i];
        ratio[i].second = wt[i];
    }

    // sort the ratio array in descending order of value/weight ratio
    sort(ratio.begin(), ratio.end(), greater<pair<double,int>>());

    double totalValue=0.0;

    for(int i=0 ; i<n ; i++)
    {
        if(capacity==0) break;

        if(ratio[i].second <= capacity)
        {// take the whole item
            totalValue += ratio[i].first * ratio[i].second; // v/w * w = value
            capacity -= ratio[i].second;
        }
        else
        {// take the fraction of the item
            totalValue += ratio[i].first * capacity; // v/w * capacity = value
            capacity = 0;
        }
    }

    return totalValue;
}


int main()
{
    vector<int> wt = {10,20,30};
    vector<int> val = {60,100,120};
    int W = 50;
    cout << fixed << setprecision(6) << fractionalKnapsack(W, wt, val) << endl;
    return 0;
}



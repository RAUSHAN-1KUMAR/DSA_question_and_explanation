/*-> 1052

There is a bookstore owner that has a store open for n minutes. Every minute, some number of customers enter the store. You are given an integer array customers of length n where customers[i] is the number of the customer that enters the store at the start of the ith minute and all those customers leave after the end of that minute.

On some minutes, the bookstore owner is grumpy. You are given a binary array grumpy where grumpy[i] is 1 if the bookstore owner is grumpy during the ith minute, and is 0 otherwise.

When the bookstore owner is grumpy, the customers of that minute are not satisfied, otherwise, they are satisfied.

The bookstore owner knows a secret technique to keep themselves not grumpy for minutes consecutive minutes, but can only use it once.

Return the maximum number of customers that can be satisfied throughout the day.

 

Example 1:
Input: customers = [1,0,1,2,1,1,7,5], grumpy = [0,1,0,1,0,1,0,1], minutes = 3
Output: 16
Explanation: The bookstore owner keeps themselves not grumpy for the last 3 minutes. 
The maximum number of customers that can be satisfied = 1 + 1 + 1 + 1 + 7 + 5 = 16.

Example 2:
Input: customers = [1], grumpy = [0], minutes = 1
Output: 1

*/

/*
Approach:- sliding window
    -- first we will find that window where we get maximum unsatisifed customers, uss window m ham apna consecutive minute wala secret technique lagayengen.
    -- and baki jo customers bach gye h usko find ker lengen.

General thought process:-
    -- sabse bada super minute ka window dhundh lo and then baki jo customers bach gye usko nikal lo ya sum ker lo usme w.r.t grumpy array.-> this appraoch is wrong because if you proceed with this approach then you are gonna take grumpy(0) customers sum which will already be added later, so we will find that window in which unsatisfied customers are max
*/

#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;

int maxSatisfied(vector<int>& customers, vector<int>& grumpy, int minutes)
{
    int n = customers.size();

    int maxUnsatCust = 0; // in consecutive window of size minutes.
    int currUnsat = 0;

    // finding unsatisfied customers for first window
    for(int i=0 ; i<minutes; i++)
    {
        if(grumpy[i]==1)
            currUnsat += customers[i];
    }
    maxUnsatCust = currUnsat;

    // checking unsatisfied customers for further window;
    int i=0;
    int j=minutes;
    while (j<n)
    {
        if(grumpy[j]==1){
            currUnsat += customers[j];
        }

        if(grumpy[i]==1){
            currUnsat -= customers[i];
        }

        maxUnsatCust = max(maxUnsatCust, currUnsat);
        
        i++;
        j++;
    }

    // finding for satisfied customers
    int totalSat = maxUnsatCust;
    for(int i=0 ; i<n ; i++)
    {
        if(grumpy[i]==0)
            totalSat += customers[i];
    }

    return totalSat;
    
}

int main()
{
    vector<int> customers = {4,10,10};
    vector<int> grumpy = {1,1,0};
    int minutes = 2;

    int ans = maxSatisfied(customers, grumpy, minutes);

    cout << ans << endl;

    return 0;
}
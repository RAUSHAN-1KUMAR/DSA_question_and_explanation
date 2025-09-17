/* -> 846

Alice has some number of cards and she wants to rearrange the cards into groups so that each group is of size groupSize, and consists of groupSize consecutive cards.

Given an integer array hand where hand[i] is the value written on the ith card and an integer groupSize, return true if she can rearrange the cards, or false otherwise.

 

Example 1:
    Input: hand = [1,2,3,6,2,3,4,7,8], groupSize = 3
    Output: true
    Explanation: Alice's hand can be rearranged as [1,2,3],[2,3,4],[6,7,8]


    Input: hand = [1,2,3,4,5], groupSize = 4
    Output: false
    Explanation: Alice's hand can not be rearranged into groups of 4.
*/

/*
Approach:-
    1. Greedy:- hashing + sorting
        -- first hashed the array elements, and sorted the array to first pick the lowest element
        -- after this, we will iterate to the sorted array and if we find the element in map,
            - after finding, run an additional loop to seek for the next consecutive elements for that element till given groupSize, 
                - we get it then OKK, also reduce the freq by 1
                - if not than return false

        Their will be different scenario if we will use unordered map or ordered map -> see both solution below

        TC:- O(k*groupSize*logk) => O(nlogk) : k-> no. of distinct elements
        SC:- O(n)

    2. Using Heap:- Next solution
            
*/

#include<bits/stdc++.h>
using namespace std;


// using unordered_map, we need to sort the hand array
bool isNStraightHand(vector<int>& hand, int groupSize)
{
    // we can have a base case also
    if(hand.size()%groupSize != 0) return false;

    // stored the freq of each element
    unordered_map<int,int> mp;
    for(auto &each:hand) //-> O(n)
    {
        mp[each]++; //-> O(1) in case of unordered_map
    }

    // sort the hand array
    sort(hand.begin(), hand.end()); //-> O(nlogn)

    // now lets build our answer
    for(auto num:hand) //-> O(n)
    {
        if(mp[num]>0)
        {
            // num, num+1, num+2, .. next consecutive elements
            for(int i=num;  i<(num+groupSize) ; i++) //->O(groupSize)
            {
                mp[i]--;
                if(mp[i]<0) return false; //-> mapOperation O(1)
            }
        }
    }

    return true;
}


// using map, we do not need to sort the 'hand' array, we will directly use the map itself-> that's the only difference
bool isNStraightHand1(vector<int>& hand, int groupSize)
{
    if(hand.size()%groupSize != 0) return false;

    map<int,int> mp;//-> ordered map will store the key-value in ordered way, so we don,t need to sort the hand array
    for(auto &each:hand) //-> O(n) 
    {
        mp[each]++; //-> O(logk) k-> no. of unique elements
    }


    while(!mp.empty()) //-> O(k)
    {
        int curr = mp.begin()->first;

        for(int i=0 ; i<groupSize; i++) //-> O(groupSize)
        {
            if(mp[curr+i]==0) //-> mapOperation O(logk)
            {
                return false;
            }

            mp[curr+i]--;
            if(mp[curr+i]<1){
                mp.erase(curr+1);
            }
        }
    }


    return true;
}


int main()
{
    vector<int> hand = {1,2,3,6,2,3,4,7,8};
    int groupSize = 3;

    cout << isNStraightHand(hand, groupSize) << endl;
}


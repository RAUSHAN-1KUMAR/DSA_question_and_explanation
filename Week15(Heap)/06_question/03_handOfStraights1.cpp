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
    2. Using Heap:-
        -- we can see that, we have started the grouping in greedy approach from the most minimum element and then next minimum element, so we will use minHeap
        -- approach is same, we are just having minHeap instead of sorting the array

        TC: same as in case of map, O(nlogk) : k-> unique elements
        SC: O(k)
*/

#include<bits/stdc++.h>
using namespace std;

class node
{
public:
    int data;
    int freq;

    node(){}

    node(int d, int f)
    {
        this->data = d;
        this->freq = f;
    }
};

// solution from here
class compare
{
public:
    bool operator()(node a, node b)
    {
        return a.data > b.data;
    }
};


bool isNStraightHand(vector<int>& hand, int groupSize)
{
    // we can a base case also
    if(hand.size()%groupSize != 0) return false;
    if(groupSize==1) return true;

    // Count frequencies of each card
    unordered_map<int, int> mp;
    for (int card : hand) mp[card]++;

    // push all unique cards into a minHeap
    priority_queue<int, vector<int>, greater<int>> minHeap;
    for (auto &each : mp) {
        minHeap.push(each.first);
    }

    // process the cards to form groups
    while (!minHeap.empty())
    {
        int start = minHeap.top(); // Smallest card in the heap

        // Try forming a group starting from 'start'
        for (int i = 0; i < groupSize; i++)
        {
            int currentCard = start + i;

            // If the current card is missing, return false
            if (mp[currentCard] == 0) return false;

            // Use one card of the current type
            mp[currentCard]--;

            // Remove the card from the heap if its frequency becomes 0
            if (mp[currentCard] == 0 && currentCard == minHeap.top()) // matching with top of heap is must
            {
                minHeap.pop();
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


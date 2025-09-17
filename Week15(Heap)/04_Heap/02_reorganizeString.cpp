/* -> 767

Given a string s, rearrange the characters of s so that any two adjacent characters are not the same.

Return any possible rearrangement of s or return "" if not possible.
 

Example 1:
Input: s = "aab"
Output: "aba"

Example 2:
Input: s = "aaab"
Output: ""
*/

/*   
Appraoch:- This question has done once, in string Week
    -- approach will be similar, just using the maxHeap to get the max freq character.
    -- popping two character at a time

    TC:- O(n)
    SC:- O(1)

Note:- we can also see that if any character having max freq more than the half of the size of the string than it's 100% that we can't rearrange the string so that any two adjacent character are not the same -> our base case(optional)
*/

#include<bits/stdc++.h>
using namespace std;

class info
{
public:
    char val;
    int count;

    info(char ch, int cnt)
    {
        this->val = ch;
        this->count = cnt;
    }
};

class compare
{
public:
    bool operator()(info a, info b){
        return a.count < b.count;
    }
};


string reorganizeString(string s)
{
    int n=s.size();

    // first store the freq of character
    int freq[26] = {0};
    for(int i=0 ; i<s.length() ; i++) //-> O(n)
    {
        char ch = s[i];
        freq[ch-'a']++;

        if(freq[ch-'a']>(n+1)/2) //-> Base case
            return "";
    }

    // inserting the data into maxHeap
    priority_queue<info, vector<info>, compare> maxHeap;
    for(int i=0 ; i<26 ; i++) //-> O(1)
    {
        if(freq[i]>0)
        {
            info temp(i+'a', freq[i]);
            maxHeap.push(temp);
        }
    }


    // building ans
    string ans = "";
    while(maxHeap.size()>=2)//->it seems O(26) becuase we can have only 26 character but we are building our ans string, so for each char in s we are gonna run this loop => max -> O(n)
    {
        // first take two top freq character
        info first = maxHeap.top();
        maxHeap.pop(); //-> O(log26) = O(1)

        info second = maxHeap.top();
        maxHeap.pop();

        // push them one by one
        ans.push_back(first.val);
        first.count--;
        ans.push_back(second.val);
        second.count--;

        // if still count is left then push them
        if(first.count>0) maxHeap.push(first);
        if(second.count>0) maxHeap.push(second);
    }

    // at last, if heap is non empty then
    if(maxHeap.size()>0)
    {
        info first = maxHeap.top();
        maxHeap.pop();

        ans.push_back(first.val);
        first.count--;

        // if count left, then we are sure that we can't build the answer string
        if(first.count>0)
            return "";
    }
 

    return ans;
}


int main()
{
    string s = "aac";

    cout << reorganizeString(s) << endl;
    
    return 0;
}


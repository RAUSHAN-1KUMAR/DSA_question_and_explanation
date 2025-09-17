/* -> 1405

A string s is called happy if it satisfies the following conditions:
 1. s only contains the letters 'a', 'b', and 'c'.
 2. s does not contain any of "aaa", "bbb", or "ccc" as a substring.
 3. s contains at most a occurrences of the letter 'a'.
 4. s contains at most b occurrences of the letter 'b'.
 5. s contains at most c occurrences of the letter 'c'.

Given three integers a, b, and c, return the longest possible happy string. If there are multiple longest happy strings, return any of them. If there is no such string, return the empty string "".

A substring is a contiguous sequence of characters within a string.

 

Example 1:
    Input: a = 1, b = 1, c = 7
    Output: "ccaccbcc"
    Explanation: "ccbccacc" would also be a correct answer.


Example 2:
    Input: a = 7, b = 1, c = 0
    Output: "aabaa"
    Explanation: It is the only correct answer in this case.
*/

/*
Approach: i solved it, see next solution for love babbar approach
    -- similar to first approach, but in this case we can place two adjacent character not three and also it not says to use all the character count given
    -- so it will require little bit carefullness because we have to to maximize the ans string:

        example:- a=6, b=2, c=0, ans-> aabaabaa

        1. General thought-> 
            - take two top max chracter, and place double of it, aabb, and then again take top two, but we only left with a so -> aabbaa
        
        2. Actual logic:-> 
            - if(count_diff of top two > 0) then place double of first character and then single character of second, aab, and then again if happens, aabaab, and we only left with a so-> aabaabaa
            - if not then go with the general thought, i.e, place double of it, aabb


TC:- O((a+b+c)*log(3)) = O(a+b+c)
SC:- O(3) = O(1)
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


void pushElementByChecking(string &ans, info &first, info &second, bool &yes)
{
    // inserting first character
    if(first.count>=2)
    {
        ans.push_back(first.val);
        ans.push_back(first.val);
        first.count-=2;
    }
    else
    {
        ans.push_back(first.val);
        first.count--;
    }

    // inserting second character
    if(yes)
    {
        ans.push_back(second.val);
        second.count--;
    }
    else
    {
        if(second.count>=2)
        {
            ans.push_back(second.val);
            ans.push_back(second.val);
            second.count-=2;
        }
        else
        {
            ans.push_back(second.val);
            second.count--;
        }
    }

}


string longestDiverseString(int a, int b, int c)
{
    priority_queue<info, vector<info>, compare> maxHeap;

    if(a>0)
        maxHeap.push(info('a', a));
    if(b>0)
        maxHeap.push(info('b', b));
    if(c>0)
        maxHeap.push(info('c', c));


    // forming answer
    string ans = "";
    while(maxHeap.size()>1)
    {
        // first take two top freq character
        info first = maxHeap.top();
        maxHeap.pop();

        info second = maxHeap.top();
        maxHeap.pop();

        bool yes=false;
        if((first.count-second.count)>0)
        {
            yes=true;
            // place double of first and single of second
            pushElementByChecking(ans, first, second, yes);
        }
        else
        {
            // place double of both if count>=2
            pushElementByChecking(ans, first, second, yes);
        }

        // if still count is left then push them
        if(first.count>0) maxHeap.push(first);
        if(second.count>0) maxHeap.push(second);
    }


    // if heap is not empty
    if(maxHeap.size()==1)
    {
        info first=maxHeap.top();
        maxHeap.pop();

        if(first.count>=2)
        {
            ans.push_back(first.val);
            ans.push_back(first.val);
            first.count-=2;
        }
        else
        {
            ans.push_back(first.val);
            first.count--;
        }
    }

    return ans;
}

int main()
{
    int a=3;
    int b=2;
    int c=0;

    string ans = longestDiverseString(a, b, c);

    cout << ans << endl;


    return 0;
}
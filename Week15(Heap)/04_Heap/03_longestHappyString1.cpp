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
Approach:
    -- Did a small twick in function "pushElementByChecking" that will imply the little bit diff logic as i did
        - if(second.count>=first.count after placing firstChar twice) then push double of second char
        - else push single of second char

    The approach is greedy: highest count wale ko do baar push kro

We have also got one approach(better than this), which will pop only one character at a time and only one push not two push at a time -> see next solution

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


void pushElementByChecking(string &ans, info &first, info &second)
{
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

    // no need for bool yes variable
    // small twick in condition after decreasing first.count
    if(second.count>=2 && second.count>=first.count)
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
        info first = maxHeap.top();
        maxHeap.pop();

        info second = maxHeap.top();
        maxHeap.pop();

        // function call to push character
        pushElementByChecking(ans, first, second);

        if(first.count>0) maxHeap.push(first);
        if(second.count>0) maxHeap.push(second);
    }

    // still we have element in heap
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



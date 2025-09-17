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
Approach: Better approach(popping one character at a time)
    -- In this solution, we will only pop one character at a time and then we will check that:- is last two character of answer string matches with this character: 
        i) if yes then pop another character and then push that
        ii) if not then we can push the same character

Can we apply the same approach, in question-> reorganizeString

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
    while(!maxHeap.empty()) //O(a+b+c)
    {
        info first = maxHeap.top();
        maxHeap.pop(); //O(log3)

        if(ans.length()>=2 && ans[ans.length()-1]==first.val && ans[ans.length()-2]==first.val)
        {
            // if we can't use currChar, check for next largest frequency character
            if(maxHeap.empty())
                break;

            info next = maxHeap.top();
            maxHeap.pop();

            ans.push_back(next.val);
            next.count--;
            if(next.count>0)
                maxHeap.push(next);
        }
        else
        {
            ans.push_back(first.val);
            first.count--;
        }

        if(first.count>0)
            maxHeap.push(first);
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



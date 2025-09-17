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
Appraoch:- 
    -- previously we were popping two character at a time, but now we will pop only one character at a time
    -- The logic is that:- we will only pop one character at a time and then we will check that:- is last one character of answer string matches with this character: 
        i) if yes then pop another character and then push that
        ii) if not then we can push the same character
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
    while(!maxHeap.empty())
    {
        info first = maxHeap.top(); maxHeap.pop();

        if(ans.length()>=1 && ans[ans.length()-1]==first.val)
        {
            // if we can't use currChar, check for next largest frequency character
            
            if(maxHeap.empty())
                return "";


            info second = maxHeap.top(); maxHeap.pop();
            
            ans.push_back(second.val);
            second.count--;

            if(second.count>0) 
                maxHeap.push(second);
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
    string s = "aaac";

    cout << reorganizeString(s) << endl;
    
    return 0;
}


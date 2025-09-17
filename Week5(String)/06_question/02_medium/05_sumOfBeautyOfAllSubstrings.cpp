/* -> 1781

The beauty of a string is the difference in frequencies between the most frequent and least frequent characters.
    - For example, the beauty of "abaacc" is 3 - 1 = 2.

Given a string s, return the sum of beauty of all of its substrings.

 
Example 1:
Input: s = "aabcb"
Output: 5
Explanation: The substrings with non-zero beauty are ["aab","aabc","aabcb","abcb","bcb"], each with beauty equal to 1.

Example 2:
Input: s = "aabcbaa"
Output: 17
*/


/*
Appraoch:- 
    -- first i find the all possible substring(length >= 3) using brute form i.e., O(n^2)
    -- and then passing each string to a beauty function finder to find the beauty of each string and then sum it into count.

Note:- Time compleixity is high O(n^2*(something))
*/

#include<iostream>
#include<vector>
#include<algorithm>
#include<unordered_map>
using namespace std;


void formingSubstring(vector<string> &subString, string &s)
{
    for(int i=0 ; i<s.size() ; i++)
    {
        for(int j=i+2 ; j<s.size() ; j++)
        {
            subString.push_back(s.substr(i,j-i+1));
        }
    }    
}

int beautyOfString(string &str)
{
    vector<int> hash(26,0);
    for(auto ch:str)
    {
        hash[ch-'a']++;
    }

    vector<int> freq;
    for(auto num:hash)
    {
        if(num>0) freq.push_back(num);
    }

    int max = *max_element(freq.begin(), freq.end());
    int min = *min_element(freq.begin(), freq.end());

    return max-min;
}

int beautySum(string s)
{
    if(s.size() <= 2) return 0;

    vector<string> subString;
    
    formingSubstring(subString, s);

    // now finding the beauty of each substring
    int count = 0;
    for(int i=0 ; i<subString.size() ; i++)
    {
        count += beautyOfString(subString[i]);
    }

    return count;
}


int main()
{
    string s = "aabcbaa";

    int ans = beautySum(s);

    cout << ans << endl;

    return 0;
}


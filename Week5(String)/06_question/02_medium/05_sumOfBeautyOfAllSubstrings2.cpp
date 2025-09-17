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
Appraoch:- applied the same approach but optimized it.
    -- previous appraoch m ham pehle string ke sare substring nikal rhe the then uss sarre obtained substring p loop laga ke her ek string ka beauti nikal rhe the but
    -- iss appraoch m ham substring nikalte waqt hi uska beauty nikla rhe h.
*/

#include<iostream>
#include<vector>
#include<algorithm>
#include<unordered_map>
using namespace std;

int beauty(vector<int> &alpha)
{
    int mf = -1;
    int lf = 1e9;

    for(int i=0 ; i<26 ; i++)
    {
        mf = max(mf,alpha[i]);

        if(alpha[i]>=1)
        {
            lf = min(lf,alpha[i]);
        }
    }

    return mf-lf;
}


int beautySum(string s)
{
    if(s.size() <= 2) return 0;

    int res = 0;
    for(int i=0 ; i<s.size() ; i++)
    {
        vector<int> alpha(26,0);
        for(int j=i ; j<s.size() ; j++)
        {
            alpha[s[j]-'a']++;
            res = res + beauty(alpha);
        }
    }

    return res;
}


int main()
{
    string s = "aabcbaa";

    int ans = beautySum(s);

    cout << ans << endl;

    return 0;
}

/*
Given a word pat and a text txt. Return the count of the occurrences of anagrams of the word in the text.

Example 1:
    Input: txt = forxxorfxdofr, pat = for
    Output: 3
    Explanation: for, orf and ofr appears
    in the txt, hence answer is 3.

Example 2:
    Input: txt = aabaabaa, pat = aaba
    Output: 4
    Explanation: aaba is present 4 times
    in txt.
*/

/*
Appraoch:- hashing + sliding window
    -- pehle pat ko hash ker rhe, then txt m her pat ke size ka string ko hash kerke pat ke hash se compare ker rhe h
*/

#include<iostream>
#include<algorithm>
#include<vector>
using namespace std;

int search(string pat, string txt)
{
    // hashing the pat
    vector<int> hashPat(26,0);
    for(char ch:pat)
    {
        hashPat[ch-'a']++;
    }

    // now applying sliding window
    int startWindow=0;
    int endWindow=0;
    int windowSize = pat.size();

    vector<int> hashWindowOfTxt(26,0);//-> to compare the hash of txt with pat
    int ans = 0;

    while(endWindow<txt.size())
    {
        char ch = txt[endWindow];
        hashWindowOfTxt[ch-'a']++;

        // if window size matches then jo hash create hua h usko check kro pat ke hash se
        if(endWindow-startWindow+1 == windowSize)
        {
            // ager dono ka hashing same h to anagram achieved
            if(hashWindowOfTxt==hashPat) ans++;

            // ab start window aage badhega to uske respect m jo hashing hua tha usko remove kerdo
            char ch = txt[startWindow];
            hashWindowOfTxt[ch-'a']--;//-> removed the hashing of startWindow
            startWindow++;
        }

        endWindow++;
    }   

    return ans;
}

int main()
{
    string pat = "aaba";
    string txt = "aabaabaa";

    cout << search(pat, txt) << endl;

    return 0;
}

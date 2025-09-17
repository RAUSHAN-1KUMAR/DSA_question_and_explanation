/* To find the longest happy prefix

KMP-> Thte Knuth-Morris-Pratt algorithm to find longest prefix suffix/longest happy prefix

LPS array:-
    -- The Longest Prefix Suffix (LPS) array for a given pattern is an array where each element at index i contains the length of the longest proper prefix of the substring pattern[0..i] which is also a suffix of this substring.
        - A prefix of a string is a substring that starts at the beginning of the string.
        - A suffix of a string is a substring that ends at the end of the string.
        - A proper prefix is a prefix that is not equal to the entire string.
*/

#include<iostream>
#include<vector>
using namespace std;

int lps(string &s)
{
    vector<int> lps(s.size(),0);
    
    int pre = 0;//i
    int suf = 1;//j

    while(suf<s.size())
    {
        // If both are same
        if(s[pre]==s[suf])
        {
            lps[suf] = pre+1;
            pre++;
            suf++;
        }
        else{
            if(pre==0){ // if both are not same and pre is at first index
                lps[suf]=0;
                suf++;
            }
            else{ // if both are not same and pre is at some index then pre ko lps[pre-1] pe bhej do, means pre ko lps ke just pehle wale value p bhej do 
                pre = lps[pre-1];
            }
        }
    }

    return lps[s.size()-1];
}


int main()
{
    string str = "abcabdabcabdabdab";

    int LPS = lps(str);

    cout << LPS << endl;

    return 0;
}




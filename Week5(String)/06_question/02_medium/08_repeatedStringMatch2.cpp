/* -> 686

Given two strings a and b, return the minimum number of times you should repeat string a so that string b is a substring of it. If it is impossible for b​​​​​​ to be a substring of a after repeating it, return -1.

Notice: string "abc" repeated 0 times is "", repeated 1 time is "abc" and repeated 2 times is "abcabc".

 

Example 1:
Input: a = "abcd", b = "cdabcdab"
Output: 3
Explanation: We return 3 because by repeating a three times "abcdabcdabcd", b is a substring of it.

Example 2:
Input: a = "a", b = "aa"
Output: 2
*/

/*
Appraoch:- KMP
*/

#include<iostream>
#include<vector>
using namespace std;

void computeLPS(string str, vector<int> &lps)
{
    int pre=0;
    int suf=1;
    while (suf<str.length())
    {
        if(str[suf]==str[pre]){
            lps[suf] = pre+1;
            pre++;
            suf++;
        }
        else{
            if(pre != 0){
                pre = lps[pre-1];
            }else{
                lps[suf]=0;
                suf++;
            }
        }
    }
    
}

bool kmp(string str, string pat)
{
    vector<int> lps(pat.length(), 0);
    computeLPS(pat, lps);

    int i=0;
    int j=0;
    while(i<str.length()){
        if(str[i]==pat[j]){
            i++;
            j++;
            if(j==pat.length()) return true;
        }
        else{
            if(j!=0){
                j = lps[j-1];
            }
            else{
                i++;
            }
        }
    }

    return false;
}


int repeatedStringMatch(string a, string b)
{
    int len_b = b.length();
    int len_a = a.length();

    int n = (len_b)/(len_a);

    int cnt = n;
    string na = "";
    while (cnt--){
        na = na+a;
    }

    // b = n*a
    if(kmp(na,b)){
        return n;
    }
    
    // b = n+1 wala cases
    na = na+a;
    if(kmp(na,b)){
        return n+1;
    }

    // b = n+2 wala case
    na = na+a;
    if(kmp(na,b)){
        return n+2;
    }
    
    return -1;
}

int main()
{
    string a = "abcd";
    string b = "dabcdab";

    int ans = repeatedStringMatch(a,b);

    cout << ans << endl;

    return 0;
}
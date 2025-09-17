/*
Given a string s, consider all duplicated substrings: (contiguous) substrings of s that occur 2 or more times. The occurrences may overlap.

Return any duplicated substring that has the longest possible length. If s does not have a duplicated substring, the answer is "".



Example 1:
Input: s = "banana"
Output: "ana"

Example 2:
Input: s = "abcd"
Output: ""
*/

// approach:- Binary Search + robin karp algorithm(rolling hash), TC-> O(logn*n*m)

#include<bits/stdc++.h>
using namespace std;

#define ll long long
#define MOD 1000000007

ll computeHash(string &s, ll &radix, ll &len, int start)
{
    ll hash=0, factor=1;

    // iterating form back of the Substring
    for(ll i=start+len-1; i>=start; --i){
        hash += ((s[i]-'a')*factor)%MOD;
        factor = (factor*radix)%MOD;
    }
    
    return hash%MOD;
}

int isPossible(string &s, ll mid, ll n)
{
    ll radix=26;
    ll max_w=1;
    for(ll i=1 ; i<=mid ; i++)
        max_w = (max_w*radix)%MOD;

    unordered_map<ll, vector<int>> mp;
    ll currHash=0;

    for(int i=0 ; i<=(n-mid) ; i++)
    {
        if(i==0){
            currHash = computeHash(s, radix, mid, 0);
            mp[currHash].push_back(0);
        }
        else{
            currHash = (currHash*radix)%MOD;
            currHash = (currHash - ((s[i-1]-'a')*max_w)%MOD + MOD)%MOD;
            currHash = (currHash + (s[i+mid-1]-'a')) %MOD;

            if(mp.count(currHash)){
                for(int idx:mp[currHash]){
                    if(s.substr(idx, mid) == s.substr(i, mid)){
                        return idx;
                    }
                }
            }

            mp[currHash].push_back(i);
        }
    }
    
    return -1;
}


string longestDupSubstring(string s)
{
    int n=s.size();

    // the first sub task is find the length of longest dublicate substring using binary search
    int start=1;
    int end=n-1;
    int len=-1, startIdx=-1;
    while(start<=end)
    {
        int mid=(start+end)/2;
        int idx=isPossible(s, mid, n);

        if(idx!=-1){
            startIdx=idx;
            len=mid;
            start=mid+1;
        }
        else{
            end=mid-1;
        }
    }

    // now we got the length of longest dublicate substring, so now we can simply return substring
    return (startIdx==-1 ? "" : s.substr(startIdx, len));
}


int main()
{
    string s="banana";
    cout << longestDupSubstring(s) << endl;
    return 0;
}




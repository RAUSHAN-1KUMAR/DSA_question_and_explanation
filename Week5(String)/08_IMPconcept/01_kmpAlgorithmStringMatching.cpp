/*
KMP-> Thte Knuth-Morris-Pratt algorithm is a string searching algorithm that searches for occurences of a substring 's' within a main string 'W'.

What is the difference between naive and KMP?
    --Naive pattern searching which slides the pattern over the text and checks for matches in O(nm) time in worst case. KMP algorithm which uses a preprocessing step to construct a lps array to avoid rematching characters, improving worst case to O(n).
*/

/*
we will use LPS of KMP for the string which is to be find

TC- (n+m)
*/

#include<iostream>
#include<vector>
using namespace std;

// LPS of KMP
void lpsOfKMP(string &s, vector<int> &lps)
{
    
    int pre = 0;
    int suf = 1;

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
            if(pre==0){
                lps[suf]=0;
                suf++;
            }
            else{
                pre = lps[pre-1];
            }
        }
    }
}


int findString(string &parent, string &child)
{
    vector<int> lps(child.size(),0);

    // making lps for child string;
    lpsOfKMP(child, lps);

    int first = 0;//-> for parent
    int second = 0;//-> for child

    while (second < child.size() && first < parent.size())
    {
        if(parent[first]==child[second])
        {
            first++;
            second++;
        }
        else{
            if(second==0){
                first++;
            }
            else{
                second = lps[second-1];
            }
        }
    }
    
    if(second == child.size()) return first-second;

    return -1;
}


int main()
{
    string str = "abcadaabceaabceaabdop";
    string child = "aabceaabdo";

    int ans = findString(str, child);

    cout << ans << endl;

    return 0;
}


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
Appraoch:- brute force
    -- string add kerte gye aur check bhi kerte gye
    -- TC: O(m^2 + m*n)

*/

#include<iostream>
#include<vector>
using namespace std;

int repeatedStringMatch(string a, string b)
{
    int ans = -1;
    string ss = a;

    int count = 1;
    while (true)
    {
        if(ss.size()<b.size()){
            ss += a;
            count++;
        }
        else if(ss.size()==b.size()){
            if(ss.find(b) != string::npos) {
                ans = count;
                break;
            }
            else{
                ss+=a;
                count++;
            }
        }
        else{
            if(ss.find(b) != string::npos){
                ans = count;
                break;
            }
            else{
                break;
            }
        }
    }

    // last checking
    ss+=a;
    count++;
    if(ans == -1 && ss.find(b) != string::npos){
        ans = count;
    }

    return ans;
}

int main()
{
    string a = "abcd";
    string b = "dabcdab";

    int ans = repeatedStringMatch(a,b);

    cout << ans << endl;

    return 0;
}
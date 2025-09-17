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
Appraoch:- 
    -- if a="abcd"
          b="cdabcdab" => "cd abcd ab";

    So, types of combination
        1. b = prefix + n*a + suffix => cd abcd ab ==> n+2
        2. b = prefix + n*a          => cd abcd   ==> n+1
        3. b = n*a + suffix          => abcd ab   ==> n+1
        4. b = n*a                   => abcd     ==> n

        ; n = (length(b)/length(a))

Note:-TC: O(n*m), Optimization using KMP(knuth-Morris-Pratt) -> see next solution
*/

#include<iostream>
#include<vector>
using namespace std;

int repeatedStringMatch(string a, string b)
{
    int len_b = b.length();
    int len_a = a.length();

    int n = (len_b)/(len_a);

    int cnt = n;

    string na = "";
    while (cnt--)
    {
        na = na+a;
    }

    // b = n*a, n wala case
    if(na.find(b) != string::npos){
        return n;
    }
    
    // b = n+1 wala cases
    na = na+a;
    if(na.find(b) != string::npos){
        return n+1;
    }

    // b = n+2 wala case
    na = na+a;
    if(na.find(b) != string::npos){
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
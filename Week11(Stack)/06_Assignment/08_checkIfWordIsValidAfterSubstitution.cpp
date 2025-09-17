/* -> 1003

Given a string s, determine if it is valid.

A string s is valid if, starting with an empty string t = "", you can transform t into s after performing the following operation any number of times:
    - Insert string "abc" into any position in t. More formally, t becomes tleft + "abc" + tright, where t == tleft + tright. Note that tleft and tright may be empty.

Return true if s is a valid string, otherwise, return false.

 

Example 1:
Input: s = "aabcbc"
Output: true
Explanation:
"" -> "abc" -> "aabcbc"
Thus, "aabcbc" is valid.

Example 2:
Input: s = "abcabcababcc"
Output: true
Explanation:
"" -> "abc" -> "abcabc" -> "abcabcabc" -> "abcabcababcc"
Thus, "abcabcababcc" is valid.

Example 3:
Input: s = "abccba"
Output: false
Explanation: It is impossible to get "abccba" using the operation.

*/

/*
Appraoch:- using find() function

    -- hame bola gya h ki ek kahli string 't' h aur hame 't' se 's' banana h 'abc' ka use kerke, so kyu na 's' se 't' jaya jaye, means 's' ko khali krenge abc ke bundle m

    -- using find() function, find the index of occurence of abc, and then modify string s by taking left and right string of found index, (just like we did in remove the occurrence of a string in main string question)

Note:- time comp: O(n^2), better appaoch-> see next solution
*/

#include<iostream>
#include<vector>
#include<algorithm>
#include<stack>
using namespace std;

bool isValid(string s)
{
    // base case
    if(s.size()==0){
        return true;
    }

    int found = s.find("abc");

    if(found != string::npos){
        // found 
        string tleft = s.substr(0, found);
        string tright = s.substr(found+3, s.size());

        return isValid(tleft+tright);
    }

    return false;
}

int main()
{
    string s = "abcabcababcc";

    if(isValid(s)) cout << "valid";
    else cout << "Invalid";

    return 0;
}
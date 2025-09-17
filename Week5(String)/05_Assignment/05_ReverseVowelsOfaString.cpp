/* -> 345

Given a string s, reverse only all the vowels in the string and return it.

The vowels are 'a', 'e', 'i', 'o', and 'u', and they can appear in both lower and upper cases, more than once.

 

Example 1:
Input: s = "hello"
Output: "holle"

Example 2:
Input: s = "leetcode"
Output: "leotcede"

*/

/*
Appraoch:- two pointer(i=0, j=n-1)
*/


#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;

bool checkVowels(char ch)
{
    ch = tolower(ch);
    
    if(ch=='a' || ch=='e' || ch=='i' || ch=='o' || ch=='u') return true;

    return false;
}

string reverseVowels(string s) 
{
    int i=0;
    int j=s.length()-1;

    while(i<j)
    {
        if(checkVowels(s[i]) && checkVowels(s[j])){
            swap(s[i], s[j]);
            i++;
            j--;
        }
        else if(!checkVowels(s[i])) i++;
        else j--;
    }

    return s;
}

int main()
{
    string s = "leetcode";

    cout << reverseVowels(s) << endl;

    return 0;
}
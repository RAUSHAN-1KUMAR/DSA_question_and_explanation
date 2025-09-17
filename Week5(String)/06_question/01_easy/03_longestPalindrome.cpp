/* -> 409

Given a string s which consists of lowercase or uppercase letters, return the length of the longest palindrome that can be built with those letters.

Letters are case sensitive, for example, "Aa" is not considered a palindrome.

 

Example 1:
Input: s = "abccccdd"
Output: 7
Explanation: One longest palindrome that can be built is "dccaccd", whose length is 7.

Example 2:
Input: s = "a"
Output: 1
Explanation: The longest palindrome that can be built is "a", whose length is 1.
*/

#include<iostream>
#include<algorithm>
#include<vector>
using namespace std;

int longestPalindrome(string s)
{
    vector<int> charHash(300,0);
    for(auto ch:s){
        charHash[ch]++;
    }

    int oddCount = 0;
    int evenCount = 0;
    for(int i=0 ; i<charHash.size() ; i++)
    {
        if(charHash[i]>0)
        {
            if(charHash[i]&1){
                oddCount = max(charHash[i],oddCount);
            }
            else{
                evenCount += charHash[i];
            }
        }
    }
    int total = oddCount+evenCount;

    // again odd count because we can use them by removing one char if they are greater than 1.
    int againOddCount=0;
    for(int i=0 ; i<charHash.size(); i++)
    {
        if(charHash[i]>1 && charHash[i]&1)
        {
            againOddCount += charHash[i]-1;
        }
    }
    if(oddCount>1) againOddCount -= oddCount-1;

    return total+againOddCount;
}


int main()
{
    string input = "bb";

    cout << longestPalindrome(input) << endl;

    return 0;
}
/* -> 13

Roman numerals are represented by seven different symbols: I, V, X, L, C, D and M.

Symbol       Value
I             1
V             5
X             10
L             50
C             100
D             500
M             1000

For example, 2 is written as II in Roman numeral, just two ones added together. 12 is written as XII, which is simply X + II. The number 27 is written as XXVII, which is XX + V + II.

Roman numerals are usually written largest to smallest from left to right. However, the numeral for four is not IIII. Instead, the number four is written as IV. Because the one is before the five we subtract it making four. The same principle applies to the number nine, which is written as IX. There are six instances where subtraction is used:

I can be placed before V (5) and X (10) to make 4 and 9. 
X can be placed before L (50) and C (100) to make 40 and 90. 
C can be placed before D (500) and M (1000) to make 400 and 900.

Given a roman numeral, convert it to an integer.


Example 1:
Input: s = "III"
Output: 3
Explanation: III = 3.

Example 2:
Input: s = "LVIII"
Output: 58
Explanation: L = 50, V= 5, III = 3.

Example 3:
Input: s = "MCMXCIV"
Output: 1994
Explanation: M = 1000, CM = 900, XC = 90 and IV = 4.
*/

/*
Appraoch:- hashing of roman to int data
    -- formed a vector to work like a stack, and used it to handle CM, CD, XC like cases i.e., ager koi value aa rha h to usko ans m sum kerne se pehle ye check ker the ki kya wo value vector ke right most element se bada h ya chota h, ager chota h to thik h ans m sum ker denge but ager bada h, it means we have the case like CD/CM/XC,etc, to iss case m ham phele ek decremented value nikalegen joo uss ans m sum hoga then usko ans m sum krengen.

Note:- there will be space complexity, so can we solve it with O(1) -> see next solution
*/

#include<iostream>
#include<vector>
#include<unordered_map>
#include<map>
using namespace std;

unordered_map<char, int> romanMap = {
    {'M',1000},
    {'D',500},
    {'C',100},
    {'L',50},
    {'X',10},
    {'V',5},
    {'I',1}
};

int romanToInt(string s)
{
    // initializing our vector stack
    vector<int> forStack;
    forStack.push_back(romanMap[s.front()]);

    int ans = forStack[0];

    for(int i=1 ; i<s.size() ; i++)
    {
        int stackRightMostIndex = forStack.size()-1;
        char ch = s[i];

        if(romanMap[ch]<=forStack[stackRightMostIndex]){
            ans += romanMap[ch];
        }
        else{
            int decrementValue = romanMap[ch]-(2*forStack[stackRightMostIndex]);

            ans += decrementValue;
        }

        forStack.push_back(romanMap[ch]);
    }

    return ans;
}


int main()
{
    string s1 = "MCMXCIV";
    string s2 = "LVIII";
    string s3 = "III";

    cout << romanToInt(s1) << endl;
    cout << romanToInt(s2) << endl;
    cout << romanToInt(s3) << endl;

    return 0;
}
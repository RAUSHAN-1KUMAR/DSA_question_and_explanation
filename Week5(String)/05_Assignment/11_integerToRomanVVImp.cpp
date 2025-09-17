/* -> 12

Seven different symbols represent Roman numerals with the following values:

Symbol	Value
    I	1
    V	5
    X	10
    L	50
    C	100
    D	500
    M	1000

Roman numerals are formed by appending the conversions of decimal place values from highest to lowest. Converting a decimal place value into a Roman numeral has the following rules:
    1. If the value does not start with 4 or 9, select the symbol of the maximal value that can be subtracted from the input, append that symbol to the result, subtract its value, and convert the remainder to a Roman numeral.
    2. If the value starts with 4 or 9 use the subtractive form representing one symbol subtracted from the following symbol, for example, 4 is 1 (I) less than 5 (V): IV and 9 is 1 (I) less than 10 (X): IX. Only the following subtractive forms are used: 4 (IV), 9 (IX), 40 (XL), 90 (XC), 400 (CD) and 900 (CM).
    3. Only powers of 10 (I, X, C, M) can be appended consecutively at most 3 times to represent multiples of 10. You cannot append 5 (V), 50 (L), or 500 (D) multiple times. If you need to append a symbol 4 times use the subtractive form.

Given an integer, convert it to a Roman numeral.

 

Example 1:
Input: num = 3749
Output: "MMMDCCXLIX"
Explanation:
3000 = MMM as 1000 (M) + 1000 (M) + 1000 (M)
 700 = DCC as 500 (D) + 100 (C) + 100 (C)
  40 = XL as 10 (X) less of 50 (L)
   9 = IX as 1 (I) less of 10 (X)
Note: 49 is not 1 (I) less of 50 (L) because the conversion is based on decimal places


Example 2:
Input: num = 58
Output: "LVIII"
Explanation:
50 = L
 8 = VIII


Example 3:
Input: num = 1994
Output: "MCMXCIV"
Explanation:
1000 = M
 900 = CM
  90 = XC
   4 = IV
*/

/*
Appraoch:-
    -- breaking form largest to smallest but for 4 and 9 their will be different. 

        So, we have list:
            Symbol	Value
                I	1
                V	5
                X	10
                L	50
                C	100
                D	500
                M	1000
        we will add some more pair into this list to handle digit for 4 and 9:-

            Symbol	Value
                I	1
                IV  4
                V	5
                IX  9
                X	10
                XL  40
                L	50
                XC  90
                C	100
                CD  400
                D	500
                CM  900
                M	1000
        we will make this by taking two array, one array of string and other array of int.

    -- So we will iterate to our array of int from largest to smaller and till num >= value of array and then ans(string) me roman Symbol ko add kro aur phir add kerne ke baad us roman ke respective integer value num se minus kerdo.  
*/

#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;

string intToRomanConversion(int num)
{
    // our roman to int mapped vector of size 13
    vector<string> romanSymbols = {"M", "CM", "D", "CD", "C", "XC", "L", "XL", "X", "IX", "V", "IV", "I"};

    vector<int> values = {1000,900,500,400,100,90,50,40,10,9,5,4,1};

    string ans = "";

    for(int i=0 ; i<13 ; i++)
    {
        while(num>=values[i]){
            ans += romanSymbols[i];
            num -= values[i];
        }
    }

    return ans;
}

int main()
{
    int num = 3994;

    cout << intToRomanConversion(num) << endl;

    return 0;
}
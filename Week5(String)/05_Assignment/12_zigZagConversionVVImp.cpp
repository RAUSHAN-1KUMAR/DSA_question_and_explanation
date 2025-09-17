/* -> 6

The string "PAYPALISHIRING" is written in a zigzag pattern on a given number of rows like this: (you may want to display this pattern in a fixed font for better legibility)

P   A   H   N
A P L S I I G
Y   I   R
And then read line by line: "PAHNAPLSIIGYIR"

Write the code that will take a string and make this conversion given a number of rows:

string convert(string s, int numRows);
 

Example 1:
    Input: s = "PAYPALISHIRING", numRows = 3
    Output: "PAHNAPLSIIGYIR"

Example 2:
    Input: s = "PAYPALISHIRING", numRows = 4
    Output: "PINALSIGYAHRPI"
    Explanation:
    P     I    N
    A   L S  I G
    Y A   H R
    P     I

Example 3:
    Input: s = "A", numRows = 1
    Output: "A"
*/


/*
Appraoch:-
*/

#include<iostream>
#include<vector>
#include<algorithm>
#include<limits.h>
using namespace std; 

string convert(string s, int numRows) 
{
    if(numRows==1) return s;

    // numRows strings
    vector<string> zigzag(numRows);

    int i = 0, row = 0;
    bool direction  = 1;//-> 1 means top to bottom

    // storing the character in our strings w.r.t zigzag
    while(true)
    {
        if(direction==1){
            while(row<numRows && i<s.size()){
                zigzag[row].push_back(s[i]);
                i++;
                row++;
            }
            row -= 2;
        }
        else{
            while (row>=0 && i<s.size())
            {
                zigzag[row].push_back(s[i]);
                i++;
                row--;
            }
            row = 1;
        }

        if(i>=s.size()) break;

        direction = !direction;
    }

    // using our formed strings to form final answer
    string ans = "";
    for(auto eachString:zigzag){
        for(auto eachChar:eachString){
            ans.push_back(eachChar);
        }
    }

    return ans;
}


int main()
{
    string s = "PAYPALISHIRING";
    int numRows = 4;

    cout << convert(s,numRows) << endl;

    return 0;
}


/* Include-Exclude pattern
 
Print the subsequences of a string
    -- subsequence are substrings of string with maintaining the relative position of characters of the string.

Example:-
    input:- "abc"
    output:- {a,b,c,ab,bc,ac,abc," "}
*/

#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;

void findSubsequences(string str, string output, int index)
{
    // base case
    if(index >= str.length()){
        // ans output string m build ho chuka h
        cout << output << ",";
        return;
    }

    //exclude
    findSubsequences(str,output, index+1);
    
    //include
    output.push_back(str[index]);
    findSubsequences(str,output, index+1); 
}


int main()
{
    string str = "ab";
    string ouput = "";
    int index = 0;

    findSubsequences(str, ouput, index);

    return 0;
}
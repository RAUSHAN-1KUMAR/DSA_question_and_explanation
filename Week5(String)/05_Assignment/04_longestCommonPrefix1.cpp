/* -> 14

Write a function to find the longest common prefix string amongst an array of strings.

If there is no common prefix, return an empty string "".

 

Example 1:
Input: strs = ["flower","flow","flight"]
Output: "fl"

Example 2:
Input: strs = ["dog","racecar","car"]
Output: ""
Explanation: There is no common prefix among the input strings.
*/

/*
My appraoch:- same approach but in optimized way
    -- pichle wale m count ko increase ker rhe the aur phir last m return kerte waqt substr ke use ker rhe the but iss approach m han ek string m character push krengen aur phir usko last m return krengen.

Time complexity:- O(n^2)
*/

#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;

string longestCommonPrefix(vector<string>& strs) 
{
    string ans;

    int i=0;
    while (true)    
    {
        char curr_ch = 0;

        for(auto str:strs)
        {
            if(i >= str.size()){
                curr_ch = 0;
                break;
            }   

            if(curr_ch==0) curr_ch = str[i];
            else if(str[i]!=curr_ch){
                curr_ch = 0;
                break;
            }
        }

        if(curr_ch==0) break;

        ans.push_back(curr_ch);
        i++;
    }

    return ans;    
}


int main()
{
    // vector<string> strs = {"cir", "car"};
    vector<string> strs = {"flower", "flow", "flight"};

    cout << longestCommonPrefix(strs) << endl;

    return 0;
}

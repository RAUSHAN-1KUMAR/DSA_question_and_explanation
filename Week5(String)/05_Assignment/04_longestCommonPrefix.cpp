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
My appraoch:- 
    -- her ek string ke pehle character ko check ker rhe h, phir dusre character ko check ker rhe h, phir teesre.
    -- har ek string pe character check kerte waqt ager last tak check ho jate to count++, means wo character sab m h,
    -- last m return substr(0, count);

Note:- time complexity(O(n^2))
*/

#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;

// brute force
string longestCommonPrefix(vector<string>& strs) 
{
    int firstLengthString = strs[0].length();

    // if only one string is present in our vector
    if(strs.size() == 1) return strs[0];

    int i = 0;
    int j = 0;
    int count = 0;

    while(i<firstLengthString)
    {
        char ch = strs[0][i];

        if(ch==0) return "";

        for(int i=1 ; i<strs.size() ; i++)
        {
            string eachString = strs[i];
            char eachChar = eachString[j];
            if(ch != eachChar) goto end;
            if(i==strs.size()-1) count++;
        }

        i++;
        j++;
    }

    end:
    if(count == 0) return "";

    return strs[0].substr(0,count);
}

// good approach
string longestCommonPrefix1(vector<string>& strs) 
{
    int n = strs.size();

    if(n==1)
        return strs[0];

    string curr = strs[0];
    for(int i=1 ; i<n ; i++)
    {
        string newstr = strs[i];
        int j=0;
        while(j<curr.size() && j<newstr.size())
        {
            if(curr[j]!=newstr[j])
                break;
            
            j++;
        }

        if(j==0){
            curr = "";
            break;
        }
        else
            curr = newstr.substr(0, j);
    } 

    return curr;   
}

int main()
{
    vector<string> strs = {"cir", "car"};

    cout << longestCommonPrefix(strs) << endl;

    return 0;
}
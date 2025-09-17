/* Q.No: 1209

You are given a string s and an integer k, a k duplicate removal consists of choosing k adjacent and equal letters from s and removing them, causing the left and the right side of the deleted substring to concatenate together.

We repeatedly make k duplicate removals on s until we no longer can.

Return the final string after all such duplicate removals have been made. It is guaranteed that the answer is unique.

 

Example 1:
Input: s = "abcd", k = 2
Output: "abcd"
Explanation: There's nothing to delete.


Example 2:
Input: s = "deeedbbcccbdaa", k = 3
Output: "aa"
Explanation: First delete "eee" and "ccc", get "ddbbbdaa" Then delete "bbb", get "dddaa"Finally delete "ddd", get "aa"


Example 3:
Input: s = "pbbcggttciiippooaais", k = 2
Output: "ps"
*/

/*
Approach:- similar to previous question
    -- newchar ko ans string m insert kerne se pehle check ker rhe ki kya wo last ke k-1 characters of ans ke equal h, ager ha to k-1 bar pop kerdo aur equal nhi h to newChar ko push kerdo ans wale string m

Note:- Time Complexity will be large( O(n*k) ), so is there any better approach??
*/


#include<iostream>
#include<string>
using namespace std;

bool areLastk_1CharsSame(string &ans, char &newch, int k_1)
{
    int it = ans.size()-1;

    for(int i=0; i<k_1; i++)
    {
        if(newch != ans[it]) return false;
        it--;
    }

    return true;
}

string removeDuplicate(string s, int k)
{
    string ans = "";

    for(int i =0 ; i<s.size() ; ++i) // O(n)
    {
        char &newch = s[i];

        if(ans.size() < k-1){
            ans.push_back(newch);
        }
        else{
            if(areLastk_1CharsSame(ans,newch,k-1)){
                for(int j=0 ; j<k-1 ; j++){
                    ans.pop_back();
                }
            }
            else{
                ans.push_back(newch);
            }
        }
    }

    return ans;
}


int main()
{
    string str = "deeedbbcccbdaa";

    string ans = removeDuplicate(str, 3);

    cout << ans << endl;

    return 0;
}




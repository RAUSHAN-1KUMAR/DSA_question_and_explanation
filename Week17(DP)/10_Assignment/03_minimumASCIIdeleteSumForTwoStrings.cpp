/* -> 712

Given two strings s1 and s2, return the lowest ASCII sum of deleted characters to make two strings equal.

 

Example 1:
    Input: s1 = "sea", s2 = "eat"
    Output: 231
    Explanation: Deleting "s" from "sea" adds the ASCII value of "s" (115) to the sum.
    Deleting "t" from "eat" adds 116 to the sum.
    At the end, both strings are equal, and 115 + 116 = 231 is the minimum sum possible to achieve this.


Example 2:
    Input: s1 = "delete", s2 = "leet"
    Output: 403
    Explanation: Deleting "dee" from "delete" to turn the string into "let", adds 100[d] + 101[e] + 101[e] to the sum.
    Deleting "e" from "leet" adds 101[e] to the sum.
    At the end, both strings are equal to "let", and the answer is 100+101+101+101 = 403.
    If instead we turned both strings into "lee" or "eet", we would get answers of 433 or 417, which are higher.
*/

/*
Approach:- hame bola gya h delete ker ke stings ko equal kerna h, to ham yahi chiz follow krengen, delete krengen jab tak equal na ho jaye
    cases: 
        1. s1 se ek delete kro
        2. s2 se ek delete kro
        3. s1 se delete mat kro
        4. s2 se delete mat kro
    
    but but but, ager tum delete kerke solve bhi ker doge, but isme phir dp kaise lagaoge -> not possible, aur ek baat ye O(4^n) jitna time complexity ja rha h so not a good approach

Another approach:- hame bola gya h delete kerne, but no need to delete bas exclude and include wala case laga ke sum_of[currect_index_wala_ASCII] kerna h
    cases:
        1. if s[i]==p[j]:
        2 else
            i) bas s ko aage badhao 
            ii) bas p ko aage badhao

        3. base case ko ache sambhalna hoga -> see in code
*/

#include<bits/stdc++.h>
using namespace std;

// approach1 -> bekar approach but sole kerte waqt dimaag m aa gya tha
int helper1(string &s1, int i, string &s2, int j)
{
    // base case
    if(s1==s2)  return 0;
    if(i>=s1.size()) return INT_MAX;
    if(j>=s2.size()) return INT_MAX;

    // s1 se ek erase kerdo
    string a = s1;
    a.erase(i,1);
    int data1 = helper1(a, i, s2, j);
    int caseA;
    if(data1!=INT_MAX) caseA = s1[i] + helper1(a, i, s2, j); 
    else caseA = INT_MAX;

    // s2 se ek erase kerdo
    string b = s2;
    b.erase(j, 1);
    int data2 = helper1(s1, i, b, j);
    int caseB;
    if(data2!=INT_MAX) caseB = s2[j] + helper1(s1, i, b, j);
    else caseB = INT_MAX;

    // s1 se delete mat kro
    int caseC = 0 + helper1(s1, i+1, s2, j);

    // s2 se delte mat kro
    int caseD = 0 + helper1(s1, i, s2, j+1);

    int ans = min(caseA, min(caseB, min(caseC, caseD)));

    return ans;
}


// approach2 -> good approach, O(2^n) time complexity
int helper(string &s1, int i, string &s2, int j)
{
    // base case
    if(i>=s1.size())
    {
        int sum=0;
        while(j != s2.size())
        {
            sum += s2[j];
            j++;
        }
        return sum;
    }

    if(j>=s2.size())
    {
        int sum=0;
        while (i!=s1.size())
        {
            sum+=s1[i];
            i++;
        }

        return sum;
    }


    int ans=0;
    if(s1[i]==s2[j])
    { 
        // koi deletion nhi => ASCII code add nhi hoga
        ans = 0 + helper(s1, i+1, s2, j+1);
    }
    else
    {
        // deletion hua s1 m -> ASCII code add hoga
        int caseA = s1[i] + helper(s1, i+1, s2, j);

        // deletion hua s2 m -> ASCII code add hoga
        int caseB = s2[j] + helper(s1, i, s2, j+1);

        ans = min(caseA, caseB);
    }

    return ans;
}

int minimumDeleteSum(string s1, string s2)
{
    int i=0;
    int j=0;

    int ans = helper(s1, i, s2, j);

    return ans;
}

int main()
{
    string s1 = "delete";
    string s2 = "leet";

    cout << minimumDeleteSum(s1, s2) << endl;

    return 0;
}
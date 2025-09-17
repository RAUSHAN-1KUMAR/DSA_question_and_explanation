/* -> 455

Assume you are an awesome parent and want to give your children some cookies. But, you should give each child at most one cookie.

Each child i has a greed factor g[i], which is the minimum size of a cookie that the child will be content with; and each cookie j has a size s[j]. If s[j] >= g[i], we can assign the cookie j to the child i, and the child i will be content. Your goal is to maximize the number of your content children and output the maximum number.

 

Example 1:
    Input: g = [1,2,3], s = [1,1]
    Output: 1
    Explanation: You have 3 children and 2 cookies. The greed factors of 3 children are 1, 2, 3. 
    And even though you have 2 cookies, since their size is both 1, you could only make the child whose greed factor is 1 content.
    You need to output 1.


Example 2:
    Input: g = [1,2], s = [1,2,3]
    Output: 2
    Explanation: You have 2 children and 3 cookies. The greed factors of 2 children are 1, 2. 
    You have 3 cookies and their sizes are big enough to gratify all of the children, 
    You need to output 2.

*/

/*
Approach:- 
    -- Sort both the arrays.
    -- Use two pointers i and j to traverse the greed factor array and the cookie size array
    -- If s[j] >= g[i] then we can satisfy the child i with cookie j so we increment both i and j and also increment the count of satisfied children
    -- Else we increment j to check for the next cookie
*/


#include<bits/stdc++.h>
using namespace std;

int findContentChildren(vector<int>& g, vector<int>& s) 
{
    sort(g.begin(), g.end());
    sort(s.begin(), s.end());

    int i=0; // for g
    int j=0; // for s

    int count=0;

    while(i<g.size() && j<s.size())
    {
        if(s[j]>=g[i])
        {
            count++;
            i++;
            j++;
        }
        else
        {
            j++;
        }
    }

    return count;
}

int main()
{
    vector<int> g = {1,2};
    vector<int> s = {1,2,3};
    cout<<findContentChildren(g,s)<<endl;
    return 0;
}
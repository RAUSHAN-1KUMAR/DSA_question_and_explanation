/* -> 3316

You are given a string 'source' of size n, a string 'pattern' that is a subsequence of source, and a sorted integer array 'targetIndices' that contains distinct numbers in the range [0, n - 1].

We define an operation as removing a character at an index idx from source such that:
    1. idx is an element of targetIndices.
    2. pattern remains a subsequence of source after removing the character.

Performing an operation does not change the indices of the other characters in source. For example, if you remove 'c' from "acb", the character at index 2 would still be 'b'.

Return the maximum number of operations that can be performed.

 

Example 1:
    Input: source = "abbaa", pattern = "aba", targetIndices = [0,1,2]
    Output: 1
    Explanation:
    We can't remove source[0] but we can do either of these two operations:
    Remove source[1], so that source becomes "a_baa".
    Remove source[2], so that source becomes "ab_aa".

Example 2:
    Input: source = "bcda", pattern = "d", targetIndices = [0,3]
    Output: 2
    Explanation:

    We can remove source[0] and source[3] in two operations.

Example 3:
    Input: source = "dda", pattern = "dda", targetIndices = [0,1,2]
    Output: 0
    Explanation:
    We can't remove any character from source.

Example 4:
    Input: source = "yeyeykyded", pattern = "yeyyd", targetIndices = [0,2,3,4]
    Output: 2
    Explanation:
    We can remove source[2] and source[3] in two operations.
*/

/*
Appraoch:- recursive
    Lets understand the logic:-
        1. track all the targetIndices in an unordered_map, and two varibale count and maxi.

        2. now we are gonna do recursive call as we do to just find the given subsequence is present in source string or not because at each removal or non removal we have to check subsequence still exits or not.

        3. if the current index is present in targetIndices than we have two cases either exclude it or not exclude it: 
            -- exluding will increment the count, and if at the end subsequence exists then store the count into maxi
            -- not excluding will also have two more case,
                i) if source[i]==source[j]
                ii) if not equal

        we have to return the maximum removal at once so at every current index present in targetIndices we will go with both the way not just one way.

This is not quiet a good approach because we have to return int so that we can apply DP-> see next solution
*/

#include<bits/stdc++.h>
using namespace std;

int maxi=0;

bool helper(string& source, string &pattern, int i, int j, unordered_map<int,bool> &ump, int count)
{
    // base cases 
    if(i>=source.size() && j<pattern.size()) return false;
    else if(i<source.size() && j>=pattern.size())
    {
        while(i<source.size())
        {
            if(ump[i])
                count++;
            i++;
        }

        maxi = max(maxi, count);
        return true;
    }
    else if(i>=source.size() && j>=pattern.size())
    {
        maxi = max(maxi,count);
        return true;
    }



    // if that index present in targetIndices then
    if(ump[i])
    {
        //caseOne: lets exclude it
        count++;
        bool caseC = helper(source, pattern, i+1, j, ump, count);
        count--; // backtrack must, because for caseTwo, we are not excluding that index so we have to decrement the incremented count
    }


    //caseTwo: lets include it(in which we have two more case, include and exclude also)
    if(source[i]==pattern[j])
    {
        bool caseA = helper(source, pattern, i+1, j+1, ump, count);
        return caseA;
    }

    bool caseB=helper(source, pattern, i+1, j, ump, count);

    return caseB;
}


int maxRemovals(string source, string pattern, vector<int> &targetIndices)
{
    // first mapping the targetIndices
    unordered_map<int,bool> ump;

    for(int i=0;i<targetIndices.size();i++)
        ump[targetIndices[i]] = true; 

    int count=0;
    bool ans = helper(source, pattern, 0, 0, ump, count);

    return maxi;
}


int main()
{
    string source = "yeyeykyded";
    string pattern = "yeyyd";
    vector<int> targetIndices = {0,2,3,4};

    cout << maxRemovals(source, pattern, targetIndices) << endl;

    return 0;
}


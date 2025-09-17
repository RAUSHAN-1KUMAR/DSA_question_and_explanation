/* -> 2381 (good question)

You are given a string s of lowercase English letters and a 2D integer array shifts where shifts[i] = [starti, endi, directioni]. For every i, shift the characters in s from the index starti to the index endi (inclusive) forward if directioni = 1, or shift the characters backward if directioni = 0.

Shifting a character forward means replacing it with the next letter in the alphabet (wrapping around so that 'z' becomes 'a'). Similarly, shifting a character backward means replacing it with the previous letter in the alphabet (wrapping around so that 'a' becomes 'z').

Return the final string after all such shifts to s are applied.

 

Example 1:
    Input: s = "abc", shifts = [[0,1,0],[1,2,1],[0,2,1]]
    Output: "ace"
    Explanation: Firstly, shift the characters from index 0 to index 1 backward. Now s = "zac".
    Secondly, shift the characters from index 1 to index 2 forward. Now s = "zbd".
    Finally, shift the characters from index 0 to index 2 forward. Now s = "ace".


Example 2:
    Input: s = "dztz", shifts = [[0,0,0],[1,1,1]]
    Output: "catz"
    Explanation: Firstly, shift the characters from index 0 to index 0 backward. Now s = "cztz".
    Finally, shift the characters from index 1 to index 1 forward. Now s = "catz".
*/

/*
Approach:-
    -- first calculating all the shifts for each index
    -- caculating all shift by using prefix sum, so that we can do it in O(n) time -> DIFFERENCE ARRAY TECHNIQUE
    -- and then for each index, i am shifting it

DIFFERENCE ARRAY TECHNIQUE:- Its kind of relative thing
    -- If you want to add/sub, let say add a value x to all elements between indices l and r (inclusive) in the original array arr[], you update the difference array as:
       i) diff[l]+=x and diff[r+1]-=x only, not all index from l to r indeces
       ii) and at last we can use prefix sum to find the original sum array: arr[i]=arr[i-1]+arr[i];

    -- Instead of applying a change across an entire range, you just mark the start of the change and the point where the change stops. This allows you to perform range updates in constant time. Later, you can easily compute the final result with a single pass through the array to accumulate the effects.

This technique is especially useful when there are multiple range updates and you want to avoid applying each update to every element in the range.
*/

/*
One more concept:
    1. modulo with positive number:-
        -- x%y -> remainder
    
    2. modulo with negative number:-
        -- (-x)%y -> y-remainder
*/


#include<bits/stdc++.h>
using namespace std;

char posetiveShift(char& ch, int &i){
    int totalVal = ch+i;
    totalVal -= 'a';

    return 'a'+(totalVal%26);
}

char negativeShift(char& ch, int &i){
    i*=-1;
    i = i%26;
    ch -= i;
    int gap = 'a'-ch;
    if(gap>0){
        return 'z'-gap+1;
    }
    return ch; 
}

string shiftingLetters(string s, vector<vector<int>>& shifts)
{
    vector<int> hash(4,0);
    for(auto &vec:shifts)
    {
        // using difference array technique to store the shifting
        if(vec[2]==0){
            hash[vec[0]]--;
            if(vec[1]<hash.size()-1) hash[vec[1]+1]++;
        }
        else{
            hash[vec[0]]++;
            if(vec[1]<hash.size()-1) hash[vec[1]+1]--;
        }
    }

    // now using prefix sum to find net movement for each index
    for(int i=1 ; i<hash.size() ; i++){
        hash[i] += hash[i-1];
    }


    // at last using the stored net movement
    for(int i=0 ; i<hash.size() ; i++){
        int index = i;
        int netMov = hash[i];
        if(netMov>0) s[index]=posetiveShift(s[index], netMov);
        else if(netMov<0) s[index]=negativeShift(s[index], netMov);
    }

    return s;
}

int main()
{
    string s = "dztz";
    vector<vector<int>> shifts = {
        {0,0,0},
        {1,1,1}
    };
    cout << shiftingLetters(s, shifts) << endl;

    return 0;
}

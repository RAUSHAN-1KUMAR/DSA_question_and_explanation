/* -> 2375

You are given a 0-indexed string pattern of length n consisting of the characters 'I' meaning increasing and 'D' meaning decreasing.

A 0-indexed string num of length n + 1 is created using the following conditions:

num consists of the digits '1' to '9', where each digit is used at most once.
If pattern[i] == 'I', then num[i] < num[i + 1].
If pattern[i] == 'D', then num[i] > num[i + 1].
Return the lexicographically smallest possible string num that meets the conditions.

 

Example 1:
    Input: pattern = "IIIDIDDD"
    Output: "123549876"
    Explanation:
    At indices 0, 1, 2, and 4 we must have that num[i] < num[i+1].
    At indices 3, 5, 6, and 7 we must have that num[i] > num[i+1].
    Some possible values of num are "245639871", "135749862", and "123849765".
    It can be proven that "123549876" is the smallest possible num that meets the conditions.
    Note that "123414321" is not possible because the digit '1' is used more than once.


Example 2:
    Input: pattern = "DDD"
    Output: "4321"
    Explanation:
    Some possible values of num are "9876", "7321", and "8742".
    It can be proven that "4321" is the smallest possible num that meets the conditions.
*/

/*
Approach:-this question have a lot approach, so we are look for it one by one
    1. brute force
        -- generate all possible pattern
        -- take a number:- 123456789, and then use next_permutation() function and find first pattern which is valid

        TC:- O(n!*n^2)
        SC:- O(n)

    2. see next solution
*/

#include<bits/stdc++.h>
using namespace std;

bool check(string &s, string &p) 
{
    for (int i = 0; i < p.size(); i++) 
    {
        if (p[i] == 'I') {
            if (s[i] > s[i + 1])//ager ulta h to return false
                return false;
        } else {
            if (s[i] < s[i + 1])// same here
                return false;
        }
    }

    return true;
}

string smallestNumber(string pattern) 
{
    int patternLength = pattern.size();
    string sequence = "";

    // Create a 12345..n
    for (int number = 1; number <= 1 + patternLength; number++) {
        sequence.push_back(number + '0');
    }

    string permutation = sequence;

    // Keep finding the next permutation until it matches the pattern
    while (!check(permutation, pattern)) //check fun -> O(n)
    {
        next_permutation(permutation.begin(), permutation.end());//O(n+1)! = O(n!*n)
    }

    return permutation;
}


int main()
{
    string pattern="IIIDDI";
    cout <<smallestNumber(pattern) << endl;
    return 0;
}
/* Q.no: 791

You are given two strings order and s. All the characters of order are unique and were sorted in some custom order previously.

Permute the characters of s so that they match the order that order was sorted. More specifically, if a character x occurs before a character y in order, then x should occur before y in the permuted string.

Return any permutation of s that satisfies this property.
 

Example 1:
Input: order = "cba", s = "abcd"
Output: "cbad"
Explanation: "a", "b", "c" appear in order, so the order of "a", "b", "c" should be "c", "b", and "a".
Since "d" does not appear in order, it can be at any position in the returned string. "dcba", "cdba", "cbda" are also valid outputs.

Example 2:
Input: order = "bcafg", s = "abcd"
Output: "bcad"
Explanation: The characters "b", "c", and "a" from order dictate the order for the characters in s. The character "d" in s does not appear in order, so its position is flexible.
Following the order of appearance in order, "b", "c", and "a" from s should be arranged as "b", "c", "a". "d" can be placed at any position since it's not in order. The output "bcad" correctly follows this rule. Other arrangements like "bacd" or "bcda" would also be valid, as long as "b", "c", "a" maintain their order.
*/

/*
Approach:- sort() + custom comparator
*/

#include<iostream>
#include<string>
#include<algorithm>
#include<vector>
using namespace  std;

// declared globally, to use inside custom comparator
string str;

bool compare(char char1, char char2)
{
    // this will return true, if positon of char 1 is less than char2 in str string.
    // if true, then char1 will be placed before char2 in s string i.e., as it is
    // if false, then char2 will be placed before char1 in s string.
    return (str.find(char1) < str.find(char2));
}

string customSortString(string order, string s)
{
    str = order;

    sort(s.begin(), s.end(), compare);

    return s;
}


int main()
{
    string order = "cba";
    string s ="abcd";

    cout << customSortString(order,s) << endl;

    return 0;
}
/* leetcode problem

You are given an array of integers nums of size 3

Return the maximum possible number whose binary representation can be formed by concatenationg the binary representation of all elements in nums in some order

Note that the binary representation of any number does not contain leading zeros.

Example1:
    Intput: nums = [1,2,3]
    output: 30
    Explanation: Concatenate the number in the order [3,1,2] to get the result "11110", which is the binary reperesentation of 30.

Example2:
    Input: nums = [2,8,16]
    output: 1296
    Explanation: Concatenate the numbers in the order [2,8,16] to get the result "10100010000", which is the binary representation of 1296.
*/

#include<bits/stdc++.h>

using namespace std;

int maxGoodNumber(vector<int> &nums)
{
    // sorted using a custom comparator defined by a lambda function:
    sort(nums.begin(), nums.end(), [](int a, int b)
    {
        // This creates a string of length 32 for each number, representing it in binary form.
        string one = bitset<32>(a).to_string();
        string two = bitset<32>(b).to_string();

        // trims off leading zeros by finding the first occurrence of '1'
        one = one.substr(one.find('1'));
        two = two.substr(two.find('1'));

        return (one + two) > (two + one);
    });// now our given vector nums, arranged in maximum form


    // now forming the answer
    string combined = "";
    for(auto n:nums)
    {
        string biny = bitset<32>(n).to_string();// converting into binary form
        combined += biny.substr(biny.find('1'));// concinating each element
    }

    // converts the binary string into a long long integer, treating the string as base 2.
    long long ans = stoll(combined, NULL, 2);

    return static_cast<int>(ans);// cast long long result to int before returning.
}


int main()
{
    vector<int> nums = {2,16,8};

    cout << maxGoodNumber(nums) << endl;

    return 0;
}


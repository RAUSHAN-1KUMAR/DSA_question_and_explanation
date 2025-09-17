
/* -> 3314

You are given an array nums consisting of n prime integers.

You need to construct an array ans of length n, such that, for each index i, the bitwise OR of ans[i] and (ans[i] + 1) is equal to nums[i], i.e. ans[i] OR (ans[i] + 1) == nums[i].

Additionally, you must minimize each value of ans[i] in the resulting array.

If it is not possible to find such a value for ans[i] that satisfies the condition, then set ans[i] = -1.

 

Example 1:
    Input: nums = [2,3,5,7]
    Output: [-1,1,4,3]
    Explanation:
    For i = 0, as there is no value for ans[0] that satisfies ans[0] OR (ans[0] + 1) = 2, so ans[0] = -1.
    For i = 1, the smallest ans[1] that satisfies ans[1] OR (ans[1] + 1) = 3 is 1, because 1 OR (1 + 1) = 3.
    For i = 2, the smallest ans[2] that satisfies ans[2] OR (ans[2] + 1) = 5 is 4, because 4 OR (4 + 1) = 5.
    For i = 3, the smallest ans[3] that satisfies ans[3] OR (ans[3] + 1) = 7 is 3, because 3 OR (3 + 1) = 7.

Example 2:
    Input: nums = [11,13,31]
    Output: [9,12,15]
    Explanation:
    For i = 0, the smallest ans[0] that satisfies ans[0] OR (ans[0] + 1) = 11 is 9, because 9 OR (9 + 1) = 11.
    For i = 1, the smallest ans[1] that satisfies ans[1] OR (ans[1] + 1) = 13 is 12, because 12 OR (12 + 1) = 13.
    For i = 2, the smallest ans[2] that satisfies ans[2] OR (ans[2] + 1) = 31 is 15, because 15 OR (15 + 1) = 31.
*/

/*
Appraoch:- 
- lets observe first:-
    x       = 0010010111
    x+1     = 0010011000 -> uptill first 0, all the bits are flipped
    x|(x+1) = 0010011111 -> first 0 become 1 and all bits remain same

    Now we want this 0010011111 = y, minmimum x.

- So now we will reverse the question, we have y = 0010011111 and which minimum no. from this y can become a number x such that x|(x+1)=y i.e., we want our y back
- as we know x|(x+1) convert the first 0 to 1, so we will flip the last 1 of first consecutive 1's i.e., 00100 1 1111, So our minimum x such that x|x+1 = y is 00100 0 1111

What if y = 00010 i.e., even number, so for even number answer will be -1
*/

#include<bits/stdc++.h>
using namespace std;

vector<int> minBitwiseArray(vector<int> &nums)
{
    vector<int> ans;
    for(auto num:nums)
    {
        if(num==2){
            ans.push_back(-1);
            continue;
        }

        // j represents the position in 32bit
        // num = 0010110111
        // j   = 0000001000; j=3, we are using j to find the first 0 position and then j-1 to find the last 1 of first consecutive 1's
        for(int j=1 ; j<31 ; j++)
        {
            // we are taking 1 = 0001 and left shifting it on value j
            // using & operator because if num = 3 = 0011 and 1<<2 = 0100, and then 0011 & 0100 = 0000. So & operator will tell which j value catches the first 0.
            if(num & (1<<j)) continue;

            // we have a j=2 for num=3, j=2 catches the first 0 in num and we have to convert the last 1 of first consecutive 1's, and the last one will be at 1<<(j-1)
            // doing xor becuase, XOR convert the equal bits to 0.
            ans.push_back(num^(1<<(j-1)));

            break;
        }
    }

    return ans;
}

int main()
{
    vector<int> nums = {2,3,5,7};

    vector<int> ans = minBitwiseArray(nums);

    for(int num:ans)
    {
        cout << num << " ";
    }

    return 0;
}
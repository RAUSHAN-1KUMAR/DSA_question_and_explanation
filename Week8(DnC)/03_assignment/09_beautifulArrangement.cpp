/* -> 526

Suppose you have n integers labeled 1 through n. A permutation of those n integers perm (1-indexed) is considered a beautiful arrangement if for every i (1 <= i <= n), either of the following is true:
    - perm[i] is divisible by i.
    - i is divisible by perm[i].

Given an integer n, return the number of the beautiful arrangements that you can construct.


Example 1:
Input: n = 2
Output: 2
Explanation: 
The first beautiful arrangement is [1,2]:
    - perm[1] = 1 is divisible by i = 1
    - perm[2] = 2 is divisible by i = 2
The second beautiful arrangement is [2,1]:
    - perm[1] = 2 is divisible by i = 1
    - i = 2 is divisible by perm[2] = 1


Example 2:
Input: n = 1
Output: 1
*/

/*
Approach:-
    1. Brute force:-(TLE)
        - find all permuations from 1 to n and then extract out beautiful ones linearly.

    2. better:- let say we have n=3 i.e., three spaces, we will put the element one by one checking the required condition given in question.
        - _ _ _: if we put 1 at index 1 then 2 at index 2 then 3 at index 3 i.e., 1 2 3 -> valid
        - _ _ _: if we put 1 at index 2 then 2 at index 1 then 3 at index 3 i.e., 2 1 3 -> valid
        - _ _ _: if we put 1 at index 3 then 2 at index 1 then 3 and index 2 but the 3 at index 2 is not satifying the condition, so -> not valid
        - _ _ _: if we put 1 at index 3 then 2 at index 2 then 3 at index 1 i.e., 3 2 1 -> valid

        So what we are doing, instead of finding all permutation, i am going through all putting posibilities of each character 

                        1,2,3
            ______________|_____________
            |             |             |  -> 1 at index 1, index 2, index 3.
            1             1             1   remember, if its position satisfies the given condition then we proceed.
        (2 and 3      (1 and 3)     (1 and 2)
        index are
        left for 2.
        So, we will
        proceed in
        all left
        posibility)

Note:- hame bas count return kerna h naki all posible vector.                       
*/

#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;

void countArrangement_helper(vector<int> &v, int &n, int &ans, int currNum)
{
    // base case
    if(currNum == n+1){
        ++ans; 
        return;
    }

    for(int i=1; i<=n ; i++) 
    {
        // checking the position is unoccupied and given conditions
        if(v[i]==0 && (currNum%i==0 || i%currNum==0)){
            v[i] = currNum;
            countArrangement_helper(v,n,ans,currNum+1);
            v[i] = 0;//-> backtracking
        }
    }
}

int countArrangement(int n)
{
    // n+1 size to start form index 1(we will leave the 0th index as it is)
    vector<int> v(n+1);//-> value initialized to 0
    int ans = 0;

    countArrangement_helper(v,n,ans,1);

    return ans;
}


int main()
{
    int n = 3;

    int ans = countArrangement(n);

    cout << ans << endl;

    return 0;
}


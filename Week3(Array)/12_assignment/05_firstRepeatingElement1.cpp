/*
Question:- Given an array arr[] of size n, find the first repeating element. The element should occur more than once and the index of its first occurence should be the smallest

Note:- The position you return should be according to 1-based indexing.

Example:-
    input: arr[] = {1,5,3,4,3,5,6}, n = 7
    output: 2
    Explanation: 5 is occuring twice and its first appearance is at index 2 which is less than 3 whose first occuring index is 3.
*/

/*
Approach:- We are using a concept called hashing using 'map' STL, to stored the occurence of each element of the array(nums).
*/

#include<iostream>
#include<vector>
#include<map>
using namespace std;

int repeatingNumber(vector<int> &nums)
{
    map<int, int> hash;
    for(int i = 0 ; i<nums.size() ; i++){
        hash[nums[i]]++;
    }

    for(int i = 0 ; i<nums.size() ; i++){
        if(hash[nums[i]]>1){
            return i+1;
        }
    }

    return -1;
}


int main()
{
    vector<int> vec = {1,5,1,4,3,5,6};

    cout << repeatingNumber(vec);

    return 0;
}
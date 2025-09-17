/*
Question:- Given an array arr[] of size n, find the first repeating element. The element should occur more than once and the index of its first occurence should be the smallest

Note:- The position you return should be according to 1-based indexing.

Example:-
    input: arr[] = {1,5,3,4,3,5,6}, n = 7
    output: 2
    Explanation: 5 is occuring twice and its first appearance is at index 2 which is less than 3 whose first occuring index is 3.
*/

/*
Approach:- In this solution we are building our own map, So how?
    -- find the maximum element in the given array(nums).
    -- make another array(for example hash) of size to that maximum element
    -- now do 'hash[nums[i]]++', this will store the count of occurence of each element of nums in hash array
*/

#include<iostream>
#include<vector>
#include<map>
#include<limits>
using namespace std;

int repeatingNumber(vector<int> &nums)
{
    int size = nums.size();

    // finding maximum element;
    int max = 0;
    for(int i = 0 ; i<size ; i++){
        if(nums[i]>max) max = nums[i];
    }

    // storing the count of occurence in new array hash
    vector<int> hash (max+1,0);
    for(int i = 0 ; i<nums.size() ; i++){
        hash[nums[i]]++; //-> hash[nums[i]] = hash[nums[i]] + 1
    }

    //printing the first occurence
    for(int i = 0 ; i<hash.size() ; i++){
        if(hash[nums[i]]>1) return i+1;
    }
    
    return -1;
}


int main()
{
    vector<int> vec = {0,5,1,4,3,5,6};
    
    cout << repeatingNumber(vec);


    return 0;
}
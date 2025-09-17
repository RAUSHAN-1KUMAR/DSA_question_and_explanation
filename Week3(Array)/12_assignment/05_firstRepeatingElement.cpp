/*
Question:- Given an array arr[] of size n, find the first repeating element. The element should occur more than once and the index of its first occurence should be the smallest

Note:- The position you return should be according to 1-based indexing.

Example:-
    input: arr[] = {1,5,3,4,3,5,6}, n = 7
    output: 2
    Explanation: 5 is occuring twice and its first appearance is at index 2 which is less than 3 whose first occuring index is 3.
*/

/*
Approach:- I have used two for loop to iterate the array for each element and returning index+1 for the repeating element.
*/

#include<iostream>
#include<vector>
using namespace std;

int repeatingNumber(vector<int> &nums)
{
    int size = nums.size();
    for(int i = 0 ; i<size ; i++){
        for(int j = i+1 ; j<size ; j++){
            if(nums[i]==nums[j]){
                return i+1;
            }
        }
    }
}


int main()
{
    vector<int> vec = {1,5,3,4,3,5,6};

    cout << repeatingNumber(vec);

    return 0;
}
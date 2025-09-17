/* -> 189
Given an integer array nums,, rotate the array to the right by k steps, where k in non-negative

Example:-
    input: nums = [1,2,3,4,5,6,7], k=3
    output: [5,6,7,1,2,3,4]

    input: nums = [-1, -100, 3, 99], k=2
    output: [3,99,-1,-100]

Explanation:
    if k = 1, output: [7,1,2,3,4,5,6]
    if k = 2, output: [6,7,1,2,3,4,5]
    if k = 3, output: [5,6,7,1,2,3,4]
*/

/*
-- applying reversal method
    1. reverse the whole array from 0 to n-1.
    2. again reverse the array from 0 to k-1.
    3. again reverse the array from k to n-1.
but what if the value of k is greater than n??,-> the above method will not be applicable.
    So, at first we have to do this: 'k = k%nums.size()'

Note:- time complexity of reverse() function is O(n).
*/

#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;


void sortColors(vector<int> &nums, int k)
{
    while (k>nums.size())
    {
        k -= nums.size();
    }
    
    reverse(nums.begin(), nums.end());// 0 to n-1
    reverse(nums.begin(), nums.begin()+k);// 0 to k-1
    reverse(nums.begin()+k, nums.end());// k to n-1
}

void display(vector<int> &v){
    for(int i = 0 ; i<v.size() ; i++){
        cout << v[i] << " ";
    }
    cout << endl;
}


int main()
{
    vector<int> vec{1,2,3,4,5,6,7};
    int rotate;
    cout << "Enter the rotation value: ";
    cin >> rotate;

    cout << "Before rotation: " << endl;
    display(vec);

    sortColors(vec,rotate);

    cout << "After rotation: " << endl;
    display(vec);

    return 0;
}


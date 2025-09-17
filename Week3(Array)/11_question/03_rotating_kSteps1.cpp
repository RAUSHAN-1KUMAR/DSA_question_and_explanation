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
Approach:- Using modulus operator
    -- we are declaring an another vector and storing the value from original vector to it in rotated position.

Note:- in case of rotation, use this modulus concept
*/


#include<iostream>
#include<vector>
using namespace std;


void sortColors(vector<int> &nums, int k){
    int n = nums.size();
    vector<int> ans(n);

    for(int i = 0 ; i<n ; i++)
    {
        int newIndex = (i+k)%n;// this will rotate after a fix value, depends on value of k
        ans[newIndex] = nums[i];
    }

    nums = ans;// to copy the elements of ans to nums
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

    if(rotate > vec.size()){
        rotate = rotate%7;
    }

    cout << "Before rotation: " << endl;
    display(vec);

    sortColors(vec,rotate);

    cout << "After rotation: " << endl;
    display(vec);

    return 0;
}


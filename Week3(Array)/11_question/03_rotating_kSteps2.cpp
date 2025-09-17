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
In the previous solutions there is a space complexity of O(n) because we were declaring a new another vector whose size depends on k or n.

So now is there any solution for this question having space complexity of O(1).
    -- yes, single rotate k times.
*/

#include<iostream>
#include<vector>
using namespace std;


void sortColors(vector<int> &nums, int k)
{
    int n = nums.size();

    for(int j = 0 ; j<k ; j++){
        int last = nums[n-1];
        for(int i = n-1 ; i>=1 ; i--){
            nums[i]=nums[i-1];
        }
        nums[0]=last;
    }
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
        rotate = rotate/7;
    }

    cout << "Before rotation: " << endl;
    display(vec);

    sortColors(vec,rotate);

    cout << "After rotation: " << endl;
    display(vec);

    return 0;
}


/* -> 75

Given an array 'nums' with n objects colored red, white, or blue, sort them in-place so that objects of the same color are adjacent, with the colors in the order red, white and blue.

we will use the integers 0, 1 and 2 to represent the color red, white, and blue respectively.

Ex:-
    input: nums-> 0,1,1,2,0,2,1
    output: 0,0,1,1,1,2,2
*/

/*
Approach:- first I sorted 0's and then sorted 1's, So automatically 2's align to end
*/

// there is a catch in this question if we use three pointer and only one while loop, see next solution

#include<iostream>
#include<vector>
using namespace std;


void sortColors(vector<int> &nums){
    int start = 0;
    int i = 0;

    while(i<nums.size()){
        if(nums[i]==0) {
            swap(nums[start],nums[i]);
            start++;
        }
        i++;
    }

    i = start;

    while(i<nums.size()){
        if(nums[i]==1){
            swap(nums[start],nums[i]);
            start++;
        }
        i++;
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
    vector<int> vec{0,1,1,2,2,2,0};

    cout << "Before arranging: " << endl;
    display(vec);

    sortColors(vec);

    cout << "After arranging: " << endl;
    display(vec);

    return 0;
}

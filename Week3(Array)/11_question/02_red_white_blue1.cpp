/* -> 75
Given an array 'nums' with n objects colored red, shite, or blue, sort them in-place so that objects of the same color are adjacent, with the colors in the order red, white and blue.

we will use the integers 0, 1 and 2 to represent the color red, white, and blue respectively.

Ex:-
    input: nums-> 0,1,1,2,0,2,1
    output: 0,0,1,1,1,2,2
*/

/*
Appraoch:- three pointer + single while loop
*/


#include<iostream>
#include<vector>
using namespace std;


void sortColors(vector<int> &nums){
    int n = nums.size();
    int index = 0;
    int left = 0;
    int right = n-1;

    while(index <= right){
        if(nums[index] == 0){
            swap(nums[index], nums[left]);
            left++;
            index++;
        }
        else if(nums[index]==2){
            swap(nums[index], nums[right]);
            right--;
            //catch -> no need of index++
            //index++;
        }
        else{
            index++;
        }
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

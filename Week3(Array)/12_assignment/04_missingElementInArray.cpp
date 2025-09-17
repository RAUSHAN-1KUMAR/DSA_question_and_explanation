/*
Question:- Find the missing elements from an array with dublicates, size of array is n and the elements of array lie b/w [1-n].
        -- What if more than one element is missing
*/

/*
Approach:- using nested for loop
    -- I have applied the same approach as before(traversing a loop form '0 to nums.size()' and checking each value in nums using linear search), but the time complexity will be O(n^2),

    Note:-This approach is applicable for more than one missing element.

lets look for a different approach using one for loop
*/

#include<iostream>
#include<vector>
using namespace std;

void missingNumber(vector<int> &nums)
{
    int size = nums.size();
    int j;
    for(int i = 1 ; i<=size ; i++)
    {
        for(j = 0 ; j<size ; j++)
        {
            if(i==nums[j]){
                break;
            }
        }
        if(j==size){
            cout << i << " ";
        }
    }

}


int main()
{
    vector<int> vec = {1,2,2,2,5};

    missingNumber(vec);

    return 0;
}
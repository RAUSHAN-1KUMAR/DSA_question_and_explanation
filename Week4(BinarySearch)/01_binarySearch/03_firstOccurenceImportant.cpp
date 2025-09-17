/*
Find the first occurence of a number in a sorted array using binary search
*/

/*
Approach:- 
    -- first apply the binary search till you get the number, when you got the number store its index into a variable and now look for the left part only, because if your current element is not the first occurence then the first occurence will lie left of it. 
*/

#include <iostream>
using namespace std;

int firstOccurence(int arr[], int n, int target)
{
    int start = 0;
    int end = n-1;

    int mid = start + (end - start)/2;

    int ans = -1;

    while(start<=end)
    {
        // here is the catch, we have to store the index and then look for the left part.
        if(arr[mid]==target){
            ans = mid;
            end = mid-1;
        }
        else if(target>arr[mid]) start = mid+1;
        else end = mid-1;

        // mid updation
        mid = (start+end)/2;
    }

    return ans;
}


int main() 
{
    int array[] = {10,20,30,30,30,30,40,50};
    int target = 30;
    int n = sizeof(array) / sizeof(array[0]);

    int result = firstOccurence(array, n, target);

    (result == -1) ? cout << "Element not found" : cout << "First occurence of element found at index: " << result;

    return 0;
}
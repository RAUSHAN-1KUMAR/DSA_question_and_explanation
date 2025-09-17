// Binary Search in C++
// applicable only if data is sorted.

/*
Type of question form in binary search in:
    1. normal classical code
    2. search space
    3. pedicate function (predicate function are those function that returns a boolean value, used to make decisions in algorithm. Often acting as conditions to filter or evaluate elements in a data structure.)
    4. index logic
*/

#include <iostream>
using namespace std;

int binarySearch(int arr[], int n, int target)
{
    int start = 0;
    int end = n-1;

    while(start<=end)
    {    
        // int mid = (start+end)/2; -> In case of large no. of elements in array, the value of (start+end) may exceeds INT_MAX;
        int mid = start + (end - start)/2;
        // int mid = start/2 + end/2; -> we can also do this.
        
        if(arr[mid]==target) return mid;
        else if(target>arr[mid]) start = mid+1;
        else end = mid-1;
    }

    return -1;
}


int main() 
{
    int array[] = {10,20,30,40,50,60,70,80,90};
    int target = 90;;
    int n = sizeof(array) / sizeof(array[0]);

    int result = binarySearch(array, n, target);

    (result == -1) ? cout << "Element not found" : cout << "Element found at index: " << result;

    return 0;
}


/*
Question:-
    -- Given an array of length N consisting of only 0s and 1s in random order. Modify the array to agregate 0s on left side and 1s on the right side of the array
*/

#include<iostream>
using namespace std;

class Solution{
    public:
        void segregate0sand1s(int arr[], int n){
            int l = 0; 
            int h = n-1;
            while(l<h){
                // increment of l if arr[l] is 0
                while(arr[l]==0 && l<h){
                    l++;
                }

                // decrement of h if arr[h] is 1
                while(arr[h]==1 && l<h){
                    h--;
                }

                // swap 
                swap(arr[l], arr[h]);
                l++;
                h--;
            }
        }
};

int main()
{

    return 0;
}
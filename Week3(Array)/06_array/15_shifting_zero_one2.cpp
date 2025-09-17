/*
Question:-
    -- Given an array of length N consisting of only 0s and 1s in random order. Modify the array to segregate 0s on left side and 1s on the right side of the array
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
                if(arr[l]==0){
                    l++;
                }

                // decrement of h if arr[h] is 1
                else if(arr[h]==1){
                    h--;
                }

                // swap 
                else{
                    swap(arr[l++], arr[h--]);
                }
            }
        }
};

int main()
{

    return 0;
}
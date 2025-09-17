/*

Given an array 'Arr' of N positive integers and another number X. Determine whether or not there exist two elements in Arr whose sum is exactly: X,

Example 1:
    Input: N = 6, X = 16, Arr[] = {1,4,45,6,10,8}
    Output: yes
    Explanation: Arr[3]+Arr[4] = 6+10 = 16 = X
*/

/*
Approach:- Brute force 
    -- Find all pairs & check their sum equal to X, using nested for loop.

Time Complexity will be O(n^2), find another lighter solution
*/

#include<iostream>
using namespace std;

bool checkingPair(int arr[], int size, int x)
{
    for(int i = 0 ; i<size ; i++){
        for(int j = i+1 ; j<size ; j++){
            if(arr[i]+arr[j]==x) return true;
        }
    }
    return false;
}


int main()
{
    int Arr[] = {1,4,45,6,10,8};
    int x = 13;
    int n = sizeof(Arr)/sizeof(int);

    if(checkingPair(Arr, n, x)){
        cout << "true";
    }
    else{
        cout << "false";
    }

    return 0;
}


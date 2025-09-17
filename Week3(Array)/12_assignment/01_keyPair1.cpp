/*
Given an array 'Arr' of N positive integers and another number X. Determine whether or not there exist two elements in Arr whose sum is exactly: X,

Example 1:
    Input: N = 6, X = 16, Arr[] = {1,4,45,6,10,8}
    Output: yes
    Explanation: Arr[3]+Arr[4] = 6+10 = 16 = X
*/

/*
Approach:- first sorting the given array and then using two pointer method
    -- one pointer at end, and other pointer at start
*/

#include<iostream>
#include<algorithm>
using namespace std;

bool checkingPair(int arr[], int size, int x)
{
    int l = 0;
    int h = size-1;
    while(l<h)
    {
        int sum = arr[l]+arr[h];

        if(sum == x) return true;
        else if(sum>x) h--;// sum is greater than x, it means current pair is high and so we have to move the high index to left
        else l++;// sum is less than x, it means current pair is low and so we have to move the low index to right
    }
    return false;
}


int main()
{
    int Arr[] = {1,4,45,6,10,8};
    int x = 16;
    int n = sizeof(Arr)/sizeof(int);

    sort(Arr,Arr+n);

    if(checkingPair(Arr, n, x)){
        cout << "true";
    }
    else{
        cout << "false";
    }

    return 0;
}



/*
Question:- we are given an array and a vector, we have to insert all the even numbers from the array into the given vector.

Ek case solve kero baki case ka recursion answer lake dega + handle the base case
*/


#include<iostream>
#include<vector>
#include<limits.h>
using namespace std;

void insertingEven(int arr[],int index, int n, vector<int> &ans)
{
    // base case
    if(index >= n) return;

    // ek case solve kro
    if(arr[index]%2==0) ans.push_back(arr[index]);

    // baki recursion p chod do
    insertingEven(arr, index+1, n, ans);
}

int main()
{
    int a[] = {10,11,12,13,14};
    vector<int> ans;

    insertingEven(a,0,5,ans);

    for(auto ele:ans){
        cout << ele << endl;
    }

    return 0;
}

/*
Question:- we are given an array and an element, we have to return all the index of occurrence of that number from the given array.
*/

#include<iostream>
#include<vector>
#include<limits.h>
using namespace std;

vector<int> findIndex(int a[], int index, int n, int element)
{
    vector<int> ans;

    if(index>=n) return ans;

    if(a[index]==element) ans.push_back(index);

    vector<int> aageKaAns = findIndex(a,index+1, n, element);

    for(auto ele:aageKaAns){
        ans.push_back(ele);
    }

    return ans;
}

int main()
{
    int arr[] = {10,20,10,10,20,30,50,10};

    vector<int> indexes = findIndex(arr,0,8,10);

    for(auto ele:indexes)
    {
        cout << ele << " ";
    }

    return 0;
}


#include<iostream>
#include<vector>
using namespace std;

int binarySearch(vector<int> arr, int key, int start, int end)
{
    
    // base case
    if(start > end) return -1;

    //processing(ek case khud solve kro)
    int mid = start + (end-start)/2;
    if(arr[mid]==key) 
        return mid;
    
    // baki recursion sambhal lega
    if(key>arr[mid]){
        // right m jao
        int aageKaAns = binarySearch(arr, key, mid+1, end);
        return aageKaAns;
    }
    else{
        // left m jao
        int aageKaAns = binarySearch(arr, key, start, mid-1);
        return aageKaAns;
    }
}


int main()
{
    vector<int> bin = {6,10,12,15,23,25,33,40};
    int element = 25;
    int s = 0;
    int e = bin.size()-1;

    int index = binarySearch(bin, element, s, e);

    cout << "Your given element " << element << " found at index: " << index;

    return 0;
}
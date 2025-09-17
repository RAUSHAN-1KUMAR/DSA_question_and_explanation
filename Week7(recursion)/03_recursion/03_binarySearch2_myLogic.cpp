
#include<iostream>
#include<vector>
using namespace std;

int binarySearch(vector<int> &bin, int element, int start, int end)
{
    int ans = -1;

    // base case -> the stopage case of recursive call
    if(start>end) return ans;

    int mid = (start+end)/2;

    if(bin[mid]==element){
        ans = mid;
    }
    else if(bin[mid]>element){
        ans = binarySearch(bin, element, start, mid-1);
    }
    else{
        ans = binarySearch(bin, element, mid+1, end);
    }

    return ans;
}

int main()
{
    vector<int> bin = {6,10,12,15,23,25,33,40};
    int element = 40;
    int s = 0;
    int e = bin.size()-1;

    int index = binarySearch(bin, element, s, e);

    cout << "Your given element " << element << " found at index: " << index;

    return 0;
}
/* GFG

Given two sorted arrays a[] and b[] and an element k, the task is to find the element that would be at the kth position of the combined sorted array.

Examples :
    Input: a[] = [2, 3, 6, 7, 9], b[] = [1, 4, 8, 10], k = 5
    Output: 6
    Explanation: The final combined sorted array would be [1, 2, 3, 4, 6, 7, 8, 9, 10]. The 5th element of this array is 6.


    Input: a[] = [100, 112, 256, 349, 770], b[] = [72, 86, 113, 119, 265, 445, 892], k = 7
    Output: 256
    Explanation: Combined sorted array is [72, 86, 100, 112, 113, 119, 256, 265, 349, 445, 770, 892]. The 7th element of this array is 256.
*/

#include<bits/stdc++.h>
using namespace std;

int kthElement(vector<int>& a, vector<int>& b, int k)
{
    int n = a.size();
    int m = b.size();

    int kthElement;

    int i=0;
    int j=0;
    int cnt=0;
    while(i<n && j<m)
    {
        if(a[i]<=b[j]){
            if(cnt==k-1) kthElement = a[i];
            cnt++;
            i++;
        }
        else{
            if(cnt==k-1) kthElement = b[j];
            cnt++;
            j++;
        }
    }

    while(i<n){
        if(cnt==k-1) kthElement = a[i];
        i++;
        cnt++;
    }

    while(j<m){
        if(cnt==k-1) kthElement = b[j];
        cnt++;
        j++;
    }

    return kthElement;
}


int main()
{
    vector<int> a = {100,112,256,349,770};
    vector<int> b = {72,86,113,119,265,445,892};
    int k = 7;

    cout << kthElement(a, b, k) << endl;

    return 0;
}
/*
Given sorted k array, merge them to form single sorted array
*/

/*
Approach:- MergeSort
    -- How we will apply the mergeSort because in this case we have whole array instead of single element
        -- we will, by treating each array as a single unit and the whole 2D vector as single array

TC:- O(n*k*logk)
SC:- O(n*k)
*/

#include<bits/stdc++.h>
using namespace std;

void mergeArrays(vector<int> &arrLow, vector<int> &arrHigh, vector<int> &res)
{
    int lowsize=arrLow.size();
    int highsize=arrHigh.size();

    int i=0;// for arrLow
    int j=0;// for arrHigh
    int k=0;// for res

    while(i<lowsize && j<highsize)
    {
        if(arrLow[i]<arrHigh[j]){
            res.push_back(arrLow[i]);
            i++;
        }
        else{
            res.push_back(arrHigh[j]);
            j++;
        }
    }

    while(i<lowsize)
    {
        res.push_back(arrLow[i]);
        i++;
    }

    while(j<highsize)
    {
        res.push_back(arrHigh[j]);
        j++;
    }
}


void mergeKSortArrays(vector<vector<int>> &arr, int s, int e, vector<int> &res)
{
    // if we got only one array
    if(s==e)
    {
        res=arr[s];
        return;
    }

    // if we got two array
    if(e-s==1)
    {
        mergeArrays(arr[s], arr[e], res);
        return;
    }

    int mid=(s+e)/2;

    // this two vector are used to store the sorted half, instead of sorting the main arr
    vector<int> firstHalf;
    vector<int> secondHalf;

    mergeKSortArrays(arr, s, mid, firstHalf);
    mergeKSortArrays(arr, mid+1, e, secondHalf);

    mergeArrays(firstHalf, secondHalf, res);
}


int main()
{
    vector<vector<int>> arr = {
        {2,6,12,34},
        {1,9,20,1000},
        {23,34,90,2000}
    };

    vector<int> res;

    int start=0;
    int end=arr.size()-1;
    mergeKSortArrays(arr, start, end, res);

    cout << "Printing answer array: " << endl;

    for(int i=0 ; i<res.size() ; i++)
    {
        cout << res[i] << " ";
    }
    cout << endl;

    return 0;
}


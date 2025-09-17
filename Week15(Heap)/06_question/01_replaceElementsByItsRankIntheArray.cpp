/* -> GFG

Given an array arr of N integers, the task is to replace each element of the array by its rank in the array. The rank of an element is defined as the distance between the element with the first element of the array when the array is arranged in ascending order. If two or more are same in the array then their rank is also the same as the rank of the first occurrence of the element. 


Example 1:
    Input: N = 6, arr = [20, 15, 26, 2, 98, 6]
    Output: 4, 3, 5, 1, 6, 2
    Explanation: After sorting, array becomes {2,6,15,20,26,98}
    Rank(2) = 1 (at index 0) 
    Rank(6) = 2 (at index 1) 
    Rank(15) = 3 (at index 2) 
    Rank(20) = 4 (at index 3) and so on..


    Input: N = 4, arr = [2, 2, 1, 6]
    Output: 2, 2, 1, 3
    Explanation: After sorting, array becomes {1, 2, 2, 6}
    Rank(1) = 1 (at index 0) 
    Rank(2) = 2 (at index 1) 
    Rank(2) = 2 (at index 2) 
    Rank(6) = 3 (at index 3)
    Rank(6) = 3 because rank after 2 is 3 as rank 
    of same element remains same and for next element 
    increases by 1.

*/

/*
Approach:-
    Brute force:-
        -- for each element iterate the whole array again to count the smaller elements in the array for the current elements, and then assign its rank using the size of the array.alignas

        TC:- O(n^2)
        SC:- O(1)

    1. Using multiset: set contain element in sorted way, 
        -- so set<pair<data,index>>, it will sort with respect to data, and then we can iterate the set to modify the data by a simple counting 1,2,3,4... and parallely store the updated data in respective index inside given array

        TC:- O(n*logn)
        SC:- O(n)

    2. Using pair: (similar to set)
        -- vector<pair<int,int>>, in this case we have explicitly sort the vector after inserting all data

        TC:- O(n*logn)
        SC:- O(n)

    3. Using minHeap:
        -- minHeap will contain the minElement at top, so we can direct use it to rank that element.
*/

#include<bits/stdc++.h>
using namespace std;

// Using multiSet
vector<int> replaceWithRank(vector<int> &arr, int N)
{
    multiset<pair<int,int>> st;

    // inserted element in multiset
    for(int i=0 ; i<N ; i++)
    {
        st.insert({arr[i], i});
    }

    // now assign rank ans as well strore it to the arr array
    int count=1;
    int modifiedData=-1; //-> this one, becuase if element is same than there ranking will also be same
    for(auto it=st.begin() ; it!=st.end() ; it++)
    {
        auto data = *it;

        // if previous modified Data is same as current data then don't use the incremented count
        if(modifiedData==data.first) count--;

        // update the modifiedData;
        modifiedData=data.first;

        data.first=count;
        count++;

        arr[data.second]=data.first;
    }

    return arr;
}


// using minHeap
vector<int> replaceWithRank1(vector<int> &arr, int N)
{
    priority_queue<pair<int,int>, vector<pair<int,int>>, greater<pair<int,int>>> minHeap;

    // insert the data into heap
    for(int i=0;i<N;i++)
        minHeap.push({arr[i],i});

    // now take one by one and rank it 
    int count=1;
    int modifiedData=-1;//-> this one, becuase if element is same than there ranking will also be same
    while(!minHeap.empty())
    {
        auto it=minHeap.top();
        minHeap.pop();

        if(modifiedData==it.first) count--;

        modifiedData=it.first;

        it.first=count;
        count++;

        arr[it.second]=it.first;
    }

    return arr;
}


int main()
{
    vector<int> arr={2,2,1,6};
    int n=arr.size();

    vector<int> ans = replaceWithRank1(arr, n);

    for(auto num:ans)
        cout << num << " ";
    cout << endl;

    return 0;
}


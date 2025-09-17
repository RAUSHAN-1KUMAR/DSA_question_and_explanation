/* GFG
Given sorted k array, merge them to form single sorted array
*/

/*
Approach:- 
    Logic1: Concatenate all sorted array and then at last sort the answer array.
        TC: O((n*k)log(n*k))
        SC: O(n*k),

    Logic2: using minHeap
        1. first we will form the minHeap of only of the first element from each of the array, doing so we will get the smallest element at the top of our heap
        2. now pop the top and store it into an answer array, 
        3. after popping, insert the next element of the popped element's array into the minHeap.

    How we are gonna get the index, i.e., which element to be inserted now into the minHeap of a particular array and also from which array ?? -> we are gonna use class/struct to form the data along with its rowIndex and colIndex

    TC:- O((n*k)*logk)
    SC:- O(k)

Would you like to try this using dynamic memory allocation:- see next solution
*/

#include<bits/stdc++.h>
using namespace std;

// we need to from this info class so that we can store the data, and the row index of it and col index as well.
class info{
public:
    int data;
    int rowIndex;
    int colIndex;

    info(int a, int b, int c){
        this->data=a;
        this->rowIndex=b;
        this->colIndex=c;
    }
};

// comparator class so that we can define our minHeap comparison
class comparator
{
public:
    bool operator()(info &a, info &b){
        return a.data > b.data;
    }
};


void mergeKSortArrays(int arr[][4], int n, int k, vector<int> &ans)
{
    // declaring minHeap with its own comparator function because we have a info type not int type, so we have to justify it that with respect to which data you have to build our min Heap.
    priority_queue<info, vector<info>, comparator> pq;


    // Step1: process first k elements i.e., front element of each array
    for(int row=0; row<k; row++) //-> O(k)
    {
        int element = arr[row][0];
        info temp(element, row, 0);// data, rowIndex, colIndex
        pq.push(temp);
    }


    // Step2: now we will build our answer
    while(!pq.empty()) //->O(n*k)
    {
        info front = pq.top(); pq.pop(); //-> O(logk)

        int topData = front.data;
        int topRow = front.rowIndex;
        int topCol = front.colIndex;

        // store in answer
        ans.push_back(topData);

        // now insert the next element of popped array element
        if(topCol+1 < n)
        {
            info newInfo(arr[topRow][topCol+1], topRow, topCol+1);// nextData, sameRow, col+1
            pq.push(newInfo); //-> O(logk)
        }
    }
}


int main()
{
    int arr[3][4] = {
        {1,4,8,11},
        {2,3,6,10},
        {5,7,12,14}
    };

    int n=4;
    int k=3;

    vector<int> ans;

    mergeKSortArrays(arr, n, k, ans);

    cout << "Printing answer array: " << endl;

    for(int i=0 ; i<ans.size() ; i++)
    {
        cout << ans[i] << " ";
    }
    cout << endl;

    return 0;
}


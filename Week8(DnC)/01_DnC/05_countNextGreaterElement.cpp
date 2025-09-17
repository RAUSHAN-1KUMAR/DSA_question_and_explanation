/* GFG

Given an array of N integers and Q queries of indices. Return a list NGEs[] where NGEs[i] stores the count of elements strictly greater than the current element (arr[indices[i]]) to the right of indices[i].


Examples :
    Input:  arr[] = [3, 4, 2, 7, 5, 8, 10, 6]
            queries = 2
            indices[] = [0, 5]
    Output:  6, 1
    Explanation: The next greater elements to the right of 3(index 0) are 4,7,5,8,10,6. The next greater elements to the right of 8(index 5) is only 10.

    Input:  arr[] = [1, 2, 3, 4, 1]
            queries = 2
            indices[] = [0, 3]
    Output:  3, 0
    Explanation: The count of numbers to the right of index 0 which are greater than arr[0] is 3 i.e. (2, 3, 4). Similarly, the count of numbers to the right of index 3 which are greater than arr[3] is 0, since there are no greater elements than 4 to the right of the array.
*/


/*
Approach:-
    Optimal approach: using merge sort (DnC)
*/

#include<bits/stdc++.h>
using namespace std;

vector<int> count_NGE(int n, vector<int> &arr, int queries, vector<int> &indices)
{

}

int main()
{
    vector<int> arr = {1,2,3,4,1};
    vector<int> indices = {0,3};
    int queries = 2;

    vector<int> ans  = count_NGE(arr.size(), arr, queries, indices);

    for(auto num:ans)
        cout << num << " ";
    cout << endl;

    return 0;
}



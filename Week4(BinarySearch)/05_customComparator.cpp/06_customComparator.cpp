/*
Why custom Comparator?
    -- The inBuilt sort() function sorts the given data in ascending order. So, what if we want it to sort in descending order, then we need comparator function.
*/

#include<iostream>
#include<vector>
#include<algorithm>

using namespace std;

bool myComparator(vector<int> &a, vector<int> &b){
    return a[1]>b[1];//-> sorting by 1st index i.e., second element of each vector;
    // return a>b;//-> sorting by 0th index i.e., first element of each vector
}

void sortFunction(vector<vector<int>> &arr)
{
    sort(arr.begin(), arr.end(), myComparator);
}

void getData(vector<vector<int>> &arr)
{
    for(int i=0 ; i<arr.size() ; i++)
    {
        for(int j=0 ; j<arr[i].size() ; j++)
        {
            cout << arr[i][j] << ",";
        }
        cout << endl;
    }
    cout << endl;
}

int main()
{
    vector<vector<int>> a = {
        {2,5,3},
        {10,0,1},
        {6,11,2},
        {9,2},
        {17,10},
        {13,5,6}
    };

    // sorting array
    cout << "array sorting using sort() with comparator function: ";
    sortFunction(a);

    // printing elemets;
    getData(a);

    return 0;
}
/*
The inBuilt sort() function sorts the given data in ascending order.
*/

#include<iostream>
#include<vector>
#include<algorithm>

using namespace std;

void sortFunction(vector<int> &arr)
{
    sort(arr.begin(), arr.end());
}

void getData(vector<int> &arr)
{
    for(int i=0 ; i<arr.size() ; i++)
    {
        cout << arr[i] << " ";
    }
    cout << endl;
}

int main()
{
    vector<int> a = {6,4,5,2,25,7,8};

    // sorting array
    cout << "array sorting using sort() function: ";
    sortFunction(a);

    // printing elemets;
    getData(a);

    return 0;
}
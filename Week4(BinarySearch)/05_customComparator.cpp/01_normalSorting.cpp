/*
Sorting:- Sorting without using sort() function
*/

#include<iostream>
#include<vector>
#include<algorithm>

using namespace std;


void sortFunction(vector<int> &arr)
{
    for(int i = 0; i<arr.size() ; ++i)
    {
        for(int j = i+1 ; j<arr.size() ; j++)
        {
            if(arr[i]>arr[j]) swap(arr[i],arr[j]);//-> descending order
        }
    }
}


void display(vector<int> &arr)
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
    cout << "array sorting: ";
    sortFunction(a);

    // printing elemets;
    display(a);

    return 0;
}

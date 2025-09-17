/*
Why custom comparator?
    -- the normal sorting sorting code just sort the data as condition given, what if we want to code that given in different funcion.
*/


#include<iostream>
#include<vector>
#include<algorithm>

using namespace std;

bool should_i_swap(int a, int b)
{
    if(a<b) return true;

    return false;
}


void sortFunction(vector<int> &arr)
{
    for(int i = 0; i<arr.size() ; ++i)
    {
        for(int j = i+1 ; j<arr.size() ; j++)
        {
            if(should_i_swap(arr[i],arr[j])) swap(arr[i],arr[j]);
        }
    }
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
    cout << "array sorting: ";
    sortFunction(a);

    // printing elemets;
    getData(a);

    return 0;
}

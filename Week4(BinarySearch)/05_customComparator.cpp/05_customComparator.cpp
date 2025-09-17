/*
Why custom Comparator?
    -- The inBuilt sort() function sorts the given data in ascending order. So, what if we want it to sort in descending order, then we need comparator function.
*/

#include<iostream>
#include<vector>
#include<algorithm>

using namespace std;

bool compDecreasing(int a, int b){
    return a>b; //-> descreasing order sorting
    // return a<b; //-> increasing order sorting
}

void sortFunction(vector<int> &arr)
{
    sort(arr.begin(), arr.end(), compDecreasing);
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
    cout << "array sorting using sort() with comparator function: ";
    sortFunction(a);

    // printing elemets;
    getData(a);

    return 0;
}
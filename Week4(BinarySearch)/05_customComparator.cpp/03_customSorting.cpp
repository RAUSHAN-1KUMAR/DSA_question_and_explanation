

#include<iostream>
#include<vector>
#include<algorithm>

using namespace std;

// bool should_i_swap(int a, int b){
//     if(a<b) return true;

//     return false;
// }

bool should_i_swap(pair<int,int> a, pair<int,int> b){
    return a>b;
}

void sortFunction(vector<pair<int,int>> &arr)
{
    for(int i = 0; i<arr.size() ; ++i)
    {
        for(int j = i+1 ; j<arr.size() ; j++)
        {
            if(should_i_swap(arr[i],arr[j])) swap(arr[i],arr[j]);
        }
    }
}

void getData(vector<pair<int,int>> &arr)
{
    cout << endl;
    for(int i=0 ; i<arr.size() ; i++)
    {
        cout << arr[i].first << " " << arr[i].second;
        cout << endl;
    }
    cout << endl;
}

int main()
{
    vector<pair<int,int>> a = {
        {4,3},
        {5,5},
        {5,3},
        {25,6},
        {7,9},
        {8,5}
    };

    // sorting array
    cout << "pair sorting: ";
    sortFunction(a);

    // printing elemets;
    getData(a);

    return 0;
}

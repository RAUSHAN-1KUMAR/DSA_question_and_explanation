     
#include<iostream>
#include<vector>

using namespace std;
 
int main()
{   
    vector<vector<int>> arr;

    vector<int> a{1,2,3};
    vector<int> b{4,5,6,2};
    vector<int> c{1,3,7};
    
    arr.push_back(a);
    arr.push_back(b);
    arr.push_back(c);

    for(int i = 0 ; i<arr.size() ; i++) // arr.size() is for number of rows.
    { 
        for(int j = 0 ; j<arr[i].size() ; j++) // arr[i].size() is for no. of columns in each row.
        { 
            cout << arr[i][j] << " ";
        }
        cout << endl;
    }

    return 0;
}

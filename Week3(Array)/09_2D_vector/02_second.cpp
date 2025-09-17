     
#include<iostream>
#include<vector>
using namespace std;
 
int main()
{   
    vector<vector<int>> arr(3, vector<int>(5,0));

    for(int i = 0 ; i<arr.size() ; i++){ // arr.size() is for number of rows.
        for(int j = 0 ; j<arr[i].size() ; j++){ // arr[i].size() is for no. of columns in each row.
            cout << arr[i][j] << " ";
        }                               
        cout << endl;
    }

    return 0;
}



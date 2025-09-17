     
#include<iostream>
#include<vector>
using namespace std;
 
int main()
{   
    // Initialization with Size Specified:
    {
        vector<vector<int>> myVector2D(3, vector<int>(4)); // all values will be initialize to zeroes

        for(int i = 0 ; i<myVector2D.size() ; i++){
            for(int j = 0 ; j<myVector2D[i].size() ; j++){ 
                cout << myVector2D[i][j] << " ";
            }                               
            cout << endl;
        }
    }


    // Initialization with Specific Value:
    {
        vector<vector<int>> myVector2D(3, vector<int>(5, -1));

        for(int i = 0 ; i<myVector2D.size() ; i++){
            for(int j = 0 ; j<myVector2D[i].size() ; j++){ 
                cout << myVector2D[i][j] << " ";
            }                               
            cout << endl;
        }
    }


    // Initialization from Existing 2D Array:
    {
        int arr[2][2] = { {1, 2}, {3, 4} }; // Example 2D array

        vector<vector<int>> myVector2D(2, vector<int>(2));

        for (int i = 0; i < 2; ++i) {
            for (int j = 0; j < 2; ++j) {
                myVector2D[i][j] = arr[i][j];
            }
        }

        for(int i = 0 ; i<myVector2D.size() ; i++){
            for(int j = 0 ; j<myVector2D[i].size() ; j++){ 
                cout << myVector2D[i][j] << " ";
            }                               
            cout << endl;
        }
    }

    // Initialization with Nested Initializer Lists (C++11 and later):
    {
        vector<vector<int>> myVector2D = { {1, 2, 3}, {4, 5, 6}, {7, 8, 9} };

        for(int i = 0 ; i<myVector2D.size() ; i++){
            for(int j = 0 ; j<myVector2D[i].size() ; j++){ 
                cout << myVector2D[i][j] << " ";
            }                               
            cout << endl;
        }
    }


    // Dynamic Initialization with Push_Back:
    {
        vector<vector<int>> myVector2D;

        for (int i = 0; i < 3; ++i) {
            vector<int> row;
            for (int j = 0; j < 4; ++j) {
                int value;
                cin >> value;
                row.push_back(value);
            }
            myVector2D.push_back(row);
        }

        for(int i = 0 ; i<myVector2D.size() ; i++){
            for(int j = 0 ; j<myVector2D[i].size() ; j++){ 
                cout << myVector2D[i][j] << " ";
            }                               
            cout << endl;
        }
    }


    return 0;
}



#include <iostream>
using namespace std;

int main() 
{

    // Declaration without initialization
    {   
        int myArray1[3][4];

        cout << "myArray1:" << endl;
        for (int i = 0; i < 3; ++i) {
            for (int j = 0; j < 4; ++j) {
                cout << myArray1[i][j] << " ";
            }
            cout << endl;
        }
    }

    // Static initialization
    {
        int myArray2[3][4] = {
            {1, 2, 3, 4},
            {5, 6, 7, 8},
            {9, 10, 11, 12}
        };

        cout << "myArray2:" << endl;
        for (int i = 0; i < 3; ++i) {
            for (int j = 0; j < 4; ++j) {
                cout << myArray2[i][j] << " ";
            }
            cout << endl;
        }
    }

    // Partial initialization
    {
        int myArray3[3][4] = {
            {1, 2},
            {3, 4},
            {5}
        };

        cout << "myArray3:" << endl;
        for (int i = 0; i < 3; ++i) {
            for (int j = 0; j < 4; ++j) {
                cout << myArray3[i][j] << " ";
            }
            cout << endl;
        }
    }

    // Zero initialization
    {
        int myArray4[3][4] = {0};

        cout << "myArray4:" << endl;
        for (int i = 0; i < 3; ++i) {
            for (int j = 0; j < 4; ++j) {
                cout << myArray4[i][j] << " ";
            }
            cout << endl;
        }
    }

    // dynamic allocation
    {   
        int rows = 3;
        int cols = 4;

        // Dynamic allocation of a 2D array
        int** myArray = new int*[rows];
        for (int i = 0; i < rows; ++i) {
            myArray[i] = new int[cols];
        }

        // Initialize the array
        for (int i = 0; i < rows; ++i) {
            for (int j = 0; j < cols; ++j) {
                myArray[i][j] = i * cols + j + 1;
            }
        }

        // Print the array
        cout << "Dynamically allocated 2D array:" << endl;
        for (int i = 0; i < rows; ++i) {
            for (int j = 0; j < cols; ++j) {
                cout << myArray[i][j] << " ";
            }
            cout << endl;
        }

        // Deallocate the memory
        for (int i = 0; i < rows; ++i) {
            delete[] myArray[i];
        }
        delete[] myArray;
    }



    return 0;
}
#include <iostream>
#include <array>
using namespace std;

int main() 
{
    // Basic declaration and initialization
    {
        int myArray1[5]; // Declaration without initialization
        int myArray2[5] = {1, 2, 3, 4, 5}; // Static initialization
        int myArray3[5] = {1, 2}; // Partial initialization, rest will be zero till size of the array
        int myArray4[5] = {}; // Full zero initialization

        cout << "myArray1: ";
        for (int i = 0; i < 5; ++i) {
            cout << myArray1[i] << " ";
        }
        cout << endl;

        cout << "myArray2: ";
        for (int i = 0; i < 5; ++i) {
            cout << myArray2[i] << " ";
        }
        cout << endl;

        cout << "myArray3: ";
        for (int i = 0; i < 5; ++i) {
            cout << myArray3[i] << " ";
        }
        cout << endl;

        cout << "myArray4: ";
        for (int i = 0; i < 5; ++i) {
            cout << myArray4[i] << " ";
        }
        cout << endl;
    }


    // Dynamic allocation
    {
        int *ptr = new int[10]; // Dynamic allocation

        // Initialize the array
        for (int i = 0; i < 10; ++i) {
            ptr[i] = i + 1;
        }

        // Print the array
        cout << "ptr: ";
        for (int i = 0; i < 10; ++i) {
            cout << ptr[i] << " ";
        }
        cout << endl;

        delete[] ptr; // Deallocate memory
    }

    // using std::array
    array<int, 5> arr = {1, 2, 3, 4, 5};

    cout << "Array elements: ";
    for (auto elem : arr) {
        cout << elem << " ";
    }
    cout << endl;

    return 0;
}
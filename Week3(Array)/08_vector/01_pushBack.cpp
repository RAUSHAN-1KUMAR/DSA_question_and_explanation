     
#include<iostream>
#include<vector>
using namespace std;
 
int main()
{   

    vector<int> arr; // declaration

    // pushing elements
    arr.push_back(5);
    arr.push_back(6);
    arr.push_back(10);

    // printing elements
    for(int i = 0 ; i<arr.size() ; i++){
        cout << arr[i] << " ";
    }
    cout << endl;


    vector<int> v1;
    vector<char> v2;
    vector<float> v3;
    cout << sizeof(v1) << endl; // output -> 12
    cout << sizeof(v2) << endl; // output -> 12
    cout << sizeof(v3) << endl; // output -> 12  // why all the output is 12 ??

    return 0;
}

/*
sizeof() function:-
    -- In C++, sizeof returns the size in bytes of its operand. When you declare a vector like vector<int> v, the sizeof operator will return the size of the vector object itself, not the size of the elements it contains.
    -- The size of the vector<int> v object will typically consist of:
        1. The size of the internal pointers used by the vector to manage the dynamically allocated array of integers.
        2. Some additional metadata to keep track of the size, capacity, and other information about the vector.
    -- However, the exact size may vary depending on the implementation of the standard library and the specific compiler and platform you are using.
*/

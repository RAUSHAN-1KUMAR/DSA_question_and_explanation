     
// observing push_back() and pop_back() function 

#include<iostream>
#include<vector>
using namespace std;
 
int main()
{   

    vector<int> arr;

    cout << sizeof(arr) << endl;
    cout << "Size of array is: " << arr.size() << endl;
    cout << "Capacity of array is: " << arr.capacity() << endl;

    // pushing elements and printing
    arr.push_back(5);
    arr.push_back(6);
    arr.push_back(10);

    for(int i = 0 ; i<arr.size() ; i++){
        cout << arr[i] << " ";
    }
    cout << endl;

    cout << "Size of array is: " << arr.size() << endl;
    cout << "Capacity of array is: " << arr.capacity() << endl;


    // popping elements and printing
    arr.pop_back();//-> popped 10

    for(int i = 0 ; i<arr.size() ; i++){
        cout << arr[i] << " ";
    }
    cout << endl;

    cout << "Size of array is: " << arr.size() << endl;
    cout << "Capacity of array is: " << arr.capacity() << endl;

    arr.pop_back();//-> popped 6
    arr.pop_back();//-> popped 5

    for(int i = 0 ; i<arr.size() ; i++){
        cout << arr[i] << " ";
    }
    cout << endl;

    cout << "Size of array is: " << arr.size() << endl;
    cout << "Capacity of array is: " << arr.capacity() << endl;

    return 0;
}



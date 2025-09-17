     
#include<iostream>
using namespace std;
 
int main()
{   
    int arr[7];

    cout << sizeof(arr) << endl;
    cout << sizeof(arr)/sizeof(int) << endl;
    
    cout << arr << endl;
    cout << &arr << endl;
    cout << &arr[0] << endl;

    cout << &arr[1] << endl;
    cout << &arr[2] << endl;
    return 0;
}



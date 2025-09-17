     
#include<iostream>
using namespace std;
 
int main()
{   
    int arr[8] = {2,4,6,9,12};

    cout << sizeof(arr) << endl;

    cout << &arr[0] << endl;
    cout << &arr[1] << endl;
    cout << &arr[2] << endl;
    cout << &arr[3] << endl;
    cout << &arr[4] << endl;
    cout << &arr[5] << endl;
    cout << &arr[6] << endl;
    cout << &arr[7] << endl;
    cout << &arr[8] << endl;
    cout << &arr[9] << endl;
    cout << &arr[10] << endl;

    cout << arr[0] << endl;
    cout << arr[1] << endl;
    cout << arr[2] << endl;
    cout << arr[3] << endl;
    cout << arr[4] << endl;
    cout << arr[5] << endl;
    cout << arr[6] << endl;
    return 0;
}

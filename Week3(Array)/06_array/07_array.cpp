
/*
using for loop for accessing as well as printing
*/

#include<iostream>
using namespace std;
 
int main()
{   
    int arr[5];
    int n=5;

    for(int i = 0 ; i<n ; i++)
    {
        cout << "Enter the value for index " << i << ": ";
        cin >> arr[i];
    }

    cout << endl << "Printing the array" << endl;
    for(int i = 0 ; i<n ; i++)
    {
        cout << arr[i] << " ";
    }

    return 0;
}

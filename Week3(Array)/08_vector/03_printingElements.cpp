     
#include<iostream>
#include<vector>
using namespace std;
 
int main()
{   

    vector<int> arr;

    int n;
    cout << "Enter the number of elemets: ";
    cin >> n;

    cout << "Enter elements: ";
    for(int i = 0 ; i<n ; i++)
    {
        int data;
        cin >> data;
        arr.push_back(data);
    }

    cout << "Printing elements: ";
    for(int i = 0 ; i<n ; i++)
    {
        cout << arr[i] << " ";
    }
    cout << endl;

    cout << "Size of vector arr is: " << arr.size() << endl;
    cout << "Capacity of vector arr is: " << arr.capacity() << endl;

    // To print the first and last element of vector
    cout << "Front element: " << arr[0] << endl;
    cout << "Front element: " << arr.front() << endl;
    cout << "Last element: " << arr[arr.size() - 1] << endl;
    cout << "Last element: " << arr.back() << endl;

    return 0;
}




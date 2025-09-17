     
#include<iostream>
#include<vector>
using namespace std;

void print(vector<int> v)
{
    cout << "printing elements: ";
    int size = v.size();
    for(int i = 0 ; i<size ; i++)
    {
        cout << v.at(i) << " "; // at(i) is used to print the element at the ith index. So output will be same as v[i].
    }
    cout << endl;
    // cout << v.at(5); -> not error but warning
}
 
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

    print(arr);
    cout << arr.size() << endl;
    cout << arr.capacity() << endl;

    arr.clear(); // to clear vector

    cout << arr.size() << endl;
    cout << arr.capacity() << endl;
    
    arr.push_back(20);
    print(arr);
    cout << arr.size() << endl;
    cout << arr.capacity() << endl;

    return 0;
}




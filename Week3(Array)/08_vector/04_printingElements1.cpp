     
#include<iostream>
#include<vector>
using namespace std;

void print1(vector<int> v)
{
    cout << "printing elements method 1: " << endl;
    int size = v.size();
    for(int i = 0 ; i<size ; i++)
    {
        cout << v.at(i) << " "; 
    }
    cout << endl;
}

void print2(vector<int> v)
{
    cout << "printing elements method 2: " << endl;
    int size = v.size();
    for(auto it:v){
        cout << it << " ";
    }
    cout << endl;
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

    print1(arr);
    print2(arr);

    return 0;
}








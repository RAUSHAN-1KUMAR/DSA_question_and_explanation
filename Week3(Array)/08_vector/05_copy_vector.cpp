     
#include<iostream>
#include<vector>
using namespace std;

void print(vector<int> v)
{
    cout << "printing elements: " << endl;
    int size = v.size();
    for(int i = 0 ; i<size ; i++)
    {
        cout << v[i] << " ";
    }
    cout << endl;
}
 
int main()
{   

    vector<int> arr = {2,6,5,8,9};
    vector<int> prr(arr); // to copy elements of vector
    prr.push_back(10);

    print(arr);
    print(prr);
    
    return 0;
}




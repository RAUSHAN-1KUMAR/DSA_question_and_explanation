
#include <iostream>
using namespace std;

int main()
{
    int A[2][3] = {{2,5,9},{7,3,6}};
    int B[2][3] = {{6,3,4},{9,5,2}};
    int C[2][3];

    cout << "The elements of Matrix A are: " << endl;
    for(auto &x:A)//-> this one is for raw
    {
        for(auto &y:x)//-> this one is for coloumn
        {
            cout << y << " ";
        }
        cout << endl;
    }
    cout << endl;

    cout << "Enter the elements of Matrix C: " << endl;
    for(auto &x:C)
    {
        for(auto &y:x)
        {
            cin >> y;
        }
    }
    cout << endl;

    cout << "The elements of Matrix C are: " << endl;
    for(auto &x:C)
    {
        for(auto &y:x)
        {
            cout << y << " ";
        }
        cout << endl;
    }
    cout << endl;

    return 0;
}
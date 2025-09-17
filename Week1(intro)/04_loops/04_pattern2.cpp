/*
*****
*   *
*   *
*****
-> Hollow rectangle
*/

#include<iostream>
using namespace std;

int main()
{
    int r,c;
    cout << "Enter no. of rows: ";
    cin >> r;
    cout << "Enter no. of columns: ";
    cin >> c;

    for(int row = 0 ; row < r ; row++)
    {
        if(row==0 || row==(r-1))
        {
            for(int col=0 ; col<c ; col++)
            {
                cout << "*";
            } 
        }
        else
        {
            cout << "*";
            for(int col = 0 ; col<(c-2) ; col++)
            {
                cout << " ";
            }
            cout << "*";
        }
        cout << endl;
    }
    return 0;
}


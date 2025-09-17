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
        for(int col = 0 ; col < c ; col++)
        {
            if(row>0 && row<(r-1))
            {
                if(col>0 && col <(c-1))
                    cout << " ";
                else    
                    cout << "*";
            }
            else
            {
                cout << "*";
            }
        }
        cout << endl;
    }
    return 0;
}


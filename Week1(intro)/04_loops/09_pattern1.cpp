/*
*****
*  *
* *
**
*
-> Hollow inverted half pyramid
*/

#include<iostream>
using namespace std;

int main()
{
    int n;
    cout << "Enter a number: ";
    cin >> n;

    for(int row = 1 ; row<=n ; row++)
    {
        if(row==1)
        {
            for(int col = 1 ; col<=n ; col++)
            {
                cout << "*";
            }
        }
        else
        {
            for(int col = 1 ; col<=n ; col++)
            {
                if(col==1 || col==(n+1)-row)
                    cout << "*";
                else
                    cout << " ";
            }
        } 
        cout << endl;
    }
    return 0;
}
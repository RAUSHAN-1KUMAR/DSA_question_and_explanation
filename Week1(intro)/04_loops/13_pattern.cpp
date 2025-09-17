/*
*********
**** ****
***   ***
**     **
*       *
*/


#include<iostream>
using namespace std;

int main()
{
    int n;
    cout << "Enter a number: ";
    cin >> n;

    for(int i = 1 ; i<=n ; i++)
    {
        for(int j = 1 ; j<=(n*2-1) ; j++)
        {
            if(i>=2 && j>=(n+2-i) && j<=(n-2+i))
                cout << " ";
            else
                cout << "*";
        }
        cout << endl;
    }
    return 0;
}
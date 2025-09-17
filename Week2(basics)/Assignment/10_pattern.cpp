/*
Butterfly Pattern

*         *
**       **
***     ***
****   ****
***** *****
***** *****
****   ****
***     ***
**       **
*         *

*/

#include<iostream>
using namespace std;

int main(){

    int n;
    cout << "Enter a number: ";
    cin >> n;

    for(int row = 1 ; row<=n ; row++)
    {
        for(int col = 1 ; col<=(2*n+1) ; col++)
        {
            if(col>=(row+1) && col<=(2*n+1-row)){
                cout << " ";
            }
            else{
                cout << "*";
            }
        }
        cout << endl;
    }

    for(int row = 1 ; row<=n ; row++)
    {
        for(int col = 1 ; col<=(2*n+1) ; col++)
        {
            if(col>=(n+2-row) && col<=(n+row)){
                cout << " ";
            }
            else{
                cout << "*";
            }
        }
        cout << endl;
    }

    return 0;
}
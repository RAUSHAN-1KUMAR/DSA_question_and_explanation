/*
Butterfly Pattern

*        *
**      **
***    ***
****  ****
**********
**********
****  ****
***    ***
**      **
*        *

*/

#include<iostream>
using namespace std;

int main(){

    int n;
    cout << "Enter a number: ";
    cin >> n;

    for(int row = 0 ; row<2*n ; row++)
    {
        int cond = row<n ? row : n+(n-row-1);
        int space_count = row<n ? 2*(n-cond-1) : row-cond-1; 

        for(int col = 0 ; col<2*n ; col++)
        {
            if(col<=cond){
                cout << "*";
            }
            else if(space_count > 0){
                cout << " ";
                space_count--;
            }
            else{
                cout << "*";
            }
        }
        cout << endl;
    }

    return 0;
}
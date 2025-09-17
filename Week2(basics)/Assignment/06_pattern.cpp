/*

1
2*3
4*5*6
7*8*9*10
7*8*9*10
4*5*6
2*3
1

*/

#include<iostream>
using namespace std;


int main()
{
    int n;
    cout << "Enter a number: ";
    cin >> n;

    int row2 = 0;
    int digit = 1;
    int k;


    for(int row = 1 ; row<=(2*n) ; row++)
    {

        if(row<=n){
            row2++;
        }
        if(row==n){
            k=digit;
        }
        if(row==(n+1)){
            digit = k;
        }
        if(row>(n+1)){
            row2--;
            digit = digit - (2*row2+1);
        }

        for(int col = 1 ; col<=(2*row2 - 1) ; col++)
        {
            if(col==1 || col%2==1){
                cout << digit;
                digit++;
            }
            else{
                cout << "*";
            }
        }
        cout << endl;
    }

    return 0;
}
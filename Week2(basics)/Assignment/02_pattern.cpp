/*
Print the given pattern:-

12345
2  5
3 5
45
5

*/

#include<iostream>
using namespace std;

int main(){

    int n;
    cout << "Enter a number: ";
    cin >> n;

    int digit;

    for(int row = 1 ; row<=n ; row++)
    {
        digit = row;

        for(int col = 1 ; col<=(n-row+1) ; col++)
        {
            if(row==1 || col==1 || col==(n-row+1)){
                cout << digit;
                digit++;
            }
            else{
                cout << " ";
                digit++;
            }
        }
        cout << endl;
    }

    return 0;
}
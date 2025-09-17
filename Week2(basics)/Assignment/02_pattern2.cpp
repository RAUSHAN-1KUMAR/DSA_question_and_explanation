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

    for(int row = 1 ; row<=n ; row++)
    {
        for(int col = row ; col<=n ; col++)
        {
            if(row == 1 || col == row || col == n){
                cout << col;
            }
            else{
                cout << " ";
            }
        }
        cout << endl;
    }

    return 0;
}
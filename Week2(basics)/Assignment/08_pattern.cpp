/*
Floyd's Triangle Pattern

1
2 3
4 5 6
7 8 9 10
11 12 13 14 15 
16 17 18 19 20 21
22 23 24 25 26 27 28

*/

#include<iostream>
using namespace std;

int main(){
    int n;
    cout << "Enter a number: ";
    cin >> n;

    int c = 1;

    for(int row = 0 ; row<n ; row++)
    {
        for(int col = 0 ; col<=row ; col++)
        {
            cout << c << " ";
            c++;
        }
        cout << endl;
    }

    return 0;
}
/*
Print the given pattern:-

1
12
1 3
1  4
12345

*/

#include<iostream>
using namespace std;

int main(){

    int n;
    cout << "Enter a number: ";
    cin >> n;

    int digit = 1;

    for(int row = 1 ; row<=n ; row++){
        for(int col = 1 ; col<=row ; col++){
            if(row==1 || row==2){
                cout << digit;
                digit++;
            }
            else if(row==n){
                cout << digit;
                digit++;
            }
            else{
                if(col>=2 && col<=(row-1)){
                    cout << " ";
                    digit++;
                }
                else{
                    cout << digit;
                }
            }
        }
        digit = 1;
        cout << endl;
    }

    return 0;
}
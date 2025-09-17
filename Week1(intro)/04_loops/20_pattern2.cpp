/*
1
121
12321
1234321
123454321
*/  

#include<iostream>
using namespace std;

int main(){

    int n;
    cin >> n;

    for(int row = 1 ; row<=n ; row++){
        
        int del = 2;

        for(int col = 1 ; col<=(2*n-1) ; col++){
            
            int c = col;
            
            if(col>(row+1)){
                del = del+2;
            }
            if(col==(row+1)){
                del=2;
            }

            if(col<=(2*row-1)){
                if(col<=row){
                    cout << c;
                }
                else{
                    c = c-del;
                    cout << c;
                }
            }

        }

        cout << endl;
    }

    return 0;
}
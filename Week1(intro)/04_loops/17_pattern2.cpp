/*
Hollow half diamond
*       *
 *     *
  *   *
   * *
    * 
*/ 

#include<iostream>
using namespace std;

int main(){

    int n;
    cin >> n;

    for(int row = 1 ; row<=n ;  row++){
        for(int col = 1 ; col<=(2*n-1) ; col++){
            if(col==row || col==(n*2-row)) cout << "*";
            else cout << " ";
        }
        cout << endl;
    }
    
    return 0;
}
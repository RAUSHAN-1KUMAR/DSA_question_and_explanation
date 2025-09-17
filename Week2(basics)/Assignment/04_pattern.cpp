/*

*
**
***
****
*****
****
***
**
*

*/

#include<iostream>
using namespace std;

int main(){

    for(int row = 1 ; row<=9 ; row++){
        for(int col = 1 ; col<=(9/2 + 1) ; col++){
            if(row<=(9/2+1)){
                if(col<=row){
                    cout << "*";
                }
                else{
                    cout << " ";
                }
            }
            else{
                if(col<=(9-row+1)){
                    cout << "*";
                }
                else{
                    cout << " ";
                }
            }
        }
        cout << endl;
    }

    return 0;
}
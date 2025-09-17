/*
Print numeric palindrome equilateral pyramid

    1
   121
  12321
 1234321
123454321

*/

#include<iostream>
using namespace std;

int main(){

    int digit = 0;

    for(int row = 1 ; row<=5 ; row++){
        for(int col = 1 ; col<=(4+row) ; col++){
            if(col>(5-row)){
                if(col<=5){
                    digit++;
                    cout << digit;
                }
                else{
                    digit--;
                    cout << digit;
                }
            }
            else{
                cout << " ";
            }
        }
        digit = 0;
        cout << endl;
    }

    return 0;
}
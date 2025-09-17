/*

*
*1*
*121*
*12321*
*121*
*1*
*

*/

#include<iostream>
using namespace std;



int main(){

    int n;
    cout << "Enter odd number: ";
    cin >> n;

    int row2 = 0;

    if(n%2==1){
        cout << "*" << endl;
        for(int row = 1 ; row<=n ; row++)
        {
            int col2 = 1;

            if(row<=(n/2 + 1)){
                row2++;
            }else{
                row2--;
            }

            cout << "*";
            for(int col = 1 ; col<=(2*row2-1) ; col++)
            {
                if(col<=row2){
                    cout << col2;
                    col2++;
                }
                else if(col==(row2+1)){
                    col2 -= 2;
                    cout << col2;
                }
                else{
                    col2--;
                    cout << col2;
                }
            }
            cout << "*";
            cout << endl;
        }
        cout << "*";
    }
    else{
        cout << "Please enter a odd number." << endl;
    }


    return 0;
}
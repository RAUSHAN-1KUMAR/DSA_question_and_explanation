/*
Pascal's Triangle Pattern

       1
      1 1               
     1 2 1
    1 3  3 1    below value is the sum of upper two
   1 4  6  4 1
  1 5 10 10 5 1
 1 6 15 20 15 6 1 

formula to find at a particular place:- 
    c = c*(row-col)/col ; row = [1,N] and col = [1,row]

print this:-
1
1 1
1 2 1
1 3 3 1
1 4 6 4 1
1 5 10 10 5 1
1 6 15 20 15 6 1 

*/

#include<iostream>
using namespace std;

int main(){
    int n;
    cout << "Enter a number: ";
    cin >> n;


    for(int row = 1 ; row<=n ; row++)
    {
        int c = 1;
        for(int col = 1 ; col<=row ; col++)
        {
            cout << c << " ";
            c = c*(row-col)/col;
        }
        cout << endl;
    }

    return 0;
}
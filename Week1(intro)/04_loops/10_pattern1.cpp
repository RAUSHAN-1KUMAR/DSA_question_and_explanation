/*
    *
   * *
  *   *
 *     *
*********
-> Hollow full pyramid
*/

#include<iostream>
using namespace std;

int main()
{
    for(int i = 1 ; i<=5 ; i++)
    {
        for(int j = 1 ; j<=9 ; j++)
        {
            if(i==5 || j==((9+1)/2)-(i-1) || j==((9+1)/2)+(i-1))
                cout << "*";
            else
                cout << " ";
        }
        cout << endl;
    }
    return 0;
}

/*
If you are taking input form the user:-
    rows(i) == n;
    column(j) == 2n-1;
*/
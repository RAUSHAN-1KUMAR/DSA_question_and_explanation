/*
     *
    ***
   *****
  *******
 *********
***********
->full pyramid
*/


#include<iostream>
using namespace std;

int main()
{
    for(int i = 1 ; i<=6 ; i++)
    {
        for(int j = 1 ; j<=11 ; j++)
        {
            if(j>=((11+1)/2 + 1)-i && j<=((11+1)/2 - 1)+i)
                cout << "*";

            else
                cout << " ";
        }
        cout << endl;
    }
    return 0;
}

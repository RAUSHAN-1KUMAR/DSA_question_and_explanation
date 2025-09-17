/*
   *
  ***
 *****
*******
 *****
  ***
   *
*/

#include<iostream>
using namespace std;

int main()
{
    int k = 0,n;
    cout << "Enter no. of rows: ";
    cin >> n;

    for(int i = 1 ; i<=n ; i++)
    {
        i<=(n+1)/2?k++:k--;

        for(int j = 1 ; j<=n ; j++)
        {
            if(j>=((n+1)/2+1-k) && j<=((n+1)/2-1+k))
                cout << "*";
            else
                cout << " ";
        }
        cout << endl;
    }
    return 0;
}
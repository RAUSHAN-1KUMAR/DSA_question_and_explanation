/*
1
2 3
3 4 5
4 5 6 7
5 6 7 8 9
*/      
 
#include<iostream>
using namespace std;
 
int main()
{
    int n;
    cin >> n;

    for(int row = 0 ; row<n ; row++)
    {
        int start = row+1;
        for(int col = 0 ; col<(row+1) ; col++)
        {
            cout << start << " ";
            start++;
        }
        cout << endl;
    }

    return 0;
}

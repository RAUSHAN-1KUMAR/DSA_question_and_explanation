
/*
set means 1 or not

so check if xth bit is 1 or not
*/

// Brute force is to directly change the given number into its binary form then iterate through it to check ith bit is 1 or not
// Better: to check ith bit is set or not, we use '&' operator

#include<bits/stdc++.h>
using namespace std;


int main()
{
    int n = 13;
    int i = 1;

    // using left shift or right shift

        //1. lets use left shift
        if(n & (1<<i)) cout << "Yes" << endl; // 1101 & 0010 = 0000 
        else cout << "No" << endl;
        
        //2. lets use right shift
        if((n>>i) & 1) cout << "Yes" << endl; // 0110 & 0001 = 0000
        cout << "No" << endl;

    // checking for all ith bit
    cout << endl;
    for(int i=0 ; i<4 ; i++)
    {
        if(n & (1<<i)) cout << i << "th bit is set." << endl;
        else cout << i << "th bit is not set." << endl;
    }

    return 0;
}

/*
Now question is asking to set the ith bit if it is zero
*/

// Brute force is to directly change the given number into its binary form then iterate through it
// Better: to set ith bit is , we use '|' operator

#include<bits/stdc++.h>
using namespace std;


int main()
{
    int n = 13;
    int i = 1;

    n = n|(1<<i);// 1101 | 0010 = 1111

    cout << n << endl;

    return 0;
}



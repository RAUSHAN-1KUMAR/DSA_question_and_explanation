/*
remove the last set bit or we can say right most set bit
*/

// removing it is easy but how we can find the position of right most set bit, using for loop and checking for each i(0->n) to find the ith bit is set or not

#include<bits/stdc++.h>
using namespace std;

int main()
{
    int n=15;
    
    int pos=-1;
    for(int i=0; i<32;i++){
        if(n&(1<<i)){
            pos=i;
            break;
        }
    }

    // but we have a better approach
    /*
        16-> 10000, 40-> 101000, 84-> 1010100
        15-> 01111, 39-> 100111, 83-> 1010011

        so we can say that if we decrease by 1 then right most set bit become 0 and all right of it become 0
    */

    // so our direct logic is: n&(n-1) to remove the last set bit

    n = n & (n-1);

    cout << n << endl;
    
    return 0;
}
/*
Explained in notecopy
*/

#include<iostream>
using namespace std;

// slow method to find exponential
int normalMethod(int a, int n)
{
    int ans = 1;
    for(int i=0 ; i<n ; i++) //O(n)
    {
        ans *= a;
    }

    return ans;
}


// fast method to find exponential
int betterMethod(int a, int n)
{
    int ans = 1;

    while(n>0) // log(n)
    {
        if(n&1){
            ans = ans*a;
        }

        a = a*a;

        n >>= 1; //-> n = n/2
    }

    return ans;
}


int main()
{
    cout << normalMethod(5,4) << endl;
    cout << betterMethod(5,4) << endl;
    
    return 0;
}


/*
Debug the code. It is trying to print the given pattern.

N = 5
E
DE
CDE
BCDE
ABCDE
*/

#include<iostream>
using namespace std;

int main() {
    int i,j,n;;
    cin>>n;
    for(i=1;i<=n;i++){
        char p='A'-i;
        for(j=1;j<=i;j++){
            cout<<p;
            p++;  
        }
        cout<<endl;
    }
}


/* CORRECT CODE

int main() 
{
    int i,j,n;;
    cin>>n;

    for(i=1;i<=n;i++)
    {
        char p='A'+ (n-i);
        for(j=1;j<=i;j++)
        {
            cout<<p;
            p++;  
        }
        cout<<endl;
    }

    return 0;
}

*/
/*
To print the required pattern

Pattern for N = 4
4444
333
22
1
*/

#include<iostream>
using namespace std;

int main(){
  int i,j,n;
    cin>>n;
    for(i=1;i<n;i++){
        for(j=i;j<n;j++){
            cout<<i;
        }
        cout<<endl;
    }
}

/* Correct code

int main()
{
    int i,j,n;
    cin>>n;

    int num = n;

    for(i=n;i>=1;i--){
        for(j=1;j<=i;j++){
            cout<<i;
        }
        cout<<endl;
    }

    return 0;
}

*/
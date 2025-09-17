
// greatest of three number.

#include<iostream>
using namespace std;

int main()
{
    int n1,n2,n3;
    cout << "enter three numbers: " ;
    cin >> n1 >> n2 >> n3;

    if(n1>n2){
        if(n1>n3){
            cout<<"Max. is: "<<n1;
        }
        else{
            cout<<"Max. is: "<<n3;
        }
    }
    else{
        if(n2>n3){
            cout<<"Max. is: "<<n2;
        }
        else{
            cout<<"Max. is: "<<n3;
        }
    }
    
    return 0;
}

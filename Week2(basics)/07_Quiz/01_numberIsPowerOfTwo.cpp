/*
To check whether a number is power of 2 or not
*/

#include<iostream>
using namespace std;

bool isPowerOfTwo(unsigned int x){
    return (!(x&(x-1)));
}

int main(){

    int n;
    cout << "Enter a number: ";
    cin >> n;

    int temp = isPowerOfTwo(n);

    if(temp == 1){
        cout << "Yes" << endl;
    }
    else{
        cout << "No" << endl;
    }

    return 0;
}

// but it does not work for x = 0;
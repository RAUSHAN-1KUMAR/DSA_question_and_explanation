/*
To unset the kth bit of a number
*/

#include<iostream>
using namespace std;

// to unset the kth bit of a number
void fun(int &num, int k){
    num = num & (~(1<<k));
}

// to print binary equivalent of a number
void bin(int n){
    if(n>1) bin(n/2);
    cout << n%2 ;
}

int main(){

    int num = 7;
    int k = 0;

    bin(num);

    fun(num,k);

    cout << endl;
    bin(num);


    cout << endl;
    bin(26);

    return 0;
}
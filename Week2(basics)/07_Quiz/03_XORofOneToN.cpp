/*
To give the XOR of numbers 1 to n
*/

#include<iostream>
using namespace std;

int collectXOR(int n){
    int result = 0;
    for(int i = 1; i<=n ; ++i){
        result = result^i;
    }
    return result;
}

int main(){

    int num;
    cout << "Enter a number: ";
    cin >> num;

    int xorResult = collectXOR(num);

    cout << "XOR of numbers from 1 to " << num << " is: " << xorResult << endl;

    return 0;
}
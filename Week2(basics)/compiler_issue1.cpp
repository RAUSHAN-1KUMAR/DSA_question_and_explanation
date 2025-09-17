/*
see the compiler issue by commenting the uncomment and uncommenting the commented instruction and observe the output.
verify the output from online compiler
*/


#include<iostream>
#include<math.h>
using namespace std;



int main(){

    int num1 = 3*pow(10,1) + 1;
    int num2 = 4*pow(10,2) + 11;
    int num3 = 5*pow(10,3) + 111;
    int num4 = 6*pow(10,4) + 1111;

    cout <<  num1 << endl;
    cout <<  num2 << endl;
    cout <<  num3 << endl;
    cout <<  num4 << endl;

    // cout << "Correct way: " << endl;
    // cout << 3*pow(10,1) + 1 << endl;
    // cout << 4*pow(10,2) + 11 << endl;
    // cout << 5*pow(10,3) + 111 << endl;
    // cout << 6*pow(10,4) + 1111 << endl;
    
    return 0;
}
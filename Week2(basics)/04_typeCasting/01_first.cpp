
// typecasting means converting one data type to another. 

#include<iostream>
using namespace std;

int main(){
    float a = 45.94;
    int b = 45;
    cout << "The value of a is " << a << endl;
    cout << "The value of a is " << (int)a << endl;
    cout << "The value of a is " << int(a) << endl;

    int c = int(a);
    cout << endl << "The value of c is " << c << endl;

    cout << endl << "The expression1 is " << a + b << endl;
    cout << "The expression2 is " << (int)b + a << endl;
    cout << "The expression3 is " << int(a+b) << endl;
    cout << "The expression4 is " << int(a) + b << endl;
    
    return 0;
}
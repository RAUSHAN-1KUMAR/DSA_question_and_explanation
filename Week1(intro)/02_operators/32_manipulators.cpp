
#include<iostream>
#include<iomanip>//-> iomanip(input output manipulators) is a library in C++ which helps us in manipulating the output of any C++ program.
using namespace std;

int main(){
    int a = 3, b = 45, c = 966;
    cout << "The  value of a without setw is: " << a << endl;
    cout << "The  value of b without setw is: " << b << endl;
    cout << "The  value of c without setw is: " << c << endl;

    // Using setw() function, present inside iomanip library.
    // setw function is a C++ manipulator which stands for set width.
    
    cout << "The  value of a with setw is: " << setw(4) << a << endl;
    cout << "The  value of b with setw is: " << setw(4) << b << endl;
    cout << "The  value of c with setw is: " << setw(4) << c << endl;
    return 0;
}
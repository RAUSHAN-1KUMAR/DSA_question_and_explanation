
#include<iostream>
using namespace std;

int main(){
    int a = 34;
    cout<<"The value of a was: "<<a<<endl;
    a = 45;
    cout<<"The value of a is: "<<a<<endl;

    // Constants in C++
    const int b = 3;//-> Now b is like pi = 3.14, means value of pi is fixed in our world it cannot be changed.
    cout<<"The value of b was: "<<b<<endl;
    //b = 45; --> error
    int b = 45;//--> Invalid
    cout<<"The value of b is: "<<b<<endl;
    return 0;
}
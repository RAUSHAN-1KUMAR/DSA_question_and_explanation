
#include<iostream>
using namespace std;

int main(){
    
    int age;
    cout << "Tell me your age: ";
    cin >> age;

    switch(age)
    {
        case 18: cout<<"Your age is 18"<<endl;

        default: cout<<"No special cases"<<endl;

        case 22: cout<<"Your age is 22"<<endl;
            break;

        case 2: cout<<"Your age is 2"<<endl;
    }
    // If one of the case satisfied then all below will be executed.
    // default case can be written anywhere.
    return 0;
}
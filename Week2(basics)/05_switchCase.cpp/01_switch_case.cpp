
#include<iostream>
using namespace std;

int main()
{
    int age;
    cout<<"Tell me your age: ";
    cin>>age;

    switch(age){
        case 18:
            cout<<"Your age is 18"<<endl;
            break;

        case 22:
            cout<<"Your age is 22"<<endl;
            break;

        case 2:
            cout<<"Your age is 2"<<endl;
            break;
    
        default:
            cout<<"No special cases"<<endl;
            break;
    }
    // if we do not write break statement then the whole cout will be executed which are below the satisfied case, including default case also.

    return 0;
}
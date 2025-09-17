
#include<iostream>
using namespace std;

int main(){
    cout << "Menu:" << endl;
    cout << "1. Add\n" << "2. Sub\n" << "3. Mul\n" << "4. Div\n";

    int option;
    cout << "Enter your choice: ";
    cin >> option;

    int a,b,c;
    if(option >= 1 && option <= 4)
    {
        cout << "Enter 2 number: ";
        cin >> a >> b;
    }

    switch(option){
        case 1: 
            c = a+b;
            cout << "Result is: " << c << endl;
            break;

        case 2: 
            c = a-b;
            cout << "Result is: " << c << endl;
            break;

        case 3: 
            c = a*b;
            cout << "Result is: " << c << endl;
            break;

        case 4: 
            c = a/b;
            cout << "Result is: " << c << endl;
            break;

        default: 
            cout << "Enter your choice correctly.";
            break;
    }

    return 0;
}
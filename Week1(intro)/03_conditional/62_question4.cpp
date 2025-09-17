
// to check whether a character is alphabet or digit or special character.

#include<iostream>
using namespace std;

int main()
{
    char ch;
    cout << "Enter a character: ";
    cin >> ch;

    if(ch >= 'a' && ch <= 'z'){
        cout << "your entered character is an alphabet." << endl;
    }
    else{
        if(ch >= 'A' && ch <= 'Z'){
            cout << "your entered character is an alphabet." << endl;
        }
        else{
            if(ch >= '0' && ch <= '9'){
                cout << "Your entered character is a digit." << endl;
            }
            else{
                cout << "Your entered character is a special character." << endl;
            }
        }
    }

    return 0;
}

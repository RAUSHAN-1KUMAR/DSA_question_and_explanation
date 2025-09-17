
// to check whether a character is alphabet or not.

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
            cout << "Your entered character is not an alphabet." << endl;
        }
    }

    return 0;
}
// we can also use ASCII value in place of a or z or A or Z.
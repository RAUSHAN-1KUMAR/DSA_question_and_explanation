
// to check whether a character is alphabet or not.

#include<iostream>
using namespace std;

int main()
{
    char ch;
    cout << "Enter a character: ";
    cin >> ch;

    if((ch >= 'a' && ch <= 'z') || (ch >= 'A' && ch <= 'Z')){
        cout << "your entered character is an alphabet." << endl;
    }
    else{
        cout << "your entered character is not an alphabet." << endl;
    }

    return 0;
}

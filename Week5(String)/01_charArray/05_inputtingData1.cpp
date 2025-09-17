/* understading the 'cin'

Observe care fully: both input and output
*/

#include<iostream>
using namespace std;

int main()
{   
    char ch[50];
    cout << "Enter for ch: ";
    cin >> ch;//-> type: 'Rohit kumar saw' and see what happens, cin will not store the data after whitespace because it will think it as you want to jump to another char array and will give next word to other upcoming cin.
    // the next cin will ask for input only if it encounter enter key. 
    cout << "ch: " << ch << endl;

    char ch1[20];
    cout << "Enter for ch1: ";
    cin >> ch1;
    cout << "ch1: " << ch1 << endl;

    char ch2[20];
    cout << "Enter for ch2: ";
    cin >> ch2;
    cout << "ch2: " << ch2 << endl;

    char ch3[20];
    cout << "Enter for ch3: ";
    cin >> ch3;
    cout << "ch3: " << ch3 << endl;

    return 0;
}

// reason given in notecopy
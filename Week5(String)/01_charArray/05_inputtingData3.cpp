/* understanding the 'cin.getline()'

Observe care fully: both input and output
*/

// more preferable to use: cin.getline()

#include<iostream>
using namespace std;

int main()
{   
    char ch[50];
    cout << "Enter for ch: ";
    cin.getline(ch,50);//-> type: 'Rohit kumar saw' and see what happens, cin.get() will take the input including white space and jump to next instruction on enter key.
    cout << "ch: " << ch << endl;

    char ch1[20];
    cout << "Enter for ch1: ";
    cin >> ch1;//-> as encountered key is [enter] so it will ask for the input value of ch1, so now observe the below cin.getline() behaviour by giving value + whitespace + enter or value + enter with commenting and incommenting the line no. 21.
    cout << "ch1: " << ch1 << endl;

    cin.ignore();//-> use is same as used in cin.get()

    char ch2[20];
    cout << "Enter for ch2: ";
    cin.getline(ch2,50);
    cout << "ch2: " << ch2 << endl;


    char ch3[20];
    cout << "Enter for ch3: ";
    cin >> ch3;
    cout << "ch3: " << ch3 << endl;

    return 0;
}

// reason given in notecopy
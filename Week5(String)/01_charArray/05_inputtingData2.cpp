/* understanding the 'cin.get()'

Observe care fully: both input and output
*/

#include<iostream>
using namespace std;

int main()
{   
    char ch[50];
    cout << "Enter for ch: ";
    cin.get(ch,50);//-> type: 'Rohit kumar saw' and see what happens, cin.get() will take the input including white space and jump to next instruction on enter key.
    cout << "ch: " << ch << endl;

    char ch1[20];
    cout << "Enter for ch1: ";
    cin >> ch1;//-> as encountered key is enter so it will ask for the input value for ch1, so now observe the below cin.get() behaviour by giving value + whitespace + enter or value + enter with commenting and incommenting the line no. 21.
    cout << "ch1: " << ch1 << endl;

    cin.ignore();//-> it is used to ignore the white space or enter(not both at a time only one) for cin.get() for ch2, because cin ask for input when it encounter enter but cin.get() not ask for input even it encounter enter so to avoid all undefined coming data(White space or enter) for next cin.get() we use cin.ignore() before it.

    char ch2[20];
    cout << "Enter for ch2: ";
    cin.get(ch2,50);
    cout << "ch2: " << ch2 << endl;


    char ch3[20];
    cout << "Enter for ch3: ";
    cin >> ch3;
    cout << "ch3: " << ch3 << endl;

    return 0;
}

// reason given in notecopy
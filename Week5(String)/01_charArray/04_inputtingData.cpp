/*
There are various methods for inputting data into a character array
*/

#include<iostream>
using namespace std;

int main()
{   
    // using 'cin'
    {
        char ch1[10] = {'a','b','v','d'};
        cout << "Enter a chracter: ";
        cin >> ch1[4];
        cout << ch1 << endl;

        char ch2[100];
        cout << "Enter a word: ";
        cin >> ch2;
        cout << "You Entered: " << ch2 << endl;
    }

    // using 'cin.get()'
    {
        cin.ignore();//-> discussed later

        char myArray[100];
        cout << "Enter a sentence: ";
        cin.get(myArray, 100); // Reads up to 99 characters or until newline,(only jumps when you hit enter)
        cout << "You entered: " << myArray << endl;
    }

    //using 'cin.getline()'
    {
        cin.ignore();//-> discussed later

        char myArray[100];
        cout << "Enter a sentence: ";
        cin.getline(myArray, 100); // Reads up to 99 characters or until newline,(only jumps when you hit enter)
        cout << "You entered: " << myArray << endl;
    }

    //using loop 
    {
        char myArray[100];
        char ch;
        int i = 0;

        cout << "Enter characters (type '.' to stop): ";
        while (cin.get(ch) && ch != '.' && i < 99) {
            myArray[i++] = ch;
        }
        myArray[i] = '\0'; // Null-terminate the character array

        cout << "You entered: " << myArray << endl;
    }

    return 0;
}
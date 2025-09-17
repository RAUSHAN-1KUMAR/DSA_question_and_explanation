/*
look notecopy first
*/

#include <iostream>
#include <cstring>
#include <array>
#include <vector>
using namespace std;

int main() 
{
    // Basic declaration and initialization
    char greeting1[] = "Hello";
    char greeting2[10] = "Hello";
    char greeting3[6] = {'H', 'e', 'l', 'l', 'o'};
    char greeting4[10] = {'H', 'e', 'l', 'l', 'o'};
    char greeting5[10] = {};
    char greeting6[] = {'H', 'e', 'l', 'l', 'o'};

    cout << greeting1 << endl;
    cout << greeting2 << endl;
    cout << greeting3 << endl;
    cout << greeting6 << endl;
    cout << greeting4 << endl;
    cout << "Length of greeting4: " << strlen(greeting4) << endl;
    cout << "All nulls in greeting5: " << (greeting5[0] == '\0') << endl;


    // Dynamic allocation
    char *ptr = new char[10];
    strcpy(ptr, "Hello");

    cout << ptr << endl;

    delete[] ptr; // to deallocaten after using array


    // using array
    array<char, 10> myArray = {'H', 'e', 'l', 'l', 'o'};
    for(char c : myArray) {
        if(c == '\0') break;
        cout << c;
    }
    cout << endl;

    // using vector
    vector<char> vec = {'H', 'e', 'l', 'l', 'o'};
    for(char c : vec) {
        cout << c;
    }
    cout << endl;

    // using string
    string myString = "Hello";
    cout << myString << endl;

    return 0;
}
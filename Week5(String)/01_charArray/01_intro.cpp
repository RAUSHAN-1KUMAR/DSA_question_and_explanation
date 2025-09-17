/*
Definition:- A char array is a sequence of characters(like integer array, sequence of integers) stored in contiguous memory locations. char arrays are often used to handle strings and other text data.
*/


// char name[20]; --> name is a 'character array/string'. [20] means it has capacity to store 20 similar elements(char).
// float percentile[90]; --> percentile is a 'floating array'. [90] means it has capacity to store 90 similar elements(float).
// int marks[56]; --> marks is an 'integer array'. [56] means it has capacity to store 56 similar elements(int).

/*
First go through the notes of notecopy then observe this code
*/

#include<iostream>
#include<string>
using namespace std;

int main()
{
    cout << "Giving extra space for null character: " << endl;
    char ch[7] = {'a','b','c','d','\0'};
    cout << ch[0] << endl;
    cout << ch[1] << endl;
    cout << ch[2] << endl;
    cout << ch[3] << endl;
    cout << ch[4] << endl; // null character
    cout << ch[5] << endl; // null character
    cout << ch[6] << endl; // garbage

    cout << "Note giving extra space for null character: " << endl;
    char ph[5] = {'a','b','c','d','f'};
    cout <<ph[0] << endl;
    cout <<ph[1] << endl;
    cout <<ph[2] << endl;
    cout <<ph[3] << endl;
    cout <<ph[4] << endl; // no null character
    cout <<ph[5] << endl; // garbage
    cout <<ph[6] << endl; // garbage

    cout << "checking in case of string literals: "<< endl;
    // char oh[5] = "Rohit"; -> error
    char oh[5] = "Rohi"; // -> no error
    cout << oh[3] << endl;
    cout << oh[4] << endl; // null character
    cout << oh[1] << endl;
    cout << oh[5] << endl; // garbage
    cout << oh[4] << endl; // null character
    cout << oh[9] << endl; // garbage
    cout << oh[10] << endl; // garbage

    cout << "using string: " << endl;
    string ch1 = "Rohit";
    cout << ch1[0] << endl;
    cout << ch1[1] << endl;
    cout << ch1[2] << endl;
    cout << ch1[3] << endl;
    cout << ch1[4] << endl;
    cout << ch1[5] << endl; // null character
    cout << ch1[6] << endl; // garbage
    cout << ch1[7] << endl; // garbage
    cout << ch1;

    return 0;
}
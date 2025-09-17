
// strchr-> finding the occurance of given character from left hand side.
// strrchr-> finding the occurance of given character from right hand side.

#include<iostream>
#include<cstring>
using namespace std;

int main()
{
    char main[] = "programming";  
    
    cout << strchr(main,'m') << endl;//-> this will print from the starting point of char m from LHS in main till end.
    cout << strrchr(main,'m') << endl;//-> this will print from the starting point of char m from RHS in main till end.


    // another example
    char str[] = "Hello";
    char *ptr = strchr(str, 'l');

    cout << (ptr) << endl;
    
    if (ptr != nullptr) {
        cout << "Found 'l' at position: " << (ptr - str) << endl;
    } else {
        cout << "Character not found" << endl;
    }

    return 0;
}
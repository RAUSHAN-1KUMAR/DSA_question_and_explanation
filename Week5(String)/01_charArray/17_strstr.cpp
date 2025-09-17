
// finding the occurance of given string in a string.

#include<iostream>
#include<cstring>
using namespace std;

int main()
{
    char main[] = "programming";  
    char sub1[] = "gram";
    cout << strstr(main,sub1) << endl;//-> this will print from the starting point of word gram in main till end. 

    char sub2[] = "m";
    cout << strstr(main,sub2) << endl;

    // char sub3[] = "k";
    // cout << strstr(main,sub3) << endl;//-> null 


    //Another example
    char str[] = "Hello World";
    char* ptr = strstr(str, "World");

    cout << ptr << endl;

    if (ptr != nullptr) {
        cout << "Found 'World' at position: " << (ptr-str) << endl;
    } else {
        cout << "Substring not found" << endl;
    }

    return 0;
}
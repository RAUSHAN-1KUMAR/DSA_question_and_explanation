
#include<iostream>
#include<cstring>
using namespace std;

int main()
{
    char str1[15] = "Rohit";
    char ptr[20];

    cout << "Using strcpy function: ";
    strcpy(ptr,str1);//-> strcpy() is used to copy the content of second string(str1) into first string(ptr).
    cout << ptr << endl;

    cout << "Using strncpy function: ";
    strncpy(ptr,str1,2);
    cout << ptr << endl;

    return 0;
}
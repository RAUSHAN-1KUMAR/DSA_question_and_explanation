/*
Array of pointer:- int *arr[5];
pointer to an array:- int (*arr)[5];
*/

#include<iostream>
using namespace std;

int main()
{
    int arr[5] = {1,2,3,4,5};
    int *ptr = arr;
    // int *ptr1 = &arr; -> error

    char ch[10] = "Babbar";
    char *cptr = ch;
    // char *cptr1 = &ch; -> error


    // So how to declare pointers to an array;
    int (*ptr2)[5] = &arr;
    cout << *ptr2 << endl;//-> pure array ki starting address = &arr = arr = &arr[0]
    cout << &arr << endl;
    cout << &arr[0] << endl;
    cout << arr << endl;
    cout << *(*ptr2) << endl;
    cout << (*ptr2)[2] << endl;
    cout << arr[2] << endl;

    return 0;
}
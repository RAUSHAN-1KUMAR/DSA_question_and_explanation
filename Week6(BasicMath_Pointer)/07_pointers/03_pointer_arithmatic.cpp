
// increment decrement of a pointer to array

#include<iostream>
using namespace std;

int main()
{
    int number[5] = {1,2,3,4,5};
    int *ptr1 = number;//-> array name represents the address of first element

    cout << "ptr1 is pointing to " << *ptr1 << endl;
    cout << "The address of number[0] is " << ptr1 << endl;
    cout << &number << endl;
    cout << "The address of number[0] is " << number << endl;
    cout << "The address of number[0] is " << &number[0] << endl;
    cout << "The address of ptr1 is " << &ptr1 << endl;
    cout << endl;

    ptr1 = ptr1 + 2; /* Now it is pointing to that memeory which is 8 bytes away from the current address
    i.e. now it is storing the address of number[2]. */
    cout << "Now ptr1 is pointing to " << *ptr1 << endl;
    cout << "The address of number[2] is " << ptr1 << endl;
    cout << "The address of number[2] is " << &number[2] << endl;
    cout << endl;

    //Next we want to display 5.
    ptr1 = ptr1 + 2; //--> Now it jumped from the address of number[2] to address of number[4].
    cout << "Now ptr1 is pointing to " << *ptr1 << endl;
    cout << "The address of number[4] is " << ptr1 << endl;
    cout << "The address of number[4] is " << &number[4] << endl;
    cout << endl;

    ptr1 = ptr1 - 1; //--> Now it is storing the address of number[3].
    cout << "Now ptr1 is pointing to " << *ptr1 << endl;
    cout << "The address of number[3] is " << ptr1 << endl;
    cout << "The address of number[3] is " << &number[3] << endl;
    cout << "The address of ptr1 is " << &ptr1 << endl;//-> it will be same
 
    return 0;
}
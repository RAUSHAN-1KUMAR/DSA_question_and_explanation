
// Operations such as subtraction of a pointer from another pointer.

/* 
--> If two pointer variables are of same type and they are pointing to the elements of the 'same array' then they can be subtracted from one another. 
*/

// NOTE:- addition, multiplication and division of pointer to pointer is not supported.

#include<iostream>
using namespace std;

int main()
{
    int number[5] = {1,2,3,4,5};

    int *ptr1 = &number[0];
    int *ptr2 = &number[4];

    cout << ptr2 - ptr1 << endl;//--> ptr2-ptr1 returns the total momery locations the two pointer variables are 'away' from one another.
    //--> [ptr2 - ptr1 = (ptr2 - ptr1)/size of pointer variable's type]

    cout << (ptr2 - ptr1)-1 << endl;//--> this returns total memory locations 'available' in between two pointer variables.

    cout << (ptr2 - ptr1)+1 << endl;/* --> this tells 'no. of elements available' in an array; only if ptr1 is pointing to the first
    memory location of the array and ptr2 is pointing to the last memory location of the array */

    return 0;
}
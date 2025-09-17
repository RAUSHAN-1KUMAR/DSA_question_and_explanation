
#include<iostream>
using namespace std;

int main()
{
    int size1;
    cout << "Enter number of elemets in array A: ";
    cin >> size1;
    int A[size1];//-> this array is declared inside the stack memory.
    cout << "The size of array A is " << sizeof A << endl;

    // if we want to change the size of array A then we can't
    cout << "Enter new size of array A: ";
    cin >> size1;
    A[size1];
    cout << "The size of array A is " << sizeof A << endl;



    // but we can change the size of same array if it is inside heap memory.
    int size2;
    cout << "Enter number of elemets in array p: ";
    cin >> size2;
    int *p = new int[size2];//-> this will create an array of size size2 in heap memory

    delete []p;//-> to assign new size we must deallocate the previous memory.

    cout << "Enter new size of array p: ";
    cin >> size2;
    p = new int[size2];//-> this will create another array of size size2 in heap memory, means now same pointer p is pointing to other memory

    delete[]p;
    
    return 0;
}
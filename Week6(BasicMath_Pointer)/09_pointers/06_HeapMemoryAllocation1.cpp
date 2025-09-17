// By using pointer we can access memory of heap.

#include<iostream>
using namespace std;

int main()
{
    int A[5] = {1,2,3,4,5};//-> this one is stored inside stack memory

    int *p;//-> this is also declared inside stack memory

    p = new int[5];//->(an array of size five is stored in heap) new means the memory is allocated from heap, and the address of that array is stored in p

    cout << "Before A[2] = " << A[2] << endl;
    A[2] = 15;
    cout << "After A[2] = " << A[2] << endl;

    cout << "Before p[2] = " << p[2] << endl;// output -> 0
    p[2] = 13;
    cout << "After p[2] = " << p[2] << endl;

    /*
    One more difference between stack memory and heap memory is:-
        -> The array inside the stack memory will automatically get deleted when it is going out of the scope.
        -> but heap memory will not get deleted automatically, it will be there as long as our program is running. So, if we want it for limited
        time then the heap memory must be deallocated after the use of data inside heap memory.
    */

    //p = NULL;
    delete []p;//-> heap memory deallocated
    p = nullptr; //-> now p is not pointing to any data, if we use this instruction before delete[]p then p will just leave the heap memory, it means the heap memory will not be deallocated. 
    // this 'nullptr' is specially for pointer.

    return 0;
}

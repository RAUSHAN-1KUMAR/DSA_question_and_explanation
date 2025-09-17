
// Comparison operation of pointer variable.
// 6 comparison or relational operators in C/C++: ==,!=,<,>,<=,>=

/* 1. ptr1 == ptr2 is used to check whether two pointer variables are pointing to the same memory location.
   2. ptr1 != ptr2 is used to check whether two pointer variables are not pointing to the same memory location.
   3. ptr1 < ptr2 is used to check in the memory whether the memory location pointed by ptr1 appears before the
      memory location pointed by ptr2 i.e. is to check ptr1 is less than the value of ptr2.
   4. ptr1 > ptr2 is used to check in the memory whether the memoty location pointed by ptr1 appears after the
      memoty location pointed by ptr2 i.e. is to check ptr1 is greater than the value of ptr2.
   5. ptr1 <= ptr2 is used to check whether value of ptr1 is less than or equal to the value of ptr2.
   6. ptr1 >= ptr2 is used to check whether value of ptr1 is greater than or equal to the value of ptr2.
*/

#include<iostream>
using namespace std;

int main()
{
    int num1 = 10;
    int num2 = 20;
    int *ptr1 = &num1;
    int *ptr2 = &num1;

    cout << (ptr1 == ptr2) << endl; //output-> 1 because the statement ptr1 == ptr2 is true.
    
    int *ptr3 = &num2;

    cout << (ptr1 != ptr3) << endl; //--> It will print 1 because the statement(ptr1 != ptr) is true.
    cout << (ptr1 == ptr3) << endl; //--> It will print 0 because the statement(ptr1 == ptr) is false.
    cout << (ptr1 < ptr3) << endl; //--> If it print 1 it means the statement(ptr1 < ptr3) is true.
    cout << (ptr1 > ptr3) << endl; //--> If it print 1 it means the statement(ptr1 > ptr3) is true.
    cout << (ptr1 <= ptr2) << endl; //--> If it print 1 it means the statement(ptr1 <= ptr2) is true.
    
    return 0;
}
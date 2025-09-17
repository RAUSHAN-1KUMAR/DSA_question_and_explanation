#include<iostream>
using namespace std;

int main()
{
    int i = 34;
    int *j = &i;//--> j is a pointer it means j is storing the address of an integer/char/float/etc. 
    int **k = &j;//--> k is a pointer to pointer iIt means k is storing the address of an pointer.

    cout << "The value of i is " << i << endl;
    cout << "The value of i is " << *j << endl; //--> *j == *(&i) == i
    cout << "The value of i is " << **k << endl; //--> *(*k) == *(*(&j)) == *(&i) == i
    cout << "The address of i is " << &i << endl;
    cout << "The address of i is " << j << endl;
    cout << "The address of i is " << *k << endl; //--> k ka jo value h uss address p kya value h?
    cout << "The address of j is " << &j << endl;
    cout << "The address of k is " << &k << endl;
    cout << "The address of j is " << *(&k) << endl;

    return 0;
}

/* Errors and non-errors
int **l = &i; -> error
int **l = &j; -> no error
int **l = &k; -> error
int ***l = &k; -> no error
*/



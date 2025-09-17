
#include<iostream>
using namespace std;

void solve(int prr[], int size)
{
    cout << *prr << endl;
    cout << *(prr+3) << endl;

    cout << "Address at solve function: " << endl;
    cout << "prr: " << prr << endl;
    cout << "&prr: " << &prr << endl;
}


int main()
{
    int arr[5] = {1,2,3,4,5};
    cout << "size of array: " << sizeof(arr) << endl;

    solve(arr,5);

    cout << "Address at main function: " << endl;
    cout << "arr: " << arr << endl;
    cout << "&arr: " << &arr << endl;

    return 0;
}

/*
Observe the output:-
    - the address of prr is equal to address of arr, because array pass is pass by reference that's why the prr variable stores the address of arr.
    - the address of &prr is not equal to address of &arr, because & gives the address of that variable, so as they are different memory blocks that's why there address are also different

What if we do:- prr = prr+1;
    -- this will only increment the prr not arr;

What if we do like this:-
    void solve(int* &prr){
        prr = prr+1;
    }
    -- not prr is a reference pointer it means prr is another name of arr. So, the value off arr will get change
*/

/*
Ek case solve kero baki case ka recursion answer lake dega + handle the base case
*/

// Observe the minor change between Count1 and Count2 function.

#include<iostream>
using namespace std;

// Tail recursion(explained in notecopy)
void Count1(int n)
{
    // base case
    if(n==0){
        return;
    }

    // solving one case
    cout << n << " ";

    // recursive call
    Count1(n-1);
}

// Head recursion(explained in notecopy)
void Count2(int n)
{
    // base case
    if(n==0){
        return;
     }

    // recursive call
    Count2(n-1);

    // solving one case
    cout << n << " ";
}


int main()
{
    Count1(10);
    cout << endl;
    Count2(10);

    return 0;
}
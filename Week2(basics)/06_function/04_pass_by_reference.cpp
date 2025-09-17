
// references are nick name to the existing variables
// call by references can be only used for simple purpose.

#include<iostream>
using namespace std;

void swap(int &a, int &b)//-> this swap function is not a seperate code, now it is the part of main function i.e. it is inside main funcion. So, when we use call by reference, the function is called inline function.
{
    cout << a << " " << b << endl;
    int temp;
    temp = a;
    a = b;
    b = temp;
    cout << a << " " << b << endl;
}

int main()
{
    int x = 10, y = 20;
    swap(x,y);//-> we are not calling a seperate function, we are in our main function.
    cout << x << " " << y << endl;
    return 0;
}
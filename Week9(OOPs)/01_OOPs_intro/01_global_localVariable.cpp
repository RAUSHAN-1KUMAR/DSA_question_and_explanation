
#include<iostream>
using namespace std;

int x = 2; // GLOBAL VARIABLE
int main()
{
    ::x = 4; // global x
    int x=20; // local to main() function
    cout << x << endl;
    cout << ::x << endl; // accessing global with ::

    {
        int x=50;
        cout << x << endl;
        cout << ::x << endl;
    }

    return 0;
}




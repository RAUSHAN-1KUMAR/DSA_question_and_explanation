/*
pointer and data both are constant
    -- after and before both
*/

#include<iostream>
using namespace std;

int main()
{
    const int* const a = new int(10);
    cout << *a << endl;
    return 0;
}

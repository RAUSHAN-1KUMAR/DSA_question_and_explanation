
#include<iostream>
using namespace std;

int main()
{

    char c = 128;//-> value overflowed so it will take the next value that is -128 (it is like, previously c was 127 and then c++)
    cout << int(c) << endl;
    cout << c << endl;

    char p = 129;//-> value overflowed so it will take the next value that is -127 (it is like, previously p was 127 and then p+=2)
    cout << int(p) << endl;
    cout << p << endl;

    char r = -130;//-> value overflowed so it will take the next value that is 126(it is like, previously r was -128 and the r-=2)
    cout << int(r) << endl;
    cout << r << endl;

    return 0;
}
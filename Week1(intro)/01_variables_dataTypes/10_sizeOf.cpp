/*
How much size each data types take, it depends on the compiler and the operating system on which it is developed. Different compilers of C++
gives different sizes for each data types.
*/

#include<iostream>
using namespace std;

int main()
{
    cout << "size of char: " << sizeof(char) << " bytes" << endl;
    cout << "size of wide char: " << sizeof(wchar_t) << " bytes" << endl;
    cout << "size of signed char: " << sizeof(signed char) << " bytes" << endl;
    cout << "size of unsigned char: " << sizeof(unsigned char) << " bytes" << endl;
    cout << "size of int: " << sizeof(int) << " bytes" << endl;
    cout << "size of short int: " << sizeof(short int) << " bytes" << endl;
    cout << "size of long int: " << sizeof(long int) << " bytes" << endl;
    cout << "size of long long int: " << sizeof(long long int) << " bytes" << endl;
    cout << "size of signed int: " << sizeof(signed int) << " bytes" << endl;
    cout << "size of unsigned int: " << sizeof(unsigned int) << " bytes" << endl;
    cout << "size of signed long int: " << sizeof(signed long int) << " bytes" << endl;
    cout << "size of unsigned long int: " << sizeof(unsigned long int ) << " bytes" << endl;
    cout << "size of float: " << sizeof(float) << " bytes" << endl;
    cout << "size of double: " << sizeof(double) << " bytes" << endl;
    cout << "size of long double: " << sizeof(long double) << " bytes" << endl;
    return 0;
}

// we cannot use short or long with float and char.
// we cannot use short double.
// we cannot use signed or unsigned with float or double.

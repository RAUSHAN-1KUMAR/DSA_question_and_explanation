/*
A funcion definition has four elements:
* A return type.
* A function name.
* A (possibly empty) parameter list enclosed in parentheses.
* A function body.
*/

#include<iostream>/* iostream headerfile is actually a library, library will contain the collection of builtin objects or functions that a programer can use and easily write a program, this is provided by c++ compiler. */

int main()
{
    std::cout << "Hello world" << std::endl;
    /*
    std::cout -> standard output object,(c++ does not define any statement for doing an input and output but it includes an extensive standard library), cout is present within the standard library, :: -> scope resolution operator,  so the statement-> 'std::cout', tells to our compiler that use the cout which is present within the scope of the standard library.

    << -> output operator

    string literals -> code inside double inverted comma(""). In this 'Hello world' is the string literals.

    endl(end line) -> it is a manipulator, it is taking the control to the next line. 

    We end a statement using semicolon (;).
    */
    return 0;//-> Return statement, as our main function has an integer return type so we have to return an integer value.
}
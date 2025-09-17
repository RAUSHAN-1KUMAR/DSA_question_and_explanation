/*
1. About function overloading:
    - Function overloading means defining multiple functions with the same name but different parameter lists (type, number, or order).
    - The compiler decides which one to call based on the arguments passed — this is called compile-time polymorphism.


2. Rules for Function Overloading
    You can overload functions if:
        1. Their number of parameters is different
        2. Or their types of parameters are different
        3. Or their order of parameters is different

        Return type alone cannot be used to differentiate overloaded functions.
            EX: int fun() and double fun() is not allowed -> compiler time error


So we can conclude a helping definition for polymorphism, as polymorphism states that it is the ability of one function to behave differently in different context or inputs. So, we can see that we have a same function name but with different behaviours and we say it as compile time polymorhism as decision is made during compilation.
*/


#include <iostream>
using namespace std;

class Printer {
public:
    void print(int i) {
        cout << "Printing int: " << i << endl;
    }

    void print(double d) {
        cout << "Printing double: " << d << endl;
    }

    void print(string s) {
        cout << "Printing string: " << s << endl;
    }
};


int main() 
{
    Printer p;
    p.print(42);           // Calls print(int)
    p.print(3.14);         // Calls print(double)
    p.print("Hello");      // Calls print(string)

    return 0;
}

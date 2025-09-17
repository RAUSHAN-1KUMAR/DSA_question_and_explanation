/*
Different types of errors in C++

1. Syntax Error: 
    - These are errors in the code that violate the rules of the C++ language. They are detected by the compiler during the compilation process. Examples include missing semicolons, unmatched parentheses, and incorrect use of keywords.

    int main() {
        cout << "Hello"   // ❌ missing semicolon
    }

    
2. Compile-time Error:
    - A broad category of errors that the compiler catches before running the program. Syntax errors are part of this, but also include type mismatches, undeclared variables, etc.

    int main() {
        int x = "Hello"; // ❌ type mismatch
    }


3. Runtime Error:
    - These errors occur while the program is running. They can cause the program to crash or behave unexpectedly. Examples include division by zero, accessing invalid memory, etc.

    int main() {
        int a = 10, b = 0;
        cout << a / b; // ❌ division by zero

        int* p = nullptr;
        cout << *p;  // ❌ segmentation fault
    }


4. Logical Error:
    - These errors occur when the program runs without crashing but produces incorrect results. 

    int r = 5;
    int area = 2 * 3.14 * r; // ❌ used circumference formula instead of area
    cout << "Area = " << area;

*/
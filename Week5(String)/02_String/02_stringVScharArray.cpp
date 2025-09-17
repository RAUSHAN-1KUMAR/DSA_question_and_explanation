/*
-- vector for array
-- string for char array
*/

/*
The main difference between character arrays (char[]) and strings (std::string) in C++ lies in how they are represented and the operations that can be performed on them. Here's an overview of their differences and the benefits of using string over character arrays:

Character Arrays (char[]):
1. Representation:
    - Character arrays are represented as contiguous blocks of memory containing individual characters followed by a null terminator ('\0') to denote the end of the string.
    - They have a fixed size and must be manually resized if the length of the string changes.

2. Operations:
    - Limited built-in operations: Standard library functions like strlen, strcpy, strcat, etc., are commonly used for operations like copying, concatenating, and finding the length of the string.
    - No built-in support for common string operations like appending, finding substrings, or comparing without using library functions.

3. Safety:
    - No built-in boundary checking: Accessing characters beyond the bounds of the array can lead to buffer overflows and undefined behavior.
    - Memory management is manual: Developers must handle memory allocation and deallocation explicitly.


string:
1. Representation:
    - string is a class provided by the C++ Standard Library that encapsulates a dynamic array of characters.
    - It automatically manages memory allocation and resizing, making it more flexible than character arrays.
    - string objects store the length of the string internally, so they can handle strings of variable length.

2. Operations:
    - Comprehensive set of member functions: string provides a wide range of member functions for common string operations, such as appending (append), finding substrings (find), comparing (compare), etc.
    - Operator overloading: string supports operator overloading for concatenation (+), comparison (==, !=, <, >), and assignment (=), making string manipulation more intuitive and concise.

3. Safety:
    - Bound-checked operations: string ensures that operations like appending or accessing elements do not result in buffer overflows.
    - Automatic memory management: string handles memory allocation and deallocation internally, reducing the risk of memory-related bugs.
*/
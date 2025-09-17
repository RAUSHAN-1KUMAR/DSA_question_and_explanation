/*
Arithmatic operators
    Ex-> Addition(+), Subtraction(-), Multiplication(*), Division(/), Modulus(%), Increment(++), Decrement(--)
            2+3           2-3               2*3             2/3         3%2 = 1       a++           a--
        
        -- Modulus operator(%) gives remainder.(it is only allowed to use in integer and character data types)
        -- Increment operator(++) increase the value by 1.   ex. a++ => a = a+1 
        -- Decrement operator(--) decrease the value by 1.   ex. a-- => a = a-1
*/

#include<iostream>
using namespace std;

int main()
{
    int num1 = 6;
    int num2 = 3;

    cout << num1+num2 << endl;//- 9
    cout << num1-num2 << endl;//- 3
    cout << num1*num2 << endl;//- 18
    cout << num1/num2 << endl;//- 2
    cout << num1%num2 << endl;//- 0
    cout << ++num1 << endl;//- 7
    cout << num1++ << endl;//- 7,, num1++ means first print then increase by 1
    cout << ++num1 << endl;//- 9,, ++num1 means first increase by 1 then print
    cout << --num2 << endl;//- 2

    return 0;
}

/* If the operation done between:-
    int and int --> output: int
    int and float --> output: float
    float and float --> output: float
*/
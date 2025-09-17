/*        
Logical operators
    -- used to compare two or more expression.
    Ex-> AND(&&), OR(||), NOT(!)

        -- in case of AND operator(&&) both the expression must be true to make the whole system true.
        -- in case of OR operator(||) both the expression must be false to make the whole system false.
        -- NOT operator(!) makes the true statement false and vice versa.
*/

// In case of logical OR(||) operator, if expression1 is true then it will not run(check) expression2.
// In case of logical AND(&&) operator, if expression1 is false then it will not run(check) expression2.

#include<iostream>
using namespace std;

int main()
{
    bool exp1 = true;
    bool exp2 = false;

    cout << (exp1&&exp2) << endl;//- false
    cout << (exp1||exp2) << endl;//- true
    cout << (!exp1) << endl;//- false
    cout << (!exp2) << endl;//- true

    return 0;
}

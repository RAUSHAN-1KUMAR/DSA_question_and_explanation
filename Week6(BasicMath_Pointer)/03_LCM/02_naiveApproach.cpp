/*
The naive approach to find the Least Common Multiple (LCM) of two numbers involves iterating through multiples of the larger number until you find one that is also a multiple of the smaller number. This method is straightforward but can be inefficient for large numbers.
*/

#include <iostream>
using namespace std;

int lcmNaive(int a, int b) 
{
    int maxNum = max(a,b); // Find the larger of the two numbers

    int lcm = maxNum;//-> start checking form the larger number

    // checking the multiples of maxNum which is divisible by both a and b
    while (true) 
    {
        if (lcm % a == 0 && lcm % b == 0) 
        {
            return lcm; //-> return if lcm is divisible by both a and b
        }
        lcm += maxNum;//-> now check next multiple of maxNum
    }

}

int main() {
    int num1, num2;
    cout << "Enter two numbers: ";
    cin >> num1 >> num2;

    cout << "LCM of " << num1 << " and " << num2 << " is " << lcmNaive(num1,num2) << endl;

    return 0;
}
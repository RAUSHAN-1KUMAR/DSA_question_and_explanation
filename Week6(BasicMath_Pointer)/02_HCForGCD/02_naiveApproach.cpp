
/*
The naive method to find the GCD of two numbers involves iterating from 1 to the smaller of the two numbers and checking for the largest number that divides both without leaving a remainder. This method is simple but not the most efficient for large numbers
*/

#include <iostream>
using namespace std;

int gcdNaive(int a, int b) 
{
    int gcd = 1; // Initialize gcd to 1 (smallest possible gcd)
    int minNum = (a < b) ? a : b; // Find the smaller of the two numbers

    for (int i = 1; i <= minNum; i++) 
    {
        if (a % i == 0 && b % i == 0) 
        {
            gcd = i; // Update gcd if i divides both a and b
        }
    }

    return gcd;
}

int main() {
    int num1, num2;
    cout << "Enter two numbers: ";
    cin >> num1 >> num2;

    int result = gcdNaive(num1, num2);
    
    cout << "GCD of " << num1 << " and " << num2 << " is " << result << endl;

    return 0;
}
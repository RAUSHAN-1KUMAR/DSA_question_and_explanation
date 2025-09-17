/*
To find the square of a given number using bitwise operator
*/

#include<iostream>
#include<bitset>

using namespace std;

int square(int num){
    if(num==0) return 0;

    int square = num;

    // multiply by 2
    square = square << 1;

    // add original number
    square = square + num;

    // Devide by 2
    square = square >> 1;

    return square;
}

int main(){

    int num;
    cout << "Enter a nubmer: ";
    cin >> num;

    int result = square(num);
    cout << "Sqaure of " << num << " is: " << result << endl;

    return 0;
}

// this is not the correct code
/*
To create number using digits

    one limit:- each input should contain one digit
*/

#include<iostream>
using namespace std;

int createDigits(int n){
    int num = 0;

    cout << "Enter digits: ";
    for(int i = 0 ; i<n ; i++)
    {
        int digit;
        cin >> digit;
        num = num*10 + digit;
    }

    return num;
}


int main()
{
    int numDigts;
    cout << "Enter the total number of digits: ";
    cin >> numDigts;

    int num = createDigits(numDigts);

    cout << "The created number is: " << num << endl;

    return 0;
}
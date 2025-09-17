
// write a program to offer discounts on total bill amount.

#include<iostream>
using namespace std;

int main(){
    float billAmount;
    float discount = 0.0;

    cout << "Enter the bill amount: ";
    cin >> billAmount;

    if(billAmount>=500)
    {
        discount = (billAmount*20)/100;
    }
    else if(billAmount>=100 && billAmount<500)
    {
        discount = (billAmount*10)/100;
    }

    cout << "Your bill amount is: " << billAmount << endl;
    cout << "Your discount at this bill amount is: " << discount << endl;
    cout << "your final bill amount is: " << billAmount-discount << endl;
    
    return 0;
}
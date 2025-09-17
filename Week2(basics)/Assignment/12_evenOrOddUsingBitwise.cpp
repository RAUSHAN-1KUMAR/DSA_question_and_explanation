/*
To check even or odd using bitwise
*/

#include<iostream>
using namespace std;

bool checkEven(int n)
{
    if((n&1)==0) return true;
    else return false;
}

int main()
{

    int num;
    cout << "Enter a number: ";
    cin >> num;

    bool isEven = checkEven(num);

    if(isEven) cout << "Given number is even."<< endl;
    else cout << "Given number is odd." << endl;
    
    return 0;
}
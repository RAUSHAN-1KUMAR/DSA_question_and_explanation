
// increment decrement to pointer to array

#include<iostream>
using namespace std;

int main()
{
    int number[5] = {1,2,3,4,5};
    
    cout << *(number+2) << endl; //-> value at second index
    cout << *(2+number) << endl; //-> will this valid or not?:- it is valid
    cout << endl; 
    cout << number[2] << endl; //-> value at second index
    cout << 2[number] << endl; //-> will this valid or not?:- it is valid

    // can we do this? as array name represents the address of first element So,
    number = number+1;//-> error, no we can't do this because the name of the array represents a constant pointer to the first element, and its value cannot be changed. This means that while you can use the array name to refer to the address of the first element, you cannot modify the address it holds

    return 0;
}
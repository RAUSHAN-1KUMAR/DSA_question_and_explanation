/*
To print 1's and 2's compliment in binary and in value as well of a number.
*/

#include<iostream>
#include<bitset>

using namespace std;

int twosComplement(int num){
    int onesComp = ~num;
    int twosComp = onesComp + 1;
    return twosComp;
}

int onesComplement(int num){
    int onesComp = ~num;
    return onesComp;
}


int main(){

    int num;
    cout << "Enter a number: ";
    cin >> num;

    // printing the original number in binary
    cout << "original number(in binary): " << bitset<sizeof(int)*8>(num) << endl;


    //printing the 1's complement in binary
    int onesComp = onesComplement(num);
    cout << "One's complement(in binary): " << bitset<sizeof(int)*8>(onesComp) << endl;

    // printing the value of 1's complement
    cout << "One's Complement(in decimal): " << onesComp << endl;


    // printing the 2's complemene in binary
    int twosComp = twosComplement(num);
    cout << "Two's Complement(in binary): " << bitset<sizeof(int)*8>(twosComp) << endl;

    // printing the value of 2's complement
    cout << "Two's Complement(in decimal): " << twosComp << endl;

    return 0;
}
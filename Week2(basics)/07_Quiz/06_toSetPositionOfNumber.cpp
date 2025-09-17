/*
To set the given position (pos) of a number(num)
*/

#include<iostream>
#include<bitset>

using namespace std;

void function(int &num, int pos)
{
    num = num|(1<<pos);
}

int main(){

    int num;
    cout << "Enter a number: " ;
    cin >> num;

    int pos;
    cout << "Enter a position: ";
    cin >> pos;

    cout << "Binary representation before set is: " << bitset<sizeof(int)*8>(num) << endl;

    function(num,pos);

    cout << "Binary representation after set is: " << bitset<sizeof(int)*8>(num) << endl;

    return 0;
}

/*
In case of char array, array name holds all the data not the address of first char array element like in integer array
*/

#include<iostream>
using namespace std;

int main()
{
    char ch[50] = {'l','o','v','e'};
    char *cptr = ch;

    cout << ch << endl;
    cout << &ch[1] << endl;
    cout << &ch[2] << endl;
    cout << &ch << endl;
    cout << cptr << endl;//-> noticable
    cout << &cptr << endl;

    cout << endl;

    cout << *cptr << endl;
    cout << *(cptr+1) << endl;

    // for character variable
    char cha = 'a';
    char *sptr = &cha;

    cout << sptr << endl;//-> it will print the whole data till it encounter null character
    cout << *sptr << endl;

    return 0;
}
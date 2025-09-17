#include<iostream>
using namespace std;

int main(){
    bool q = false;
    bool p = false;
    bool r = true;

    cout << (p==q==r);// == -> left to right associativity. so p==q is true then true == r is true so the output will be 1.

    return 0;
}
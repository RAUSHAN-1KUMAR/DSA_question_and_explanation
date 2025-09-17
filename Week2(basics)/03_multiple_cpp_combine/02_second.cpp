#include<iostream>
using namespace std;

#include "second.h"

void funFromSecond(){ // function body
    cout << "fun ho gaya from second.cpp " << endl;
}

// Here we can't use main function because we are calling this function in another cpp file where a main function already exist.


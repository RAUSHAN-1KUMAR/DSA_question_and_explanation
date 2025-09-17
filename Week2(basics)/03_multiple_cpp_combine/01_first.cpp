#include<iostream>
using namespace std;

#include "second.h"

void fun(){

    cout << "fun ho gaya" << endl;
}

int main(){
    int a=10;
    fun();

    funFromSecond(); //-> this function is in another cpp file.

    return 0;
}

// to combine multiple object files
// run this using terminal

/*
if we execute this file alone then error will occur, this is because we just told our first.cpp file that a function funFromSecond() is in second.h but second.h is also guessing that yes this function exist but function definition is inside second.cpp so we have to form respective .cpp to .obj file then a combined executable file of first and second.cpp file.
*/
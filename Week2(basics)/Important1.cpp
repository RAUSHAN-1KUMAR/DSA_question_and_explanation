
#include<iostream>
using namespace std;

int main(){

    int a = 10;
    int c = 10;
    int e = 10;

    int b = ++a * a++; // In this case a++, first incremented and then value is used.
    cout << b << endl;
    cout << a << endl;

    int d = c++ * c++; // but in this case, first value is taken then incremented in both c++
    cout << d << endl;
    cout << c << endl;

    int f = (++e) * (e)++; // but in this case, it works the way it should.
    cout << f << endl;
    cout << e << endl;

    return 0;
}


// it is so confusing
// it depends on the designing of compiler

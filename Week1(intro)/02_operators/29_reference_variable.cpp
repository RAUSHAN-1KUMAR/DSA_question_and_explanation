
// reference variable must be initialize during declaration

#include<iostream>
using namespace std;

int main(){
    int x = 455;
    cout << x << endl;

    int &y = x; //--> y is a reference variable, which provides an alternate name(y) for the previously defined variable(x).
    //int & y = x; we can also make reference variable like this
    cout << y << endl;

    ++y; //--> we can also use ++x, below display will be same.
    cout << x << " " << y << endl;

    int a = 11;
    //&y = a; -> error
    //int &y = a; -> invalid, runtime error that is we cannot use same name for two variable

    return 0;
}

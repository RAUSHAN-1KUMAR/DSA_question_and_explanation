
#include<iostream>
using namespace std;

int main(){

    bool a = 1;
    cout << (~a) << endl; // output is -2, why not 0 ??

    // but
    bool c = 1;
    bool d = ~c; // now the output is 1, why?
    cout << d << endl;

    // so lets check for 0
    bool g = 0;
    bool f = ~g;
    cout << f << endl;

    return 0;
}

/*
It happens like this:
---> It is just like bitwise complement of posetive number.

    1's complement then 2's complement of obtained 1's complememt.
        -> 1 = 00000001
        -> 1's complement = 11111110 (MSB is 1)
        -> 2's complement of obtained 1's complement = 00000001
                                                       ______+1
                                                       00000010
        -> obtained answet will be decimal equivalent of 00000010 with negative sign = -2
                        
*/

/*
In second and third case the output is 1 because after the 1's complement in obtained binary is not 0 number and if its not a 0 number then the ouput is true that is 1.
*/

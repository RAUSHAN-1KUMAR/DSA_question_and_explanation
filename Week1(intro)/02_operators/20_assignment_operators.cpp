/*        
 4. Assignment operators
    -- used to assign value.
    Ex-> =, +=, -=, /=, %=, *=

        --(=), this is used to simply assign a value.
        --(+=), ex. a+=2 => a = a + 2
        --(-=), ex. a-=2 => a = a - 2
        --(/=), ex. a/=2 => a = a / 2
        --(%=), ex. a%=2 => a = a % 2
        --(*=), ex. a*=2 => a = a * 2
*/

#include<iostream>
using namespace std;

int main()
{
    int assign = 4;

    cout << assign << endl;
    cout << (assign+=6) << endl;
    cout << (assign-=2) << endl;
    cout << (assign/=2) << endl;
    cout << (assign%=3) << endl;

    return 0;
}

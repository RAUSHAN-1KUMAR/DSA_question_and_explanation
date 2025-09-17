#include<iostream>
using namespace std;

int main()
{

    cout << (2&3) << endl; // 2 -> 0010, 3 -> 0011. So, (2&3) => 0010 & 0011 = 0010
    cout << (5&10) << endl; // 5 -> 0101, 10 -> 1010. So, (5&10) => 0101 & 1010 = 0000
    cout << (5|10) << endl; // 5 -> 0101, 10 -> 1010. So, (5|10) => 0101 | 1010 = 1111

    int num = 1;
    cout << ~num << endl;
    cout << (~num) << endl;
    cout << ~(num) << endl;
    cout << ~0 << endl;

    bool bl = 1;
    cout << (~bl) << endl;
    
    return 0;

}
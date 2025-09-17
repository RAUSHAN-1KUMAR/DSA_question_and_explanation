#include<iostream>
using namespace std;

int main()
{
    int p = 4;
    int q = 3;
    int r = 5;
    int s = p-++r-q++;

    cout << s << endl;/* operator precedence -/+ < ++/--. so first value of r is taken after the increment of r and value of q is taken before the
    increment of q. */
    
    return 0;
}
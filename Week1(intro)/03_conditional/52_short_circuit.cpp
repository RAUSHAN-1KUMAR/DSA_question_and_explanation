
/* In case of logical OR(||) operator, if expression1 is true then it will not run(check) expression2 and In case of logical AND(&&) operator, 
if expression1 is false then it will not run(check) expression2 this is called short circuit, but in case of Bitwise OR(|) or Bitwise AND(&) 
operator, both the expressions will be executed.
*/

#include<iostream>
using namespace std;

int main()
{
    int a = 5, b = 7, i = 5;

    if(a > b && ++i < b);// as first expression is false so the second expression will not be checked
    {
        cout << i;
    }

    if(a > b || ++i < b){// as first expression is false and we are using OR logical operator so the second expression will be checked 
        cout << " " << i;
    }

    return 0;
}

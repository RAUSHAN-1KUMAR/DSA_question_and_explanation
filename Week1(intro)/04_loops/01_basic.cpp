    
#include<iostream>
using namespace std;
 
int main()
{   
    for(int col = 0 ; col<4 ; col++)
    {
        int num = col+1;
        char ch = 'A' + num - 1;
        cout << ch;
    }
    return 0;
}


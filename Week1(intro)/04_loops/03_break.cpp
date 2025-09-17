
#include<iostream>
using namespace std;

int main()
{
    int i = 1;

    for(;;){
        cout << i << " Hello\n";
        i++;
        if(i>10)
            break;// this statement will terminate the loop
    }

    return 0;
}
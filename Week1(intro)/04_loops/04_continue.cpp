
#include<iostream>
using namespace std;

int main()
{
    int n,i;
    cout << "Enter a number: ";
    cin >> n;

    for(i = 1 ; i<=n ; i++){
        if(i == 4)
            continue;// this statement will skip the below instruction and start the next iteration.
        
        cout << "The value of i is " << i << endl;
    }

    return 0;
}
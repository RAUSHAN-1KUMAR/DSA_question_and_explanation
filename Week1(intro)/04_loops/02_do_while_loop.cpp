// printing the numbers till n.
#include<iostream>
using namespace std;

int main()
{
    int n,i = 1;
    cout << "Enter a number: ";
    cin >> n;

    do{
        cout << i << " ";
        i++;
    }while(i<=n);

    return 0;
}
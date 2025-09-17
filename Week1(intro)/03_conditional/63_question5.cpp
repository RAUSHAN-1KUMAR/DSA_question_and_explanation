
// to check whether a triangle is valid or not.

#include<iostream>
using namespace std;

int main()
{
    int a,b,c;
    cout << "Enter the three sides of a triangle: " << endl;
    cin >> a >> b >> c;

    if(a+b > c && a+c > b && b+c > a){
        cout << "The given triangle is valid." << endl;
    }    
    else{
        cout << "The given triangle is not valid." << endl;
    }
    return 0;
}

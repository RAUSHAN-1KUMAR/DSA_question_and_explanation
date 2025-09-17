/*
To find the number of set bits present in the number
*/

#include<iostream>
#include<bitset>

using namespace std;

int function(int n){
    int count = 0;
    while(n){
        n = n & (n-1);
        count++;
    }

    return count;
}

int main(){

    int num;
    cout << "Enter a number: ";
    cin >> num;

    int setBits = function(num);

    cout << "The number of set bits present in " << num << " is " << setBits << endl;

    return 0;
}
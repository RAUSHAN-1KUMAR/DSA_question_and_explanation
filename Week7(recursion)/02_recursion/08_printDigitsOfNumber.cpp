

#include<iostream>
#include<vector>
#include<limits.h>
using namespace std;

void findIndex(int num)
{
    if(num==0) return;

    findIndex(num/10);

    cout << num%10 << " ";
}

int main()
{
    int number = 42150;

    findIndex(number);

    return 0;
}
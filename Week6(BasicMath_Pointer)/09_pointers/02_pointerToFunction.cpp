
#include<iostream>
using namespace std;

void solve1(int *prr)
{
    prr = prr+1;
}

void solve2(int* &prr)
{
    prr = prr+1;
}


int main()
{
    int a = 5;
    int *arr = &a;

    cout << arr << endl;
    cout << &arr << endl;
    cout << *arr << endl;

    solve1(arr);

    cout << arr << endl;
    cout << &arr << endl;
    cout << *arr << endl;

    solve2(arr);

    cout << arr << endl;
    cout << &arr << endl;
    cout << *arr << endl;//-> garbage value

    return 0;
}

/*
1. prr = prr+1;
    -- this will only increment the prr not arr;


2. void solve(int* &prr){
    prr = prr+1;
   }
    -- not prr is a reference pointer it means prr is another name of arr. So, the value off arr will get change
*/
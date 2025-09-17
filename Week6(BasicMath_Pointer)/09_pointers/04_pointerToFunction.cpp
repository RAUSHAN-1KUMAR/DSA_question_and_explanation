
#include<iostream>
using namespace std;

// since pass by reference so the value will be changed
void solve(int prr[], int size)
{
    *(prr+1) += 5;//-> modified the index 1 element
    prr++;//-> no pointing to 1th index
    *(prr) += 5;//-> again modified the index 1 element
    
    cout << prr[-1] << endl;
    cout << prr[0] << endl;
    cout << prr[1] << endl;
    cout << prr[2] << endl;
    cout << prr[3] << endl;
}

// this is also pass by reference
void solve1(int *prr, int size){}


int main()
{
    int arr[5] = {1,2,3,4,5};

    cout << "Before call: " << endl;
    cout << "At index 1: " << arr[1] << endl;
    cout << "At index 2: " << arr[2] << endl;

    solve(arr,5);

    cout << "After call: " << endl;
    cout << "At index 1: " << arr[1] << endl;
    cout << "At index 2: " << arr[2] << endl;

    return 0;
}


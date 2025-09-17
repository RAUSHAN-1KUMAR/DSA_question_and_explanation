
#include<iostream>
using namespace std;

void solve1(int arr[], int size)
{
    cout << "size of array inside solve1 function: " << sizeof(arr) << endl; //-> output - 4, because array passing into function is by reference so the arr will be treated as int* i.e., a pointer it means only address is being passed not whole data
}

//proof
void solve2(int *arr, int size)
{
    cout << "size of array inside solve2 function: " << sizeof(arr) << endl;
}


int main()
{
    int arr[5] = {1,2,3,4,5};
    cout << "size of array: " << sizeof(arr) << endl;//-> ouput - 20
    solve1(arr,5);
    solve2(arr,5);

    return 0;
}
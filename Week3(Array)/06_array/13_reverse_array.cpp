
/*
A program to reverse an array
*/

#include<iostream>
#include<limits.h>
#include<utility>
using namespace std;
 
int main()
{   
    int arr[7] = {1,0,10,56,3,59,19};
    int size = 7;
    int swap;

    int start = 0;
    int end = size-1;

    while(true)
    {
        if(start > end)
            break;

        else
        {
            swap = arr[start];
            arr[start] = arr[end];
            arr[end] = swap;
            start++;
            end--;
        }
    }

    for(int i = 0 ; i<size ; i++)
    {
        cout << arr[i] << " ";
    }

    return 0;
}



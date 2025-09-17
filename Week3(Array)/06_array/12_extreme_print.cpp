
/*
What we want is, to print the number in alternate way one from begining and one from ending and then again same thing.
*/

#include<iostream>
#include<limits.h>
using namespace std;
 
int main()
{   
    int arr[8] = {1,0,10,56,3,59,19,3};
    int size = 8;

    int start = 0;
    int end = size-1;

    while(true)
    {
        if(start > end)
            break;

        if(start == end)
        {
            cout << arr[start];
            start++;
            end--;
        }
        
        else
        {
            cout << arr[start] << " ";
            cout << arr[end] << " ";
            start++;
            end--;
        }
    }
    return 0;
}



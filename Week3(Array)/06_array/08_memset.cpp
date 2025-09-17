
/*
memset() functioin:-
1. It is a cpp library function used to fill a memory block with a particular values.
2. But we can set any character to string or character array.
*/ 

#include<iostream>
#include<cstring>
using namespace std;
 
int main()
{   
    int arr[10];
    memset(arr,0,sizeof(arr));
    for(int i = 0 ; i<10 ; i++)
    {
        cout << arr[i] << " ";
    }

    cout << endl;

    int prr[10];
    memset(prr,32,sizeof(prr));
    for(int i = 0 ; i<10 ; i++)
    {
        cout << prr[i] << " "; 
    }

    cout << endl;

    char crr[10];
    memset(crr,'%',sizeof(crr));
    for(int i = 0 ; i<10 ; i++) 
    {
        cout << crr[i] << " ";
    }
    return 0;
}



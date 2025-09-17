     
#include<iostream>
#include<limits.h>
using namespace std;
 
int main()
{   
    int arr[7] = {1,0,10,56,3,59,19};
    int size = 7;
    int maxi = INT_MIN;

    for(int i = 0 ; i<size ; i++)
    {
        if(arr[i] > maxi)
        {
            maxi = arr[i];
        }
    }

    cout << "Maximum number is " << maxi << endl;
    
    return 0;
}



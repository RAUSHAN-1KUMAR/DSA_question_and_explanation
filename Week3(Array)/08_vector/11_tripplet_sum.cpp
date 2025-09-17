     
#include<iostream>
#include<vector>
#include<limits.h>
using namespace std;
 
int main()
{   
    vector<int> arr{10,20,40,60,70}; 

    // let check sum = 120;
    for(int i = 0 ; i<arr.size() ; i++)
    {
        for(int j = i+1 ; j<arr.size() ; j++)
        {
            for(int k = j+1 ; k<arr.size() ; k++)
            {
                if(arr[i]+arr[j]+arr[k]==120)
                    cout << "(" << arr[i] << "," << arr[j] << "," << arr[k] << ")" << endl;
                else{
                    continue;
                }
            }
        }
    }    
    return 0;
}


#include<iostream>
using namespace std;

int main()
{   
    int arr[3][3] ={{1,2,3},{4,5,6},{7,8,9}};
    cout << "array arr: " << endl;
    for(int row = 0 ; row<3 ; row++)
    {
        for(int col = 0 ; col<3 ; col++)
        {
            cout << arr[row][col] << " ";
        }
        cout << endl;

    }

    // observe carefully
    int prr[3][4] ={{1,2,3},{4,5,6,10},{7}};
    cout << "array prr: " << endl;
    for(int row = 0 ; row<6 ; row++)
    {
        for(int col = 0 ; col<5 ; col++)
        {
            cout << prr[row][col] << " ";
        }
        cout << endl;

    }

    return 0;
}



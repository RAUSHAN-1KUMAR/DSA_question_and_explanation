#include <iostream> 
using namespace std;

int main()
{
    int marks[4];
    cout << "Enter the elements of array: ";
    cin >> marks[0] >> marks[1] >> marks[2] >> marks[3];//-> we can also use loop to take inputs.

    cout << "your given inputs are: ";
    for(int i = 0 ; i<=4 ; i++)
    {
        cout << marks[i] << " ";
    }

    return 0;
}
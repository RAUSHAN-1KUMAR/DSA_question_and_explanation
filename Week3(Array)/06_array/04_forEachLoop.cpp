#include <iostream> 
using namespace std;

int main()
{
    int marks[4] {1, 5, 56, 32}; //-> we can also initialize without "="

    float money[] = {56.3, 72.4, 101.6, 85.33};

    // special 'for loop' for an array or any collection type of data structure.
    for(int x:marks)//-> this will create a variable x to iterate through each elements in marks, and the loop will run till the no. of element inside array(marks).
    {
        cout << x << endl;//-> So first x will become 1 then x will become 5 then x will become 56 and soon.
    }
    cout << endl;

    for(int x:money)//-> money is a floating array and we are storing its value in a integer data type variable.
    {
        cout << x << endl;
    }
    cout << endl;

    for(float x:money)
    {
        cout << x << endl;
    }
    cout << endl;
    
    
    for(auto x:money)//-> auto keyword will automatically assign the data type of variable x according to the data type of array. 
    {
        cout << x << endl;
    }

    return 0;
}
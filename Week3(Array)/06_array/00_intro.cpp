
// char name[20]; --> name is a 'character array/string'. [20] means it has capacity to store 20 similar elements(char).
// float percentile[90]; --> percentile is a 'float array'. [90] means it has capacity to store 90 similar elements(float).
// int marks[56]; --> marks is an 'integer array'. [56] means it has capacity to store 56 similar elements(int).

#include <iostream> 
using namespace std;

int main()
{
    int marks[4];//--> allocate space for 4 integers
    marks[0] = 34; //--> Why start form 0?.. the array index starts from 0 and end to n-1.
    marks[1] = 35;
    marks[2] = 36;
    marks[3] = 37;

    // array name stores the address of 1st element of the array, proof is given below (but not in case of character array).
    cout << "The address of marks[0] is " << &marks[0] << endl;
    cout << "The address of marks[0] is " << marks << endl;
    cout << "The address of marks[1] is " << &marks[1] << endl;
    cout << "The address of marks[1] is " << marks << endl;//--> the output will be the address of marks[0]

    return 0;
}
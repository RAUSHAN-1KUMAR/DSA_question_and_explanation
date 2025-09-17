
/* Name of a 2D array represents address of the first row in the 2D array and address of nth row of 2D array will same as address of its 1st element. */

#include <iostream>
using namespace std;

int main()
{
    int n_students = 3;
    int n_subjects = 5;
    
    int marks[n_students][n_subjects];//--> first [] is for no. of rows and second [] is for no. of columns.

    for(int i = 0 ; i<n_students ; i++)
    {
        for(int j = 0 ; j<n_subjects ; j++)
        {
            cout << "Enter the marks of student " << i+1 << " in subject " << j+1 << ": " << endl;
            cin >> marks[i][j];
        }
    }

    for(int i = 0; i < n_students; i++)
    {
        for(int j = 0; j < n_subjects; j++)
        {
            cout << "The marks of student " << i+1 << " in subject " << j+1 << " is " << marks[i][j] << endl;
        }
    }

    return 0;
}

/* To initialize 2D array
    int marks[2][2] = {1,2,3,4};
    int marks[][2] = {1,2,3,4};
    int marks[2][2] = {{1,2},{3,4}}; --> first pair of bracket indicates first row and second pair of bracket indicates second row.
    int marks[][2] = {{1,2},{3,4}};
    int marks[][] = {2,3,5,6}; -> error, we can't initiaize like this.
If first pair of sqr bracket is empty it implies that it can have n no. of rows. */

/*
using next_permutatioin() function of STL:-
    -- it gives the next permutation of a given data by modifying it inPlace
*/

#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;

void printPermutation(string &str)
{
    cout << str << endl;

    while (next_permutation(str.begin(), str.end()))
    {
        cout << str << endl;
    }
    
}

int main()
{
    string str = "abc";

    printPermutation(str);
    
    return 0;
}
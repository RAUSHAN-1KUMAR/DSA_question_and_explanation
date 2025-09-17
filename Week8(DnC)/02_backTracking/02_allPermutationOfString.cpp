/*
We have a given string -> abc, we have to print all permutation of the given string  i.e., all sequences
*/

/*
Appraoch:- explained in note copy

Below question is done by simple recursion, then where is the backtracking, see next solution.

Time Complexity:- N!
*/

#include<iostream>
#include<vector>
using namespace std;

void printPermutation(string str, int index)
{
    // base case
    if(index>=str.length()){
        cout << str << " ";
        return;
    }

    for(int j=index; j<str.length(); j++)
    {
        swap(str[index],str[j]);
        printPermutation(str,index+1);
    }
}

int main()
{
    string str = "abc";
    int index=0;
    printPermutation(str,index);
    return 0;
}
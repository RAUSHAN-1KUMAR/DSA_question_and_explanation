/*
We have a given string -> abc, we have to print all permutation of the given string  i.e., all sequences
*/

/*
applying backtracking i.e., call back aate waqt kuch additional kaam kerna

Time Complexity:- N!
*/

#include<iostream>
#include<vector>
using namespace std;

void printPermutation(string &str, int index)//-> change1(&str)
{
    if(index>=str.length()){
        cout << str << " ";
        return;
    }
 
    for(int j=index; j<str.length(); j++)
    {
        swap(str[index],str[j]);

        printPermutation(str,index+1);

        // backtracking
        swap(str[index],str[j]);//-> change2(undoing)
    }
}

int main()
{
    string str = "abc";
    int index=0;
    printPermutation(str,index);
    return 0;
}

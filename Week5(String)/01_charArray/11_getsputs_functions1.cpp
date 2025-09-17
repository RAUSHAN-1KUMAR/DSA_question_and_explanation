
// no need to use cin.ignore() in case of gets().

#include<iostream>
using namespace std;

int main()
{
    char c[20];
    cout << "Enter your name: ";
    gets(c);//--> It is like cin but with the use of gets() we can input multi-word strings with space. 
    cout << "Your name is ";
    puts(c);//--> It is like cout but puts() places the cursor to the next line.

    return 0;
}
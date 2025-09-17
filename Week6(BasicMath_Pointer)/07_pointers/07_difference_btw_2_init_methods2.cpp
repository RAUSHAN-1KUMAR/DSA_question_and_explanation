
#include <iostream>
using namespace std;

int main()
{
    char str[] = "Rohit kumar";
    //str = "Ankit Kumar";-->Invalid because str is an actual array so that's why str acts like a constant pointer. 
    puts(str);

    char *ptr = "Rohit kumar";
    ptr = "Ankit Kumar"; //--> Valid because ptr is a pointer variable which can point to another one somewhere in memory.
    puts(ptr);

    cout << "size of str is: " << sizeof(str) << endl; 
    cout << "size of ptr is: " << sizeof(ptr) << endl; 

    return 0;
}
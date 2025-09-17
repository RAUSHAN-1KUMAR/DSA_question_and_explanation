
#include <iostream>
using namespace std;

int main()
{
    char str[] = "abcd";//--> str is a character array(string).
    str[0] = 'k';
    //str++;--> Invalid because str acts like a constant pointer which we cannot change where str is pointing to.
    cout << str << endl;

    // below method is a bad practice
    
    char *ptr = "efgh";//--> ptr is a pointer to first character in the string leteral wherever it is stored in the memory.
    //ptr[0] = 'm';//--> We cannot modify because compiler don't know where "efgh" is actually stored and we can modify it or not? 
    ptr++;//--> Now ptr is pointing to second character in the string lateral.
    cout << ptr << endl;
    
    return 0;
}
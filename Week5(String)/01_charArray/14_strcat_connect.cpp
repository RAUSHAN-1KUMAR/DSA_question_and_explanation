
#include<iostream>
#include<cstring>
using namespace std;

int main()
{
    char str1[] = "Good";
    char str2[] = "Morning";
    
    cout << "Using strcat function: ";
    strcat(str1,str2);//-> strcat() is used to connect second string(str2) into first string(str1) but without space.
    cout << str1 << endl;

    cout << "Using strncat function: ";
    strncat(str1,str2,3);//-> strncat() is used to connect second string(str2) into first string(str1) only till specified number.
    cout << str1 << endl;

    return 0;
}
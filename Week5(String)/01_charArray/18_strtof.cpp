
// converting a string into a float.
// strtof -> string to float

#include<iostream>
#include<cstring>
using namespace std;

int main()
{
    char str1[] = "54.78";
    char str2[] = {'5','4','.','7','8','9'};
    float x = strtof(str1,NULL);
    float x1 = strtof(str2,NULL);
    
    cout << x << endl;//-> 54.78
    cout << x1 << endl;//-> 54.7895, why??
    return 0;
}
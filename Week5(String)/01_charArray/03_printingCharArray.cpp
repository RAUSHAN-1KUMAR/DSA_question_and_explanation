#include <iostream>
#include <cstring>
#include <array>
#include <vector>
using namespace std;

int main() 
{
    char greeting1[] = "Hello";
    char greeting2[10] = "Hello";  
    char greeting3[6] = {'H', 'e', 'l', 'l', 'o', '\0'};
    char greeting4[10] = {'H', 'e', 'l', 'l', 'o'};
    char greeting5[10] = {};


    // basic printing method
    cout << greeting1 << endl;
    cout << greeting2 << endl;
    cout << greeting3 << endl;
    cout << greeting4 << endl;
    cout << "Length of greeting4: " << strlen(greeting4) << endl;
    cout << "All nulls in greeting5: " << (greeting5[0] == '\0') << endl;


    //using for each loop
    cout << "Using for each loop: " << endl;
    for(auto c:greeting4){
        if(c=='\0') break;
        cout << c << endl;
    }


    //using simple for loop
    cout << "Using simple for loop: " << endl;
    cout << sizeof(greeting4) << endl;
    int n = sizeof(greeting4)/sizeof(greeting4[0]);
    for(int i=0 ; i<n ; i++){
        if(greeting4[i]=='\0') break;
        cout << greeting4[i] << endl;
    }

    return 0;
}

#include<iostream>
using namespace std;

int number(){
    static int c = 0;//-> This executes only ones and next time if this function runs, the value of c remains as previous.
    c = c + 1;
    return c;
}

int main(){
    cout<<number()<<" ";
    cout<<number()<<" ";   
    return 0;
}

#include<iostream>
using namespace std;

int main(){
    int a = 3, b = 4;
    int c = (((((a * 5) + b) - 45) + 87)); /* --> BODMAS rule is not applicable in programming. It follows operator 
    precedence and assossiativity. (assossiativity means left to right or may be right to left, if operators presedence is same) */
    cout<<c;
    return 0;
}
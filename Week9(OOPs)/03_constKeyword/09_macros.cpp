
#include<iostream>
using namespace std;

// MACRO -> before compilation, at the time of preprocessing it will replace the PI with 3.14159465
#define PI 3.14159465
#define MAXX(x,y) (x>y ? x:y)

float circleArea(float r){
    return PI*r*r;
}

void fun(){
    int x = 6;
    int b = 17;
    int c = MAXX(x,b);
    cout << c << endl;
}

int main()
{
    cout << circleArea(2.5) << endl;
    fun();
    return 0;
}





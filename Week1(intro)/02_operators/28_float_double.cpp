
#include<iostream>
using namespace std;

int c = 45;

int main()
{
    float d = 34.4;//-> upto 6 decimal 
    double c = 34.4;//-> upto 15 decimal
    long double e = 34.4;//-> upto 18 decimal
    cout << sizeof(d) << endl << sizeof(c) << endl << sizeof(e) << endl;
    cout << "The value of d is " << d << endl << "The value of e is " << e << endl;

    /* According to compiler every decimal number is a double, So what to do? to make it float or long double?? 
    Answer-> To make it float, we just have to write '34.4f' and to make it long double, write '34.4l' 
    Note:- We can also use capital F and L. */
    float f = 34.4f;
    long double g = 34.4l;

    // Proof is below
    cout << endl;
    cout << "The size of 34.4 is: " << sizeof(34.4) << endl;//--> Double
    cout << "The size of 34.4f is: " << sizeof(34.4f) << endl;//--> Float
    cout << "The size of 34.4F is: " << sizeof(34.4F) << endl;//--> Float
    cout << "The size of 34.4l is: " << sizeof(34.4l) << endl;//--> Long double
    cout << "The size of 34.4L is: " << sizeof(34.4L) << endl;//--> Long double

    return 0;
}
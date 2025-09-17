
// enumeration(enum) is used to assign names to integral constants or integral constant to names.(these are constant we cannot modify them)

#include<iostream>
using namespace std;

int main()
{
    enum meal {breakfast, lunch, dinner};//--> meal is the name of user defined data type, the numbers are given from 0 to 1,2,3,soon
    cout << breakfast << endl;
    cout << lunch << endl;
    cout << dinner << endl;

    //meal m2 = 0;//--> we cannot assign a number by using enum data types, we can only use the names to assign a integer value.
    meal m1 = breakfast;//--> now m1 = 0;
    cout << m1 << endl;
    cout << (m1==5) << endl;//--> comparing, if false == 0 and true == 1

    return 0;
}
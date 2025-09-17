/*
convert KM to Miles
*/

#include<iostream>
using namespace std;

float KMtoMiles(float k)
{
    float _1kmMiles = 0.621371;
    float miles = k * _1kmMiles;
    return miles;
}

int main()
{
    float km;
    cout << "Enter KM value: ";
    cin >> km;

    cout << "In miles = " << KMtoMiles(km) << " miles " << endl;

    return 0;
}
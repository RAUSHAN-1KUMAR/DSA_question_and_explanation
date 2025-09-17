/*
Question:-
    -- you are given a non-negative floating point number rounded to two decimal places 'celcius', that denotes the temperature in Celcius. You should convert celcius into kelvin and fahrenheit and return it as an array 'ans = [kelvin, fahrenheit]'. Return the array ans. Answers within 10^-5 of the actual answer will be accepted.
*/

#include<iostream>
#include<vector>
using namespace std;

class solution{
    public:
        vector<double> convertTemperature(double celcius){
            double k = celcius + 273.15;
            double f = celcius * 1.80 + 32.00;

            vector<double> v;
            v.push_back(k);
            v.push_back(f);
            
            return v;
        }
};

int main()
{

    return 0;
}
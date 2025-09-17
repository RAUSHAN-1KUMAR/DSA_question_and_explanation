/* -> 69
Given a non-negative integer x, return the square root of x, answer should not be rounded down to the nearest integer. The returned integer should be non-negative as well

Example 1:
    Input: x = 4
    Output: 2

Example 2:
    Input: x = 8
    Output: 2.828
*/

/*
Approach:- by lakshaay bhaiyaa
*/

#include<iostream>
#include<vector>
using namespace std;

int mySqrt(int x)
{
    int s = 0;
    int e = x;
    float ans = 0;

    while(s<=e)
    {
        int mid = s + (e-s)/2;

        if(mid*mid == x) return mid;
        else if(mid*mid > x) e = mid-1;
        else{
            ans = mid;
            s = mid+1;
        }
    }

    return ans;
}

double myPrecisionSqrt(int n)
{
    double sqrt = mySqrt(n);

    int precision = 3;
    
    // for fractional part
    double step = 0.1;
    for(int i =0; i<precision ; i++)
    {
        double j = sqrt;
        while(j*j<=n){
            sqrt = j;
            j += step;
        }
        step = step/10;
    }

    return sqrt;
}

int main()
{
    int num;
    
    cout << "number: ";
    cin >> num;

    double sqrt = myPrecisionSqrt(num);

    cout << sqrt << endl;

    return 0;
}
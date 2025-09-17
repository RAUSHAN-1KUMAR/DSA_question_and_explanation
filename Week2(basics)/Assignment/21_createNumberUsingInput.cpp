/*
Same question as '20_function.cpp' but with no limts
*/


#include<iostream>
#include<math.h>
#include<iomanip>
using namespace std;

void createDigits(int n){
    long long int num = 0;

    cout << "Enter digits: ";
    for(int i = 0 ; i<n ; i++)
    {
        int digit;
        cin >> digit;

        int count = 0;
        int dummyDigit = digit;

        while(dummyDigit>0){
            count++;
            dummyDigit /= 10;
        }

        switch(count){
            case 1:
                num = num*10 + digit;
                break;
            
            case 2:
                num = num*100 + digit;
                break;
            
            case 3:
                num = num*1000 + digit;
                break;
            
            case 4:
                num = num*10000 + digit;
                break;
            
            case 5:
                num = num*100000 + digit;
                break;
            
            case 6:
                num = num*1000000 + digit;
                break;

            default:
                cout << "Digit should be less then 7." << endl;
                break;
        }

    }

    cout << "formed number is: " << num << endl;

}


int main()
{
    int numDigts;
    cout << "Enter the total input: ";
    cin >> numDigts;

    createDigits(numDigts);

    return 0;
}
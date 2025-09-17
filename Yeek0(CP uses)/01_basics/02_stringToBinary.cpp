#include<bits/stdc++.h>
using namespace std;


int main()
{
    // binary string to decimal
    string s1 = "10";
    int binaryRep = stoi(s1, 0, 2);//2 -> given string is binary string 
    cout << binaryRep << endl;

    // number to binary
    int num=5;// in three bit
    string bin=bitset<10>(num).to_string();
    bin=bin.substr(10-3, 3);
    cout << bin << endl;

    return 0;
}
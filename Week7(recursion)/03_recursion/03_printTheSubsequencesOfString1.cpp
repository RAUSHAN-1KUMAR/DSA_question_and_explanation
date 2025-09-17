/*
solving iteratively
*/

#include<iostream>
#include<vector>
#include<algorithm>
#include<math.h>
using namespace std;

void findSubsequences(string &s)
{
    // total no. of subsequences
    int total_subs = pow(2,s.size());

    for(int n=0; n<total_subs ; n++)
    {
        string out = "";
        int num=n;

        int i=0;
        while (num)
        {
            int b = (num&1);
            if(b) out.push_back(s[i]);
            i++;
            num >>= 1;
        }
        cout << out << endl;
    }
}


int main()
{
    string str = "abc";

    findSubsequences(str);

    return 0;
}
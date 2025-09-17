

#include<iostream>
using namespace std;

void removeOCCRE(string &s, string &part)
{
    int found= s.find(part);
    if(found!=string::npos)
    {
        string left_part = s.substr(0,found);
        string right_part = s.substr(found+part.size(), s.size());

        s = left_part + right_part;

        removeOCCRE(s,part);
    }
    else{//base case
        return;
    }
}

string removeOccurrences(string s, string part)
{
    removeOCCRE(s, part);

    return s;
}


int main()
{
    string s = "daabcbaabcbc";
    string part = "abc";

    string ans = removeOccurrences(s,part);

    cout << ans << endl;

    return 0;
}

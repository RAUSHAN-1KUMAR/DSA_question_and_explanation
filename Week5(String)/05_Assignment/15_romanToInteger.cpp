#include <bits/stdc++.h>
using namespace std;

unordered_map<char, int> hashRoman = {
    {'I', 1},
    {'V', 5},
    {'X', 10},
    {'L', 50},
    {'C', 100},
    {'D', 500},
    {'M', 1000}};

int romanToInt(string s)
{
    int i = 0, n = s.size();
    int ans = 0;
    while (i < n)
    {
        ans += hashRoman[s[i]];

        if (i > 0 && hashRoman[s[i]] > hashRoman[s[i - 1]])
        {
            ans -= 2 * hashRoman[s[i - 1]];
        }

        i++;
    }

    return ans;
}

int main()
{
    string s = "MCMXCIV";
    cout << romanToInt(s) << endl;
    return 0;
}
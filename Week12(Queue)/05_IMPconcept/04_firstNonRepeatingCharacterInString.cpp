/* GFG
Given an input stream A of n characters consisting only of lower case alphabets. While reading characters from the stream, you have to tell which character has appeared only once in the stream upto that point. If there are many characters that have appeared only once, you have to tell which one of them was the first one to appear. If there is no such character then append '#' to the answer

Example:
    Input: A = "aabc"
    Output: "a#bb"
    Explanation: For every ith character we will consider the string from index 0 till index i first non repeating character is as follow-
    "a" - first non-repeating character is 'a'
    "aa" - no non-repeating character so '#'
    "aab" - first non-repeating character is 'b'
    "aabc" - there are two non repeating characters 'b' and 'c', first non-repeating character is 'b' because 'b' comes before 'c' in the stream.
*/

/*
Appraoch:- queue + (freuency table of character using int freq[26])
    -- queue ka use kregen kyunki mujhe first non-repeating character batanah.
    -- So, string m iterate krengen, aur sabse phele jo character ayega uska frequency store krengen array m and then uss character ko push krengen queue m, ye dono step krene ke baad queue m ab iterate kregen starting se aur jis bhi chracter ka freuency 1 hoga wo uss character tak first non-repeating character h, aur jis character ka freuency 1 nhi hoga usko pop ker dengen queue se(q.pop() front se pop ho jayega kyunki front wala ka hi frequence more than 1 aya h)
    -- ager pop kerte kerte queue empty ho gyi to ab uss character tak ka answer '#' hoga

Note:- freq 1 se jyada ho rha to pop ker rhe h, yahi yanha p catch h, waise bina pop kiye bhi answer aa jayega but pop kerne se comparison kam ho rha h
*/

#include <iostream>
#include <queue>
using namespace std;

string FirstNonRepeating(string &s)
{
    vector<int> hash(26, 0);
    int i = 0, n = s.size();

    queue<char> qu;
    string ans;
    while (i < n)
    {
        int ch = s[i] - 'a';
        hash[ch]++;

        // only push the character into queue if its first time
        if (hash[ch] <= 1) qu.push(s[i]);

        // we do gonna take from front of the queue, but first remove them who has occured more than 1 times
        while (!qu.empty() && hash[qu.front() - 'a'] > 1) qu.pop();

        // if queue is emtpy then push '#'
        if (qu.empty())
            ans.push_back('#');
        else
            ans.push_back(qu.front());

        i++;
    }

    return ans;
}

int main()
{
    string s = "aabcb";

    string ans = FirstNonRepeating(s);

    for (char ch : ans)
    {
        cout << ch << " ";
    }
    cout << endl;

    return 0;
}
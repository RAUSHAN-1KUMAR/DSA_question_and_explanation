/* Q.no: 2325

You are given the strings key and message, which represent a cipher key and a secret message, respectively. The steps to decode message are as follows:
    1. Use the first appearance of all 26 lowercase English letters in key as the order of the substitution table.
    2. Align the substitution table with the regular English alphabet.
    3. Each letter in message is then substituted using the table.
    4. Spaces ' ' are transformed to themselves(' ').
    5. For example, given key = "happy boy" (actual key would have at least one instance of each letter in the alphabet), we have the partial substitution table of ('h' -> 'a', 'a' -> 'b', 'p' -> 'c', 'y' -> 'd', 'b' -> 'e', 'o' -> 'f').

Return the decoded message.

Example:-
    Input: key = "the quick brown fox jumps over the lazy dog", message = "vkbs bs t suepuv"
    Output: "this is a secret"
    Explanation: The diagram below shows the substitution table. It is obtained by taking the first appearance of each letter in "the quick brown f(o)x j(u)mps (o)v(e)(r) (the) lazy d(o)g".(-> bracket tell that tha character is already taken in substitution table)

    Substituition table:-
        Given key: the quick brown fx jmps v lazy dg
        alphabet:  abc defgh ijklm no pqrs t uvwx yz

*/

/*
Approach:-
    -- make the substitution table, by creating a character array(let sey mapping) and then key ke starting se lekar end character tak ke ASCII code ke respective postion m a se z tak fill krenge mapping array m aur
    -- jab message decode kerna hoga to, message ke starting se end character ke ASCII code ke respective character push ker lengen mapping wale array se kisi ans string m.

Note:- observe the mapping, it is done in so good way without using map or pair or set STL.
*/



#include<iostream>
using namespace  std;

string decodeMessage(string key, string message)
{
    // creating mapping
    char start = 'a';
    char mapping[280] = {0}; 

    for(auto ch:key)
    {   
        if(ch != ' ' && mapping[ch]==0){
            mapping[ch] = start;
            start++;
        }
    }

    // using mapping
    string ans;

    for(auto msg:message)
    {
        if(msg == ' ') ans.push_back(' ');
        else{
            ans.push_back(mapping[msg]);
        }
    }

    return ans;
}


int main()
{
    string key = "the quick brown fox jumps over the lazy dog";

    string message = "vkbs bs t suepuv";

    cout << decodeMessage(key, message) << endl;

    return 0;
}
/* -> 1002

Given a string array words, return an array of all characters that show up in all strings within the words (including duplicates). You may return the answer in any order.


Example 1:
Input: words = ["bella","label","roller"]
Output: ["e","l","l"]

Example 2:
Input: words = ["cool","lock","cook"]
Output: ["c","o"]
*/

#include<iostream>
#include<vector>
#include<limits.h>
using namespace std;

void fillCount(string &word, vector<int> &temp)
{
    for(auto eachC:word){
        temp[eachC-'a']++;
    }
}

vector<string> commonChars(vector<string>& words) 
{
    vector<string> ans;

    // creating hashing of first string
    vector<int> hash(26,0);
    fillCount(words[0],hash);

    // now checking with all other string
    for(int i=1 ; i<words.size() ;i++)
    {
        vector<int> temp(26,0);
        fillCount(words[i],temp);
        // storing the minimum freq of each character in main hash vector w.r.t upcoming string
        for(int j=0 ; j<26 ; j++){
            hash[j] = min(hash[j],temp[j]);
        }
    }

    // forming the answer string
    for(int i=0 ; i<26 ; i++)
    {
        int chFreq = hash[i];
        while(chFreq)
        {
            ans.push_back(string(1, i+'a'));
            chFreq--;
        }  
    }

    return ans;
}

int main()
{
    vector<string> words = {"bella", "label", "roller"};

    vector<string> ans = commonChars(words);

    for(auto eachS:ans){
        cout << eachS << endl;
    }
    
    return 0;
}
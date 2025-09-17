#include<bits/stdc++.h>
using namespace std;

int main() {
    // ordered set(ascending)
    set<int> st;
    st.insert(2);
    st.insert(0);
    st.insert(1);
    for(int num:st) cout << num << " ";
    cout << endl << endl;

    // ordered set(descending)
    set<int, greater<int>> st2;
    st2.insert(2);
    st2.insert(0);
    st2.insert(10);
    for(int num:st2) cout << num << " ";
    cout << endl << endl;

    // ordered map
    map<int, int> mp;// will be sorted w.r.t key
    mp[10]=20;
    mp[0]=5;
    mp[1]=2;
    for(auto mPair:mp){
        cout << mPair.first << " " << mPair.second << endl;
    }
    cout << endl;

    // unordered mao
    unordered_map<int,int> ump;
    ump[5]++;
    ump[5]++;
    ump[3]++;
    ump[3]++;
    ump[3]++;
    ump[1]++;
    ump[1]++;
    for(auto umPair:ump){
        cout << umPair.first << " " << umPair.second << endl;
    }
    cout << endl;
    return 0;
}

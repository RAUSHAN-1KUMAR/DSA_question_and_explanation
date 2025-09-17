/* -> 2327

On day 1, one person discovers a secret.

You are given an integer delay, which means that each person will share the secret with a new person every day, starting from delay days after discovering the secret. You are also given an integer forget, which means that each person will forget the secret forget days after discovering it. A person cannot share the secret on the same day they forgot it, or on any day afterwards.

Given an integer n, return the number of people who know the secret at the end of day n. Since the answer may be very large, return it modulo 10^9 + 7.


Example 1:
    Input: n = 6, delay = 2, forget = 4
    Output: 5
    Explanation:
    Day 1: Suppose the first person is named A. (1 person)
    Day 2: A is the only person who knows the secret. (1 person)
    Day 3: A shares the secret with a new person, B. (2 people)
    Day 4: A shares the secret with a new person, C. (3 people)
    Day 5: A forgets the secret, and B shares the secret with a new person, D. (3 people)
    Day 6: B shares the secret with E, and C shares the secret with F. (5 people)

Example 2:
    Input: n = 4, delay = 1, forget = 3
    Output: 6
    Explanation:
    Day 1: The first person is named A. (1 person)
    Day 2: A shares the secret with B. (2 people)
    Day 3: A and B share the secret with 2 new people, C and D. (4 people)
    Day 4: A forgets the secret. B, C, and D share the secret with 3 new people. (6 people)

*/

// One approach Question Type -> simulation i.e., queue m hi pop kerna h then push kerna h ya phir q m push ker rhe h then kuch operation ker rhe h

// Another approach -> just do what they said, form its delay to forget, it will tell secret to other people

// remember to add modulo, because its given in question to return in modulo 10^9 + 7


#include<iostream>
#include<queue>
using namespace std;


// Approach1: TC: O(n)
int peopleAwareOfSecret(int n, int delay, int forget)
{
    const int M = 1e9+7;
    
    // {day, people_count}
    queue<pair<int,int>> forgetQ;// forgetQ is for, naye log jo add hue the isme, unke forget days ko check kerne ke liye, ager wo forget hote h to unko pop ker dengen and then ans and cur variable se minus ker dengen
    queue<pair<int,int>> delayQ;// delayQ is for, naye log jo add hue the isme, wo kab active honge, active hone ke baad usko pop ker dengen and cur variable me add ker denge
    
    // {day(1), onlyPeople(1)}
    forgetQ.push({1,1});
    delayQ.push({1,1});
    
    int cur = 0; // current day active spreader
    int ans = 1; // it will store our answer: kitne logo ko secret pata h
    for(int i=1 ; i<=n ; i++)// i represents current day
    {
        // step 1: forget check -> ager push wale din se lekar forget days tak aa gye h to pop kerdo
        int forgetDay = forgetQ.front().first;
        if(!forgetQ.empty() && forgetDay + forget <= i)
        {
            auto front = forgetQ.front();
            forgetQ.pop();//-> pop ker diye, jo forget ho gya usko nikal do

            // but

            // kitne log forget hue usko hatana bhi to h
            int forgetPeople = front.second;
            ans = (ans - forgetPeople + M) % M;

            // ab jo bhul gya h wo current spreader bhi nhi hoga
            cur = (cur - forgetPeople + M) % M;
        }

        // step 2: make new active spreader -> ager push wale din ab delay jitna ho gya h to wo ab ek active speaker h, 
        int delayDay = delayQ.front().first;
        if(!delayQ.empty() && delayDay+delay <= i)
        {
            auto front = delayQ.front();
            delayQ.pop();//-> pop ker diye, jo ab active ho gya usko nikal do

            // but

            // jitne log active hue unko add bhi to kerna h
            int activePeople = front.second;
            cur = (cur + activePeople) % M;
        }


        // jitne log iss(i) din active h spread kerne ke liye utne log add ho jayengen ans m
        if(cur>0)
        {
            // add ker diye
            ans = (ans + cur) % M;

            // but

            // jo neye log add hue h unko queue m push to kerdo
            forgetQ.push({i,cur});//-> jitne active spreader the utne log isss(i) din add honge
            delayQ.push({i,cur});
        }
    }

    return ans;
}


// Another approach TC:- O(n*n)
int peopleAwareOfSecret1(int n, int delay, int forget) 
{
    int mod=1e9+7;

    vector<int> dp(2*n, 0); // nth day p kitne logo ko secret pata pada: matlab kitne naye log uss din secret ko jaane

    dp[1] = 1;

    for(int i=1 ; i<=n ; i++){
        for(int k=i+delay ; k<i+forget ; k++){
            dp[k] = (dp[k]+dp[i]) % mod;
        }
    }// we have calculated on each day kitne log naye enter kiye

    // ab nth day ke liye naye + purane jitne active h 
    int i=0; long long ans=0;
    while(forget--){
        ans = (ans + dp[n-i]) % mod;
        i++;
    }

    return ans;
}


int main()
{
    int n=6, delay=2, forget=4;

    cout << peopleAwareOfSecret(n,delay,forget) << endl;

    return 0;
}

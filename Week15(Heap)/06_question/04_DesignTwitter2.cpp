
#include<bits/stdc++.h>
using namespace std;

class Twitter 
{
    unordered_map<int, set<int>> followMap;
    unordered_map<int, vector<pair<int,int>>> tweetsMap;
    int time;

public:
    Twitter() {
        time = 0;
    }
    
    void postTweet(int userId, int tweetId) 
    {
        // userId ke specific, tweet push kerdo
        tweetsMap[userId].push_back({time++, tweetId});
    }
    
    vector<int> getNewsFeed(int userId) 
    {
        priority_queue<pair<int,int>> pq;

        // user ke tweets and uske followers ke saare tweets ko maxHeap m push kerdo
        for(auto t :tweetsMap[userId]){
            pq.push(t);
        }
        for(auto f : followMap[userId]){
            for(auto t: tweetsMap[f]){
                pq.push(t);
            }
        }

        // push kerne ke baad top 10 ko lelo
        vector<int> res;
        int n=10;
        while(!pq.empty() && n){
            n--;
            res.push_back(pq.top().second);
            pq.pop();
        }
        return res;
    }
    
    void follow(int followerId, int followeeId) {
        followMap[followerId].insert(followeeId);
    }
    
    void unfollow(int followerId, int followeeId) {
        followMap[followerId].erase(followeeId);
    }
};

int main()
{


    return 0;
}
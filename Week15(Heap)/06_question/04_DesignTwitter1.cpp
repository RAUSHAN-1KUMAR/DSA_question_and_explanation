/* -> 355\

Design a simplified version of Twitter where users can post tweets, follow/unfollow another user, and is able to see the 10 most recent tweets in the user's news feed.

Implement the Twitter class:
    - Twitter() Initializes your twitter object.

    - void postTweet(int userId, int tweetId):- Composes a new tweet with ID tweetId by the user userId. Each call to this function will be made with a unique tweetId.

    - List<Integer> getNewsFeed(int userId):- Retrieves the 10 most recent tweet IDs in the user's news feed. Each item in the news feed must be posted by users who the user followed or by the user themself. Tweets must be ordered from most recent to least recent.

    - void follow(int followerId, int followeeId):- The user with ID followerId started following the user with ID followeeId.

    - void unfollow(int followerId, int followeeId):- The user with ID followerId started unfollowing the user with ID followeeId.
 

Example 1:
    Input:
    ["Twitter", "postTweet", "getNewsFeed", "follow", "postTweet", "getNewsFeed", "unfollow", "getNewsFeed"]
    [[], [1, 5], [1], [1, 2], [2, 6], [1], [1, 2], [1]]

    Output: [null, null, [5], null, null, [6, 5], null, [5]]

    Explanation
    Twitter twitter = new Twitter();
    twitter.postTweet(1, 5); // User 1 posts a new tweet (id = 5).
    twitter.getNewsFeed(1);  // User 1's news feed should return a list with 1 tweet id -> [5]. return [5]
    twitter.follow(1, 2);    // User 1 follows user 2.
    twitter.postTweet(2, 6); // User 2 posts a new tweet (id = 6).
    twitter.getNewsFeed(1);  // User 1's news feed should return a list with 2 tweet ids -> [6, 5]. Tweet id 6 should precede tweet id 5 because it is posted after tweet id 5.
    twitter.unfollow(1, 2);  // User 1 unfollows user 2.
    twitter.getNewsFeed(1);  // User 1's news feed should return a list with 1 tweet id -> [5], since user 1 is no longer following user 2.

*/

/*
Approach:- Better approach
    -- her ek user ka apna khus ke tweets and follow kis kis ko kiya h
    -- tweets will contain time, tweetID
    -- aur jab NewsFeed call ho tab, her followers ke 10 10 tweets and khudke 10 tweets ko maxHeap push kerdo and then maxHeap to ans array m bas top ke 10 tweets, and return the ans vector.

Below code ko aur optimise ker sakte h in sense of code and SC not TC. -> see next solution
*/

#include<bits/stdc++.h>
using namespace std;

class Tweet
{
public:
    int time;
    int tweetId;

    Tweet(int t, int id)
    {
        time = t;
        tweetId = id;
    }
};

class compare
{
public:
    bool operator()(Tweet &a, Tweet &b){
        return a.time < b.time;
    }
};

class User
{
public:
    int userId;
    unordered_set<int> followers;
    list<Tweet> tweets;

    User(){
        userId=-1;
    }

    User(int userId)
    {
        this->userId = userId;
    }

    void addTweet(Tweet t)
    {
        tweets.push_front(t);
    }

    void addFollower(int followeeId)
    {
        followers.insert(followeeId);
    }

    void removeFollower(int followeeId)
    {
        followers.erase(followeeId);
    }
};

class Twitter 
{
public: 
    int timeCounter=0;
    unordered_map<int, User> userMap;

    Twitter(){}
    
    void postTweet(int userId, int tweetId)
    {
        timeCounter++;

        if(userMap.find(userId)==userMap.end())
        {
            userMap[userId] = User(userId);
        }

        userMap[userId].addTweet(Tweet(timeCounter, tweetId));
    }
    
    vector<int> getNewsFeed(int userId)
    {
        if(userMap.find(userId)==userMap.end())
        {
            return vector<int> {};
        }

        priority_queue<Tweet, vector<Tweet>, compare> maxHeap;

        User &user = userMap[userId];
        for(int followerId:user.followers)
        {
            int count=0;
            for(Tweet tweet:userMap[followerId].tweets)
            {
                maxHeap.push(tweet);
                count++;
                if(count>10)
                    break;
            }
        }

        int count=0;
        for(Tweet tweet: user.tweets)
        {
            maxHeap.push(tweet);
            count++;
            if(count>10)
                break;
        }

        count=0;
        vector<int> ans;
        while(!maxHeap.empty() && count<10)
        {
            ans.push_back(maxHeap.top().tweetId);
            maxHeap.pop();
            count++;
        }

        return ans;
    }
    
    void follow(int followerId, int followeeId)
    {
        if(userMap.find(followerId)==userMap.end())
        {
            userMap[followerId] = User(followerId);
        }

        if(userMap.find(followeeId)==userMap.end())
        {
            userMap[followeeId] = User(followeeId);
        }

        userMap[followerId].addFollower(followeeId);
    }
    
    void unfollow(int followerId, int followeeId)
    {
        if(userMap.find(followeeId)==userMap.end() || userMap.find(followeeId)==userMap.end())
        {
            return;
        }  

        userMap[followerId].removeFollower(followeeId);
    }
};


int main()
{

    return 0;
}
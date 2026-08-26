class Twitter {
    long long timeStamp;
    unordered_map<int, vector<pair<long long, int>>> tweets;
    unordered_map<int, unordered_set<int>> following;

public:
    Twitter() {
        timeStamp = 0;
    }
    
    void postTweet(int userId, int tweetId) {
        tweets[userId].push_back({timeStamp++, tweetId});
    }
    
    vector<int> getNewsFeed(int userId) {
        priority_queue<pair<long long, int>> maxHeap;
        
        for (auto& tweet : tweets[userId]) {
            maxHeap.push(tweet);
        }
        
        following[userId].insert(userId);
        for (int followeeId : following[userId]) {
            if (followeeId == userId) continue;
            for (auto& tweet : tweets[followeeId]) {
                maxHeap.push(tweet);
            }
        }
        
        vector<int> res;
        int n = 0;
        while (!maxHeap.empty() && n < 10) {
            res.push_back(maxHeap.top().second);
            maxHeap.pop();
            n++;
        }
        
        return res;
    }
    
    void follow(int followerId, int followeeId) {
        if (followerId != followeeId) {
            following[followerId].insert(followeeId);
        }
    }
    
    void unfollow(int followerId, int followeeId) {
        if (following[followerId].find(followeeId) != following[followerId].end()) {
            following[followerId].erase(followeeId);
        }
    }
};
#include<bits/stdc++.h>
using namespace std;

class Twitter {
public:
    struct compare {
        bool operator()(vector<int>& p, vector<int>& q) {
            return p[0] < q[0];
        }//need minheap so ordering p > q so that min element is on top
    };
    
    int t;
    unordered_map<int, vector<vector<int>>> utline;
    //maps uid to all their posts, saved as uid -> timestamp, tweetid
    
    
    unordered_map<int, unordered_set<int>> following;
    //map id to whoever he follows
    
    int uid=0, tid=0;
    Twitter() {
        t = 0;
    }
    
    void postTweet(int userId, int tweetId) {
        //put tweet in my timeline
        utline[userId].push_back({t, tweetId});
        t++;
        return;
    }
    
    vector<int> getNewsFeed(int userId) {
        following[userId].insert(userId);   //my timeline must be displayed in my feed (incase follow() hasnt been called once also)
        vector<int> ans;    //ans 
        
        //slower solution, TC: O(alltweets*log(10))
        /*
        priority_queue<vector<int>, vector<vector<int>>, compare> pq;   //heap to store 10 most recent tweeets by tweeters
        unordered_set<int>& tweeters = following[userId];
        if(tweeters.size() <= 0) return {};
        
        for(int tweeter:tweeters) {
            for(auto vec:utline[tweeter]) {
                pq.push(vec);
                if(pq.size() > 10)
                    pq.pop();
            }
        }
        
        while(pq.size()) {
            ans.push_back(pq.top()[1]);
            pq.pop();
        }
        reverse(ans.begin(), ans.end());
        */
        //need to find code for better solution that uses my oo design
        //below usage of max heap drops space omplexity by 50% but increases TC by 100%
        priority_queue<vector<int>, vector<vector<int>>, compare> pq;   //heap to store 10 most recent tweeets by tweeters
        unordered_set<int>& tweeters = following[userId];
        if(tweeters.size() <= 0) return {};
        
        for(int tweeter:tweeters) {
            for(auto vec:utline[tweeter]) {
                pq.push(vec);
            }
        }
        
        while(ans.size() < 10 && pq.size() != 0) {
            ans.push_back(pq.top()[1]);
            pq.pop();
        }
        return ans;
    }
    
    void follow(int me, int celeb) {
        following[me].insert(me);   //for some reason, i follow myself
        following[me].insert(celeb);   //add celeb to list of ppl i follow
        return;
    }
    
    void unfollow(int me, int celeb) {
        following[me].erase(celeb);    //remove celeb from list of ppl i follow
        return;
    }
};

/**
 * Your Twitter object will be instantiated and called as such:
 * Twitter* obj = new Twitter();
 * obj->postTweet(userId,tweetId);
 * vector<int> param_2 = obj->getNewsFeed(userId);
 * obj->follow(followerId,followeeId);
 * obj->unfollow(followerId,followeeId);
 */
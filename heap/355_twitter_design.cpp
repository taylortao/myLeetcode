class Twitter {
private:
	int timeId = 0;
	struct tweet
	{
		bool operator()(pair<int, int>& p1, pair<int, int>& p2) const{
			return p1.second > p2.second;
		}
	};
	
	unordered_map<int, unordered_map<int, bool>> userRelationship;
	unordered_map<int, vector<pair<int, int>>> userTweets;
	
public:
    /** Initialize your data structure here. */
    Twitter() {
    }
    
    /** Compose a new tweet. */
    void postTweet(int userId, int tweetId) {
        auto it = userTweets.find(userId);
		if (it == userTweets.end())
		{
			vector<pair<int, int>> tweetList;
			tweetList.push_back(make_pair(tweetId, timeId++));
			userTweets.insert(make_pair(userId, tweetList));
		}
		else
		{
			(it->second).push_back(make_pair(tweetId, timeId++));
		}
    }
    
    /** Retrieve the 10 most recent tweet ids in the user's news feed. Each item in the news feed must be posted by users who the user followed or by the user herself. Tweets must be ordered from most recent to least recent. */
    vector<int> getNewsFeed(int userId) {
		priority_queue<pair<int, int>, vector<pair<int, int>>, tweet> f_queue;
		auto it = userTweets.find(userId);
		if (it != userTweets.end())
		{
			for (int index = (it->second).size() - 1; index >= 0; index --)
			{
				pair<int, int> p = (it->second)[index];
				if (f_queue.size() < 10)
				{
					f_queue.push(p);
				}
				else if (p.second > f_queue.top().second)
				{
					f_queue.pop();
					f_queue.push(p);
				}
				else
				{
					break;
				}
			}
		}
		
        auto it2 = userRelationship.find(userId);
		if (it2 != userRelationship.end())
		{
			for (auto userIdIt = (it2->second).begin(); userIdIt != (it2->second).end(); userIdIt ++)
			{
				if (userIdIt->second && (userIdIt->first) != userId)
				{
					auto tit = userTweets.find(userIdIt->first);
					if (tit != userTweets.end())
					{
						for (int index = (tit->second).size() - 1; index >= 0; index --)
						{
							pair<int, int> p = (tit->second)[index];
							if (f_queue.size() < 10)
							{
								f_queue.push(p);
							}
							else if (p.second > f_queue.top().second)
							{
								f_queue.pop();
								f_queue.push(p);
							}
							else
							{
								break;
							}
						}
					}
				}
			}
		}
		
		int feedSize = f_queue.size();
		vector<int> feeds(feedSize, 0);
		while(!f_queue.empty())
		{
			feeds[--feedSize] = (f_queue.top().first);
			f_queue.pop();
		}
		
		return feeds;
    }
    
    /** Follower follows a followee. If the operation is invalid, it should be a no-op. */
    void follow(int followerId, int followeeId) {
        auto it = userRelationship.find(followerId);
		if (it == userRelationship.end())
		{
			unordered_map<int, bool> followers;
			followers[followeeId] = true;
			userRelationship.insert(make_pair(followerId, followers));
		}
		else
		{
			(it->second)[followeeId] = true;
		}
    }
    
    /** Follower unfollows a followee. If the operation is invalid, it should be a no-op. */
    void unfollow(int followerId, int followeeId) {
        auto it = userRelationship.find(followerId);
		if (it != userRelationship.end())
		{
			(it->second).erase(followeeId);
		}
    }
};

/**
 * Your Twitter object will be instantiated and called as such:
 * Twitter obj = new Twitter();
 * obj.postTweet(userId,tweetId);
 * vector<int> param_2 = obj.getNewsFeed(userId);
 * obj.follow(followerId,followeeId);
 * obj.unfollow(followerId,followeeId);
 */
 
 
 /** test cases:
 ["Twitter","postTweet","getNewsFeed","follow","postTweet","getNewsFeed","unfollow","getNewsFeed"]
[[],[1,5],[1],[1,2],[2,6],[1],[1,2],[1]]

followes himself
["Twitter","postTweet","follow","getNewsFeed"]
[[],[1,5],[1,1],[1]]

**/
class Solution {
public:
    int rob(vector<int>& nums) {
        int len = nums.size();
		if (len == 0)
		{
			return 0;
		}
		
		vector<int> dp;
		for (int i=0; i<len; i++)
		{
			int crtVal = max((i >= 2 ? dp[i - 2] : 0) + nums[i], (i >= 1 ? dp[i-1] : 0));
			dp.push_back(crtVal);
		}
		
		return dp[len-1];
    }
};

/*
[]
[2]
[23,2]
[23,32,43,12,43,32,1,1,2,13,12,32,3,23]
*/

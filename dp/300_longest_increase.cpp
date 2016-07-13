class Solution {
public:
    int lengthOfLIS(vector<int>& nums) {
        vector<int> dp;
		dp.push_back(1);
		int len = nums.size(), maxVal = len==0 ? 0 : 1;
		for (int i=1; i<len; i++)
		{
			int tpMax = 1;
			for (int j=i-1; j>=0; j--)
			{
				if (nums[j] < nums[i] && dp[j] + 1 > tpMax)
				{
					tpMax = dp[j] + 1;
				}
			}
			
			dp.push_back(tpMax);
			if (tpMax > maxVal)
			{
				maxVal = tpMax;
			}
		}
		
		return maxVal;
    }
};

/*
test cases:
[]
[1]
[2,1]
[1,2]
[1,54,36,2,6,12,2,54,45,65,1,8,23]
*/
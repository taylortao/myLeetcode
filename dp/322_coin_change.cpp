class Solution {
public:
    int coinChange(vector<int>& coins, int amount) {
		if (coins.empty() || amount < 0)
		{
			return -1;
		}
		
        vector<int> dp;
		dp.push_back(0);
		for (int i=1; i<=amount; i++)
		{
			int min = -1, size = coins.size();
			for (int j=0; j<size; j++)
			{
				if (i >= coins[j] && dp[i - coins[j]] >= 0)
				{
					int tmp = dp[i - coins[j]] + 1;
					if (min == -1 || min > tmp)
					{
						min = tmp;
					}
				}
			}
			
			dp.push_back(min);
		}
		
		return dp[amount];
    }
};

/*
test cases:
[] 0
[1, 2] 0
[1,2,5,9,22] 9205
*/
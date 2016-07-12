class Solution {
public:
    vector<int> largestDivisibleSubset(vector<int>& nums) {
		vector<int> result;
		if (nums.size() > 0)
		{
			sort(nums.begin(), nums.end());
			vector<int> dp, last;
			dp.push_back(1);
			last.push_back(-1);
			int len = nums.size(), max = 1, maxLast = 0;
			for (int i=1; i<len; i++)
			{
				int tpmax = 1, tplast = -1;
				for (int j=i-1; j>=0; j--)
				{
					if (dp[j] + 1 > tpmax && nums[i] % nums[j] == 0)
					{
						tpmax = dp[j] + 1;
						tplast = j;
					}
				}
				
				dp.push_back(tpmax);
				last.push_back(tplast);
				if (tpmax > max)
				{
					max = tpmax;
					maxLast = i;
				}
			}
			
			while (maxLast >= 0)
			{
				result.push_back(nums[maxLast]);
				maxLast = last[maxLast];
			}
		}
		
		return result;
    }
};

/*
test cases:
[], [1], [1, 3], [2,3]
[1,2,3,4,5,6,7,8,9,10]
[10,9,8,7,6,5,4,3,2,1]
*/
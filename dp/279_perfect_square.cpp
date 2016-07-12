class Solution {
public:
    int numSquares(int n) {
        vector<int> dp;
		dp.push_back(0);
		dp.push_back(1);
		for (int i=2; i<=n; i++)
		{
			int minv = INT_MAX;
			for (int j=1; ;j++)
			{
				int jsq = j*j;
				if (jsq > i)
				{
					break;
				}
				
				int val = dp[i-jsq] + 1;
				if (val < minv)
				{
					minv = val;
				}
			}
			
			dp.push_back(minv);
		}
		
		return dp[n];
    }
};

/*
test cases
0
1
25
372
*/
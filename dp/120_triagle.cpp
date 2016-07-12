class Solution {
public:
    int minimumTotal(vector<vector<int>>& triangle) {
        vector<int> sum;
		int len = triangle.size(), minv = INT_MAX;
		if (len == 0)
		{
			return 0;
		}
		
		sum.push_back(triangle[0][0]);
		for (int i=1; i<len; i++)
		{
			vector<int> row = triangle[i];
			sum.push_back(row[i] + sum[i-1]);
			for (int j=i-1; j>0; j--)
			{
				sum[j] = (min(sum[j-1], sum[j])) + row[j];
			}
			
			sum[0] += row[0];
		}
		
		for (int i=0; i<len; i++)
		{
			if (minv > sum[i])
			{
				minv = sum[i];
			}
		}
		
		return minv;
    }
};

/*
test cases:
[[]]
[[-10]]
[[1],[2,3],[4,5,6]]
[[2],[3,4],[6,5,7],[4,1,8,3]]

please note that in the process of calculation, the latter value may overlap the previous value.
right: for (int j=i-1; j>0; j--)
wrong for (int j=0; j<i; j++)
*/
class Solution {
public:
    int rob(vector<int>& nums) {
        int len = nums.size();
		if (len == 0)
		{
			return 0;
		}
		else if (len == 1)
		{
			return nums[0];
		}
		
		vector<int> dp1, dp2;
		dp1.push_back(nums[0]);
		dp2.push_back(0);
		for (int i=1; i<len; i++)
		{
			dp1.push_back(max((i >= 2 ? dp1[i - 2] : 0) + nums[i], dp1[i-1]));
			dp2.push_back(max((i >= 2 ? dp2[i - 2] : 0) + nums[i], dp2[i-1]));
		}
		
		return max(dp1[len-2], dp2[len-1]);
    }
};

/*
[]
[2]
[23,2]
[23,32,43,12,43,32,1,1,2,13,12,32,3,23]
*/

class Solution {
public:
    int maxSubArray(vector<int>& nums) {
        vector<int> dp;
		int len = nums.size(), maxVal = 0;
		if (len > 0)
		{
			maxVal = nums[0];
			dp.push_back(nums[0]);
			for (int i=1; i<len; i++)
			{
				int tpMax = max(0, dp[i-1]) + nums[i];
				dp.push_back(tpMax);
				if (tpMax > maxVal)
				{
					maxVal = tpMax;
				}
			}
		}
		
		return maxVal;
    }
};

/* divide and conquer */
class Solution {
public:
    int maxSubArray(vector<int>& nums) {
		return maxSub(nums, 0, nums.size()-1);
    }
private:
	int maxSub(vector<int>& nums, int start, int end)
	{
		if (start > end)
		{
			return INT_MIN;
		}
		else if (start == end)
		{
			return nums[start];
		}
		
		int mid = (start + end) >> 1;
		int leftV = maxSub(nums, start, mid - 1);
		int rightV = maxSub(nums, mid + 1, end);
		int midV = nums[mid], tp=midV;
		for (int i=mid-1; i>=start; i--)
		{
			tp = nums[i] + tp;
			if(tp > midV)
			{
				midV = tp;
			}
		}
		
		tp = midV;
		for (int i=mid+1; i<=end; i++)
		{
			tp = nums[i] + tp;
			if(tp > midV)
			{
				midV = tp;
			}
		}
		
		return max(midV, max(leftV, rightV));
	}
};

/*
test cases:
[]
[1]
[-123]
[109,-1]
[323,-23,32,-23,32,-32,4,-3]
[-1, -2, -3]
*/
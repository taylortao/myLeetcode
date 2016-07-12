class Solution {
public:
    int threeSumClosest(vector<int>& nums, int target) {
        int result = INT_MAX, len = nums.size(), min = INT_MAX;
		// sort may change the order of vector nums
		sort(nums.begin(), nums.end());
		for (int i=0; i<len; )
		{
			int num = nums[i], st = i+1, end = len-1;
			while (st < end)
			{
				int sum = num + nums[st] + nums[end];
				if (sum == target)
				{
					return target;
				}
				else
				{
					int val = target - sum, absVal = abs(val);
					if (absVal < min)
					{
						min = absVal;
						result = sum;
					}
					
					if (val > 0)
					{
						st ++;
					}
					else
					{
						end --;
					}
				}
			}
			
			while (nums[i] == num && i<len)
			{
				i ++;
			}
		}
		
		return result;
    }
};

/*
test cases:
[] [1 2] 
[1 2 9]
[-10 -20 -23] 100

*/

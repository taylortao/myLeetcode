class Solution {
public:
    vector<vector<int>> fourSum(vector<int>& nums, int target) {
        // sort may change the order of nums
		sort(nums.begin(), nums.end());
		vector<vector<int>> result;
		int len = nums.size();
		for (int i=0; i<len-1; )
		{
			int num1 = nums[i];
			for (int j=i+1; j<len; )
			{
				int num2 = nums[j], st = j+1, end = len-1;
				while (st < end)
				{
					int sum = num1 + num2 + nums[st] + nums[end];
					if (sum == target)
					{
						vector<int> tv;
						int num3 = nums[st], num4 = nums[end];
						tv.push_back(num1);
						tv.push_back(num2);
						tv.push_back(num3);
						tv.push_back(num4);
						result.push_back(tv);
						while (nums[st] == num3 && st < end)
						{
							st ++;
						}
						
						while (nums[end] == num4 && st < end)
						{
							end --;
						}
					}
					else if (sum < target)
					{
						st ++;
					}
					else 
					{
						end --;
					}
				}
				
				while (num2 == nums[j] && j<len)
				{
					j ++;
				}
			}
			
			while (num1 == nums[i] && i<len-1)
			{
				i ++;
			}
		}
		
		return result;
    }
};

/*
test cases:
[] [1, 3]
[1, 2, 3, 8]  -10
[0, 0, 0, 0, 0, 0, 0] 0
[-3, -2, -1, 0, 0, 0, 0, 1, 2, 3] 0

*/
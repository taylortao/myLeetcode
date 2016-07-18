class Solution {
public:
    int findMin(vector<int>& nums) {
        int n = nums.size();
		int s = 0, e = n - 1;
		while (s < e)
		{
			int mid = s + ((e - s) >> 1);
			if (nums[mid] == nums[e])
			{
				if (nums[e-1] <= nums[e])
				{
					e--;
				}
				else
				{
					s = e;
				}
			}
			else if (nums[mid] >= nums[s] && nums[mid] > nums[e])
			{
				s = mid + 1;
			}
			else
			{
				e = mid;
			}
		}
		
		return nums[s];
    }
};
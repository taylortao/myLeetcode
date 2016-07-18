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


/*
Would this affect the run-time complexity? How and why?

yes, in worst case: it would be O(n) instead of O(logn)

worst case it: [2,2,2,2,2,2,2,2,2]

*/
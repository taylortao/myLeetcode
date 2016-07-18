class Solution {
public:
    int searchInsert(vector<int>& nums, int target) {
        int n = nums.size(), s = 0, e = n - 1;
		while (s < e)
		{
			int mid = s + ((e - s) >> 1);
			if (nums[mid] == target)
			{
				return mid;
			}
			else if (target > nums[mid])
			{
				s = mid + 1;
			}
			else
			{
				e = mid - 1;
			}
		}
		
		return (s < n && nums[s] < target) ? s + 1 : s;
    }
};

/*
[] 1
[1] 0
[1] 8
[1,2,3,4,5,6] 0
[1,2,3,4,5,6] 7
[1,2,3,5,6] 4
*/
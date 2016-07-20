class Solution {
public:
    vector<int> searchRange(vector<int>& nums, int target) {
        int s = 0, e = nums.size() - 1;
		vector<int> result;
		while (s < e)
		{
			if (nums[s] == target)
			{
				break;
			}
			
			int mid = s + ((e - s) >> 1);
			if (nums[mid] < target)
			{
				s = mid + 1;
			}
			else if(nums[mid] > target)
			{
				e = mid - 1;
			}
			else
			{
				e = mid;
			}
		}
		
		if (nums.empty() || nums[s] != target)
		{
			result.push_back(-1);
			result.push_back(-1);
			return result;
		}
		
		result.push_back(s);
		e = nums.size() - 1;
		while (s < e)
		{
			if (nums[e] == target)
			{
				break;
			}
			
			int mid = s + ((e - s - 1) >> 1) + 1;
			if (nums[mid] > target)
			{
				e = mid - 1;
			}
			else if (nums[mid] < target)
			{
				s = mid + 1;
			}
			else
			{
				s = mid;
			}
		}
		
		result.push_back(e);
		return result;
    }
};

/**
test cases:
[] 0
[1] 1
[1] 92
[1,2,4,4,4,4,4,4,5] 1, 4, 5, 3

**/
class Solution {
public:
    bool search(vector<int>& nums, int target) {
        int n = nums.size();
		int s = 0, e = n - 1;
		while(s<e)
		{
			int mid = s + ((e-s)>>1);
			if (nums[mid] == nums[e])
			{
				if (nums[e-1] <= nums[e])
				{
					e --;
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
		
		e = s + n - 1;
		while (s <= e)
		{
			int mid = s + ((e-s)>>1);
			int realIndex = mid % n;
			if (nums[realIndex] == target)
			{
				return true;
			}
			else if (nums[realIndex] < target)
			{
				s = mid + 1;
			}
			else 
			{
				e = mid - 1;
			}
		}
		
		return false;
    }
};

/*
[2,2,2,0,2,2]
0

[1,3,5]
5

[1,2,2,2,0,1,1]
0

[1,1,1,1,3]
3
*/
class Solution {
public:
    int search(vector<int>& nums, int target) {
        int n = nums.size();
		int s = 0, e = n - 1;
		while(s<e)
		{
			int mid = s + ((e-s)>>1);
			if (nums[mid] >= nums[s] && nums[mid] >= nums[e])
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
				return realIndex;
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
		
		return -1;
    }
};

/*
[] 2
[1] 1
[9] 1
[7,8,9,10,1,2,3,4,5,6] 8
[7,8,9,10,1,2,3,4,5,6] 3
[7,8,9,10,1,2,3,4,5,6] 11
[1,1,1,1,1,1,1] 1
[1,1,1,1,1,1,1] 3
[1,3,5] 5
*/
class Solution {
public:
    int findKthLargest(vector<int>& nums, int k) {
        int s = 0, e = nums.size() - 1;
		k--;
		while (s <= e)
		{
			swap(nums[s], nums[e]);
			int index = s;
			for (int i=s; i<e; i++)
			{
				if (nums[i] > nums[e])
				{
					if (i != index)
					{
						swap(nums[i], nums[index]);
					}
					
					index ++;
				}
			}
			
			swap(nums[index], nums[e]);
			if (index == k)
			{
				return nums[k];
			}
			else if (index < k)
			{
				s = index + 1;
			}
			else
			{
				e = index - 1;
			}
		}
		
		return -1;
    }
};

/**
test cases:
[] 
2
[2] 
3
[1]
1
[2,4,21,45,65,3,65,6,43,43] 
3
**/
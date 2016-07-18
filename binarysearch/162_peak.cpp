class Solution {
public:
    int findPeakElement(vector<int>& nums) {
        int s = 0, e = nums.size() - 1;
		while (s < e)
		{
			int mid = s + ((e - s) >> 1);
			if (nums[mid] < nums[mid + 1])
			{
				s = mid + 1;
			}
			else
			{
				e = mid;
			}
		}
		
		return s;
    }
};

/**  a smarter O(n) method **/
class Solution {
public:
    int findPeakElement(vector<int>& nums) {
        int n = nums.size();
		for (int i=0; i < n - 1; i++)
		{
			if (nums[i] > nums[i+1])
			{
				return i;
			}
		}
		
		return n-1;
    }
};
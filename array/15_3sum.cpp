class Solution {
public:
    vector<vector<int>> threeSum(vector<int>& nums) {
        // sort may infect the order of vector
		vector<vector<int>> result;
		sort(nums.begin(), nums.end());
		int len = nums.size();
		for (int i=0; i<len; )
		{
			int num = nums[i], st = i+1, end = len-1, anum = 0 - num;
			while (st < end)
			{
				if (nums[st] + nums[end] == anum)
				{
					vector<int> tpv;
					int v1 = nums[st], v2 = nums[end];
					tpv.push_back(num);
					tpv.push_back(v1);
					tpv.push_back(v2);
					result.push_back(tpv);
					while (nums[st] == v1 && st < end)
					{
						st ++;
					}
					
					while (nums[end] == v2 && st < end)
					{
						end --;
					}
				}
				else if (nums[st] + nums[end] > anum)
				{
					end --;
				}
				else
				{
					st ++;
				}
			}
			
			while(nums[i] == num && i<len)
			{
				i ++;
			}
		}
		
		return result;
    }
};


/*
test cases:
invalid input: [] [1] [1 2]
solution: [-1 -2 -3 0 0 0 1 2 3], [-9 -9 3 6]
no solution: [1 2 3]
*/
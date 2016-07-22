class Solution {
public:
    int maximumGap(vector<int>& nums) {
        vector<vector<int>> radixVector;
		vector<int> allNums(nums);
		for (int i=0; i<16; i++)
		{
			vector<int> radix;
			radixVector.push_back(radix);
		}
		
		int base = 15, digit = 0, len = nums.size();
		if (len < 2)
		{
			return 0;
		}
		
		for (int i=0; i<8; i++)
		{
			bool allZero = true;
			for (int j=0; j<len; j++)
			{
				int radixNum = (allNums[j] >> digit) & base;
				radixVector[radixNum].push_back(allNums[j]);
				if (allZero && radixNum > 0)
				{
					allZero = false;
				}
			}
			
			if (allZero)
			{
				break;
			}
			
			allNums.clear();
			for (int j=0; j<16; j++)
			{
				int radLen = radixVector[j].size();
				for (int k=0; k<radLen; k++)
				{
					allNums.push_back(radixVector[j][k]);
				}
				
				radixVector[j].clear();
			}
			
			digit += 4;
		}
		
		int maxGap = 0;
		for (int i=1; i<len; i++)
		{
			int gap = allNums[i] - allNums[i-1];
			if (gap > maxGap)
			{
				maxGap = gap;
			}
		}
		
		return maxGap;
    }
};

/**
use 2^4 = 16, and time complex is O(16n) ~ O(n)

test cases:
[]
[1]
[1,9,5,222,333,888]

**/
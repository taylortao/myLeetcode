class Solution {
public:
    int jump(vector<int>& nums) {
        int len = nums.size();
        if (len <= 0)
        {
            return 0;
        }
        
        int step = 0, maxDistance = 0, index = 0;
        while (index < len)
        {
            if (maxDistance >= len - 1)
            {
                return step;
            }
            
            int tmpMaxDist = 0;
            for (int i=index; i<=maxDistance; i++)
            {
                tmpMaxDist = max(tmpMaxDist, i+nums[i]);
            }
            
            step ++;
            index = maxDistance + 1;
            maxDistance = tmpMaxDist;
        }
        
        return -1;
    }
};

/**
test cases:
[]
[2]
[1,4,6,3,8,3,1,1,1,1,3,4,5]
**/
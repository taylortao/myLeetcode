class Solution {
public:
    bool canJump(vector<int>& nums) {
        int maxDistance = 0, len = nums.size();
        for (int i=0; i<len; i++)
        {
            if (i <= maxDistance && i + nums[i] > maxDistance)
            {
                maxDistance = i + nums[i];
            }
        }
        
        return maxDistance >= len - 1;
    }
};
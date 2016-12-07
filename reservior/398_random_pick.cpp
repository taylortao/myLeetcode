class Solution {
public:
    Solution(vector<int> nums) {
        numsVec = nums;
        srand((unsigned)time(0));
    }
    
    int pick(int target) {
        int index = -1;
        int tc;
        for (int i = 0; i < numsVec.size(); i++) {
            if (numsVec[i] != target) {
                continue;
            }
            
            if (index < 0) {
                index = i;
                tc = 1;
            }
            else {
                tc ++;
                if (rand() % tc == 0) {
                    index = i;
                }
            }
        }
        
        return index;
    }
private:
    vector<int> numsVec;
};

/**
 * Your Solution object will be instantiated and called as such:
 * Solution obj = new Solution(nums);
 * int param_1 = obj.pick(target);
 */
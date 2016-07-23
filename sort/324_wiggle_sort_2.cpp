class Solution {
private:
    void partition(vector<int>& nums, int k) {
        int s = 0, e = nums.size() - 1;        
        while (s <= e)
        {
            swap(nums[s], nums[e]);
            int i=s, j=s;
            for (; i<e; i++)
            {
                if (nums[i] < nums[e])
                {
                    if (i != j)
                    {
                        swap(nums[i], nums[j]);
                    }
                    
                    j++;
                }
            }
            
            swap(nums[j], nums[e]);
            
            if (j == k)
            {
                return;
            }
            else if (j < k)
            {
                s = j+1;
            }
            else
            {
                e = j-1;
            }
        }
    }
    
public:
    void wiggleSort(vector<int>& nums) {
        int len = nums.size(), mid = len >> 1;
        partition(nums, mid);
        int s = 1, e = len - 1 - ((len+1) % 2), midval = nums[mid];
        while (s < e)
        {
            swap(nums[s], nums[e]);
            s += 2;
            e -= 2;
        }
        
        int si = 0;
        for (int i=0; i<len; i+=2)
        {
            if (nums[i] == midval)
            {
                if (si != i)
                {
                    swap(nums[i], nums[si]);
                }
                
                si += 2;
            }
        }
        
        si = 1;
        for (int i=1; i<len; i+=2)
        {
            if (nums[i] != midval)
            {
                if (si != i)
                {
                    swap(nums[i], nums[si]);
                }
                
                si += 2;
            }
        }
    }
};

/**
test cases:
[]
[1]
[1,8]
[32,43,56,3243,5,32,32,45,65,433,7,87,4,7,43,7]
[4,5,5,6]
**/
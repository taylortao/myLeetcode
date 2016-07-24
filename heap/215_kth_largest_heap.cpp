class Solution {
public:
    int findKthLargest(vector<int>& nums, int k) {
        vector<int> heap;
		int len = nums.size(), halfK = k >> 1;
		if (k > len)
		{
			return -1;
		}
		
		for (int i=0; i<k; i++)
		{
			heap.push_back(nums[i]);
			int son = i, parent = son;
			while (son > 0)
			{
				parent = (son - 1) >> 1;
				if (heap[son] < heap[parent])
				{
					swap(heap[son], heap[parent]);
					son = parent;
				}
				else
				{
					break;
				}
			}
		}
		
		for (int i=k; i<len; i++)
		{
			if (nums[i] > heap[0])
			{
				heap[0] = nums[i];
				int p = 0, s;
				while (p < halfK)
				{
					s = (p << 1) + 1;
					if (s + 1 < k && heap[s+1] < heap[s])
					{
						s ++;
					}
					
					if (heap[p] > heap[s])
					{
						swap(heap[p], heap[s]);
						p = s;
					}
					else
					{
						break;
					}
				}
			}
		}
		
		return heap[0];
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
[5,2,4,1,3,6,0]
4
**/
class Solution {
private:
	void siftUp(vector<pair<int, int>>& heap)
	{
		int crtIndex = heap.size() - 1;
		while (crtIndex > 0)
		{
			int parent = (crtIndex - 1) >> 1;
			if (heap[parent].second > heap[crtIndex].second)
			{
				swap(heap[parent], heap[crtIndex]);
			}
			else
			{
				break;
			}
			
			crtIndex = parent;
		}
	}
	
	void siftDown(vector<pair<int, int>>& heap, int k)
	{
		int crtIndex = 0, halfK = k >> 1;
		while (crtIndex < halfK)
		{
			int son = (crtIndex << 1) + 1;
			if (son + 1 < k && heap[son+1].second < heap[son].second)
			{
				son ++;
			}
			
			if (heap[son].second < heap[crtIndex].second)
			{
				swap(heap[son], heap[crtIndex]);
			}
			else
			{
				break;
			}
			
			crtIndex = son;
		}
	}
	
public:
    vector<int> topKFrequent(vector<int>& nums, int k) {
		typedef pair<int, int> Pair;
		typedef map<int, int> Map;
		Map map;
		Map::iterator it;
		vector<Pair> heap;
		vector<int> result;
		int len = nums.size();
		for (int i=0; i<len; i++)
		{
			it = map.find(nums[i]);
			if (it == map.end())
			{
				map.insert(make_pair(nums[i], 1));
			}
			else
			{
				it->second = it->second + 1;
			}
		}
		
		for (it = map.begin(); it != map.end(); it++)
		{
			Pair pair = make_pair(it->first, it->second);
			if (heap.size() < k)
			{
				heap.push_back(pair);
				siftUp(heap);
			}
			else if (pair.second > heap[0].second)
			{
				heap[0] = pair;
				siftDown(heap, k);
			}
		}
		
		int heapSize = heap.size();
		while (heapSize --)
		{
			swap(heap[0], heap[heapSize]);
			siftDown(heap, heapSize);
		}
		
		heapSize = heap.size();
		for (int i=0; i<heapSize; i++)
		{
			result.push_back(heap[i].first);
		}
		
		return result;
    }
};


/**
test cases:
[]
2
[1]
1
[1,1,1,2,2,3]
9
[2,43,2,32,34,23,3,3,43,43,23,32,2,32,23,3,23,323,23,3,2,32,3,32,33,2,32,323,23]
3
**/


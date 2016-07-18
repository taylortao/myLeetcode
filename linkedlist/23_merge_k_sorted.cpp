/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */
 
/** implement a priority queue by myself using heap data structure **/

class PriorityHeap {
private:
	vector<ListNode*> heap;

public:
	void AddIntoheap(ListNode* element) {
		heap.push_back(element);
		int elementIndex = heap.size() - 1;		
		while (elementIndex > 0)
		{
			int parent = (elementIndex - 1) >> 1;
			if (heap[elementIndex]->val < heap[parent]->val)
			{
				swap(heap[elementIndex], heap[parent]);
			}
			
			elementIndex = parent;
		}
	}
	
	ListNode* GetTopAndPop() {
		int index = 0, childIndex = 1, heapLen = heap.size();
		ListNode* top = heap[0];
		heap[0] = heap[heapLen - 1];
		heap.pop_back();
		heapLen --;
		while (childIndex < heapLen)
		{
			if (childIndex + 1 < heapLen && heap[childIndex+1]->val < heap[childIndex]->val)
			{
				childIndex ++;
			}
			
			if (heap[childIndex]->val > heap[index]->val)
			{
				break;
			}
			
			swap(heap[childIndex], heap[index]);
			index = childIndex;
			childIndex = index * 2 + 1;
		}
		
		return top;
		
	}
	
	bool IsEmpty() {
		return heap.empty();
	}
};

class Solution {
public:
    ListNode* mergeKLists(vector<ListNode*>& lists) {
        PriorityHeap heap;
		for (int i=0; i<lists.size(); i++)
		{
			if (lists[i] != NULL)
			{
				heap.AddIntoheap(lists[i]);
			}
		}
		
		ListNode* head = NULL, **pHead = &head;
		while (!heap.IsEmpty())
		{
			ListNode* top = heap.GetTopAndPop();
			if (top->next != NULL)
			{
				heap.AddIntoheap(top->next);
			}
			
			*pHead = top;
			pHead = &(top->next);
		}
		
		return head;	
    }
};

/** use STL priority queue **/

class Solution {
public:
	bool operator()(ListNode* a, ListNode* b) {
		return a->val > b->val;
	}
	
    ListNode* mergeKLists(vector<ListNode*>& lists) {
        priority_queue<ListNode*, vector<ListNode*>, Solution> q;
		for (int i=0; i<lists.size(); i++)
		{
			if (lists[i] != NULL)
			{
				q.push(lists[i]);
			}
		}
		
		ListNode* head, ** pHead = &head;
		while (!q.empty())
		{
			ListNode* top = q.top();
			q.pop();
			if (top->next != NULL)
			{
				q.push(top->next);
			}
			
			*pHead = top;
			pHead = &top->next;
		}
		
		return head;
    }
};

/*
test cases:
[]
[[1]]
[[],[1,4,8]]
[[],[1,5,9],[3,7,10],[2,4,8]]
*/
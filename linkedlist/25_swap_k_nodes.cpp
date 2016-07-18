/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */
class Solution {
public:
    ListNode* reverseKGroup(ListNode* head, int k) {
        ListNode first(0);
		first.next = head;
		stack<ListNode*> liststack;
		ListNode* p0 = &first, * p1, *p2, *pk;
		while (true)
		{
			p1 = p0->next;
			for (int i=0; i<k && p1!=NULL; i++)
			{
				liststack.push(p1);
				p1 = p1->next;
			}
			
			if (p1 == NULL && liststack.size() < k)
			{
				break;
			}
			
			p2 = liststack.top();
			liststack.pop();
			p1 = p2;
			pk = p2->next; 
			while (!liststack.empty())
			{
				p1->next = liststack.top();
				liststack.pop();
				p1 = p1->next;
			}
			
			p0->next = p2;
			p1->next = pk;
			p0 = p1;
		}
		
		return first.next;
    }
};


/*
test cases:
[]
5

[1,2,3,4,5,6,7,8]
1, 4, 7, 8, 9
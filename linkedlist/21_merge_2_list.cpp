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
    ListNode* mergeTwoLists(ListNode* l1, ListNode* l2) {
		if (l1 == NULL)
		{
			return l2;
		}
		else if (l2 == NULL)
		{
			return l1;
		}
		
        ListNode* head = NULL, *p1 = l1, *p2 = l2, *th;
		if (p1->val < p2->val)
		{
			head = p1;
			p1 = p1->next;
		}
		else
		{
			head = p2;
			p2 = p2->next;
		}
		
		th = head;
		while (p1 != NULL && p2 != NULL)
		{
			if (p1->val < p2->val)
			{
				th->next = p1;
				p1 = p1->next;
			}
			else
			{
				th->next = p2;
				p2 = p2->next;
			}
			
			th = th->next;
		}
		
		while (p1 != NULL)
		{
			th->next = p1;
			p1 = p1->next;
			th = th->next;
		}
		
		while (p2 != NULL)
		{
			th->next = p2;
			p2 = p2->next;
			th = th->next;
		}
		
		th->next = NULL;
		return head;
    }
};


/*
test cases:
[][]
[1,2,3,4][]
[][1,2]
[1,2,5,6][2,4,7,9]
*/
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
    ListNode* insertionSortList(ListNode* head) {
		if (head == NULL)
		{
			return NULL;
		}
		
        ListNode first(0);
		first.next = head;
		ListNode *p1 = head->next, *p2, *p3;
		head->next = NULL;
		while (p1 != NULL)
		{
			p2 = &first;
			while (p2->next != NULL && p1->val > p2->next->val)
			{
				p2 = p2->next;
			}
			
			p3 = p1->next;
			p1->next = p2->next;
			p2->next = p1;
			p1 = p3;
		}
		
		return first.next;
    }
};

/**
test cases:
[]
[1]
[1,6]
[8,1]
[32,43,5,32,56,43,45,32,3,5,6,7,493]
**/
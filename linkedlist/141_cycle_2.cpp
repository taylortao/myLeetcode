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
    ListNode *detectCycle(ListNode *head) {
        if (head == NULL)
		{
			return NULL;
		}
		
		ListNode *p1=head, *p2=head;
		do
		{
			if (p2->next == NULL || p2->next->next == NULL)
			{
				return NULL;
			}
			
			p2 = p2->next->next;
			p1 = p1->next;
		}
		while(p1 != p2);
		
		p1=head;
		while (p1 != p2)
		{
			p1 = p1->next;
			p2 = p2->next;
		}
		
		return p1;
    }
};
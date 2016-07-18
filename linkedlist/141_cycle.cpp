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
    bool hasCycle(ListNode *head) {
		if (head == NULL)
		{
			return false;
		}
		
        ListNode *p1=head, *p2=head;
		do
		{
			if (p2->next == NULL || p2->next->next == NULL)
			{
				return false;
			}
			
			p2 = p2->next->next;
			p1 = p1->next;
		}
		while(p1 != p2);
		
		return true;
    }
};
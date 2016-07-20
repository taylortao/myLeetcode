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
    ListNode* deleteDuplicates(ListNode* head) {
		if (head == NULL)
		{
			return NULL;
		}
	
        ListNode first(0);
		first.next = head;
		ListNode *p0 = &first, *p1 = head, *p2 = head->next;
		while (p2 != NULL)
		{
			if (p2->val != p1->val)
			{
				if (p2 == p1->next)
				{
					p0->next = p1;
					p0 = p1;
				}
				
				p1 = p2;
			}
			
			p2 = p2->next;
		}
		
		p0->next = p1->next == NULL ? p1 : NULL;
		return first.next;
    }
};

/**
test cases:
[]
[1]
[1,2]
[1,1]
[1,2,3,4,5]
[1,1,1,1,1,3,5,7,7,7,7,7,8,9,10,11,12,12,12,12]
[1,1,1,1,1,1]
[1,1,2,2,3,4,5,5,6,6,7,8,9,9,9,9]
**/
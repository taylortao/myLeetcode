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
    ListNode* sortList(ListNode* head) {
        int step = 1, len = 0;
		ListNode first(0);
		ListNode *origin = head, *dest, *p1, *p2, *p3;
		while (origin != NULL)
		{
			origin = origin->next;
			len ++;
		}
		
		origin = head;
		while(step < len)
		{
			p1 = p2 = p3 = origin;
			dest = &first;
			while (p3 != NULL)
			{
				for (int i=0; i<step && p2!=NULL; i++)
				{
					p2 = p2->next;
				}
				
				p3 = p2;
				for (int i=0; i<step && p3!=NULL; i++)
				{
					p3 = p3->next;
				}
				
				ListNode *tp1 = p1, *tp2 = p2;
				while (tp1 != p2 && tp2 != p3)
				{
					if (tp1->val <= tp2->val)
					{
						dest->next = tp1;
						tp1 = tp1->next;
					}
					else
					{
						dest->next = tp2;
						tp2 = tp2->next;
					}
					
					dest = dest->next;
				}
				
				while (tp1 != p2)
				{
					dest->next = tp1;
					tp1 = tp1->next;
					dest = dest->next;
				}
				
				while (tp2 != p3)
				{
					dest->next = tp2;
					tp2 = tp2->next;
					dest = dest->next;
				}
				
				p1 = p2 = p3;
			}
			
			step <<= 1;
			dest->next = NULL;
			origin = first.next;
		}
		
		return origin;
    }
};

/**
test cases:
[]
[6]
[6,1]
[18,7,4,7,3]

**/
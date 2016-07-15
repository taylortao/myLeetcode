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
    ListNode* removeNthFromEnd(ListNode* head, int n) {
		if (head == NULL || n <= 0)
		{
			return NULL;
		}
		
        ListNode *first=head, *second=head;
		while (n--)
		{
			first = first->next;
			if (first == NULL)
			{
				return second->next;
			}
		}
		
		while (first->next != NULL)
		{
			first = first->next;
			second = second->next;
		}
		
		second->next = second->next->next;
		return head;
    }
};

/*
[1,2,3] 0
[1,2,3] 5
[1,2,3] 3
[1,2,3] 1
*/
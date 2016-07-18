/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */
 
/** add a very first head node is useful, makes logic more simple **/
class Solution {
public:
    ListNode* swapPairs(ListNode* head) {
        ListNode first(0);
		first.next = head;
		ListNode* p0 = &first, * p1 = p0->next, * p2;
		while (p1 != NULL && p1->next != NULL)
		{
			p2 = p1->next;
			p1->next = p2->next;
			p0->next = p2;
			p2->next = p1;
			p0 = p1;
			p1 = p0->next;
		}
		
		return first.next;
    }
};


/*
test cases:
[]
[1]
[1,7]
[1,2,3,4]
[1,2,3,4,5]
*/
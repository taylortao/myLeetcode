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
    /** @param head The linked list's head.
        Note that the head is guaranteed to be not null, so it contains at least one node. */
    Solution(ListNode* head) {
        listHead = head;
        srand((unsigned)time(0));
    }
    
    /** Returns a random node's value. */
    int getRandom() {
        // the head is guaranteed to be not null, so it contains at least one node.
        int val = listHead->val;
        int cnt = 1;
        ListNode* pNode = listHead->next;
        while (pNode != NULL) {
            cnt ++;
            if (rand() % cnt == 0) {
                val = pNode->val;
            }
            
            pNode = pNode->next;
        }
        
        return val;
    }
private:
    ListNode* listHead;
};

/**
 * Your Solution object will be instantiated and called as such:
 * Solution obj = new Solution(head);
 * int param_1 = obj.getRandom();
 */
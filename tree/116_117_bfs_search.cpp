/**
 * Definition for binary tree with next pointer.
 * struct TreeLinkNode {
 *  int val;
 *  TreeLinkNode *left, *right, *next;
 *  TreeLinkNode(int x) : val(x), left(NULL), right(NULL), next(NULL) {}
 * };
 */
class Solution {
public:
    void connect(TreeLinkNode *root) {
        if (root == NULL)
        {
            return;
        }
        
        queue<TreeLinkNode*> q;
		q.push(root);
		while (!q.empty())
		{
			TreeLinkNode* h = q.front(), *ph = h;
			q.pop();
			while (!q.empty())
			{
				ph->next = q.front();
				ph = ph->next;
				q.pop();
			}
			
			ph->next = NULL;
			ph = h;
			while (ph != NULL)
			{
				if (ph->left != NULL)
				{
					q.push(ph->left);
				}
				
				if (ph->right != NULL)
				{
					q.push(ph->right);
				}
				
				ph = ph->next;
			}
		}
    }
};
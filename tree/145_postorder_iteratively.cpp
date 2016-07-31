/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
class Solution {
public:
    vector<int> postorderTraversal(TreeNode* root) {
        vector<int> result;
		stack<TreeNode*> strvStk;
		stack<bool> visitedStk;
		TreeNode *nodeP = root;
		while (nodeP != NULL || !strvStk.empty())
		{
			while (nodeP != NULL)
			{
				strvStk.push(nodeP);
				visitedStk.push(false);
				nodeP = nodeP->left;
			}
			
			nodeP = strvStk.top();
			bool visited = visitedStk.top();
			if (!visited)
			{
				visitedStk.pop();
				visitedStk.push(true);
				nodeP = nodeP->right;
			}
			else
			{
				result.push_back(nodeP->val);
				visitedStk.pop();
				strvStk.pop();
				nodeP = NULL;
			}			
		}
		
		return result;
    }
};

/**
test cases:
[]
[1]
[1,2,null,3]
[1,null,2,3]
[1,null,2,null,3]
[1,2,3,null,null,4,5,null,null,null,6,7,null,8,9,null,null,10,11,12]
**/
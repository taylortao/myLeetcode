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
    vector<int> inorderTraversal(TreeNode* root) {
        vector<int> result;
		stack<TreeNode*> travStk;
		TreeNode* nodeP = root;
		while (nodeP != NULL || !travStk.empty())
		{
			while (nodeP != NULL)
			{
				travStk.push(nodeP);
				nodeP = nodeP->left;
			}
			
			nodeP = travStk.top();
			travStk.pop();
			result.push_back(nodeP->val);
			nodeP = nodeP->right;
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
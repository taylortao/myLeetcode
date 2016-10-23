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
private:
	bool dfs(TreeNode* node, int sum) {
		if (node->left == NULL && node->right == NULL) {
			if (node->val == sum) {
				return true;
			}
		}
		
		if (node->left != NULL) {
			if (dfs(node->left, sum - node->val))
			{
				return true;
			}
		}
		
		if (node->right != NULL) {
			if (dfs(node->right, sum - node->val))
			{
				return true;
			}
		}
		
		return false;
	}

public:
    bool hasPathSum(TreeNode* root, int sum) {
        if (root == NULL) {
			return false;
		}
		
		return dfs(root, sum);
    }
};


/**
[]
0
[]
11
[5,4,8,11,null,13,4,7,2,null,null,5,1]
22
**/
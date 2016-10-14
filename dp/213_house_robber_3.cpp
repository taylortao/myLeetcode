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
    int rob(TreeNode* root) {
		if (root == NULL)
		{
			return 0;
		}
		
        pair<int, int> ans = robMaxValue(root);
		return max(ans.first, ans.second);
    }

private:
	pair<int, int> robMaxValue(TreeNode* root) {
		// first : rob root, second not rob root
		int rootMax = 0, noRootMax = 0;
		if (root->left == NULL && root->right == NULL)
		{
			return make_pair(root->val, 0);
		}
		
		if (root->left != NULL) 
		{
			pair<int, int> leftVal = robMaxValue(root->left);
			rootMax = leftVal.second;
			noRootMax = leftVal.first;
		}
		
		if (root->right != NULL)
		{
			pair<int, int> rightVal = robMaxValue(root->right);
			rootMax += rightVal.second;
			noRootMax += rightVal.first;
		}
		
		rootMax = max(root->val + rootMax, noRootMax);
		return make_pair(rootMax, noRootMax);
	}
};

/*
[]
[1]
[3,2,3,null,3,null,1]
[1,null,8,null,7,null,6,null,9]
[3,1,null,1,null,19]
*/

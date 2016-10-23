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
	vector<vector<int>> result;
	vector<int> oneResult;
	void dfs(TreeNode* node, int sum) {
		if (node->left == NULL && node->right == NULL) {
			if (node->val == sum) {
				oneResult.push_back(node->val);
				vector<int> resultCpy(oneResult);
				result.push_back(resultCpy);
				oneResult.pop_back();
			}
		}
		
		if (node->left != NULL) {
			oneResult.push_back(node->val);
			dfs(node->left, sum - node->val);
			oneResult.pop_back();
		}
		
		if (node->right != NULL) {
			oneResult.push_back(node->val);
			dfs(node->right, sum - node->val);
			oneResult.pop_back();
		}
	}
	
public:
    vector<vector<int>> pathSum(TreeNode* root, int sum) {
        result.clear();
		oneResult.clear();
		if (root == NULL) {
			return result;
		}
		
		dfs(root, sum);
		return result;
    }
};
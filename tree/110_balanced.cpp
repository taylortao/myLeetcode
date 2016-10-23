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
	struct treeValue {
		bool isBalance;
		int height;
		treeValue(bool isb, int h) : isBalance(isb), height(h) {
		}
	};
	
	treeValue isBalancedSub(TreeNode* node) {
		if (node == NULL) {
			return treeValue(true, 0);
		}
		
		if (node->left == NULL && node->right == NULL) {
			return treeValue(true, 1);
		}
		
		treeValue left = isBalancedSub(node->left);
		if (!left.isBalance) {
			return treeValue(false, -1);
		}
		
		treeValue right = isBalancedSub(node->right);
		if (!right.isBalance) {
			return treeValue(false, -1);
		}
		
		if(abs(left.height - right.height) <= 1)
		{
			return treeValue(true, max(left.height, right.height) + 1);
		}
		else
		{
			return treeValue(false, -1);
		}
	}

public:
    bool isBalanced(TreeNode* root) {
        if (root == NULL) {
			return true;
		}
		
		return isBalancedSub(root).isBalance;
    }
};

/**
[]
[1,2,3]
[1,2,null, 3]
[1,2,null, null, 3, null]
**/
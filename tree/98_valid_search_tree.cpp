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
    bool isValidBST(TreeNode* root) {
        int currentVal = INT_MIN;
		bool isFirst = true;
		stack<TreeNode*> nodesStk;
		TreeNode* node = root;
		while (node != NULL || !nodesStk.empty())
		{
			while (node != NULL)
			{
				nodesStk.push(node);
				node = node->left;
			}
			
			int tpVal = nodesStk.top()->val;
			if (!isFirst && tpVal <= currentVal)
			{
				return false;
			}
			
			currentVal = tpVal;
			isFirst = false;
			node = nodesStk.top()->right;
			nodesStk.pop();
		}
		
		return true;
    }
};

/**
test cases:
[]
[2,1,3]
[8,5,10,3,6,9,12]
[1,1]
[-2147483648]
**/
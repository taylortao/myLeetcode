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
	TreeNode* buildTree(const vector<int>& preorder, int s1, int e1, const vector<int>& inorder, int s2, int e2)
	{
		if (s1 == e1 && s2 == e2 && preorder[s1] == inorder[s2])
		{
			TreeNode* treeNode = new TreeNode(preorder[s1]);
			return treeNode;
		}
		
		int rootNode = preorder[s1], indexInorder = s2;
		while (indexInorder <= e2)
		{
			if (inorder[indexInorder] == rootNode)
			{
				break;
			}
			
			indexInorder ++;
		}
		
		TreeNode* treeNode = new TreeNode(rootNode);
		if (s2 <= indexInorder - 1)
		{
			treeNode->left = buildTree(preorder, s1 + 1, s1 + indexInorder - s2, inorder, s2, indexInorder - 1);
		}
		
		if (indexInorder + 1 <= e2)
		{
			treeNode->right = buildTree(preorder, s1 + indexInorder - s2 + 1, e1, inorder, indexInorder + 1, e2);
		}
		
		return treeNode;
	}
	
public:
    TreeNode* buildTree(vector<int>& preorder, vector<int>& inorder) {
		int len1 = preorder.size(), len2 = inorder.size();
		if (len1 == 0 || len2 == 0 || len1 != len2)
		{
			return NULL;
		}
		
        return buildTree(preorder, 0, len1 - 1, inorder, 0, len1 - 1);
    }
};

/**
test cases:
[]
[]
[1,2,3]
[2,1,3]
[1,2,3]
[3,2,1]
[1,2,3]
[1,3,2]
[1,2,3]
[1,2,3]
[1,2,3,4,5,6,7,8,9,10,12,11]
[2,1,4,3,5,8,7,12,10,9,11,6]

**/
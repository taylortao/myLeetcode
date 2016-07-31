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
	TreeNode* buildTree(const vector<int>& inorder, int s1, int e1, const vector<int>& postorder, int s2, int e2)
	{
		if (s1 == e1 && s2 == e2 && inorder[s1] == postorder[s2])
		{
			TreeNode* treeNode = new TreeNode(inorder[s1]);
			return treeNode;
		}
		
		int rootNode = postorder[e2], indexInorder = s1;
		while (indexInorder <= e1)
		{
			if (inorder[indexInorder] == rootNode)
			{
				break;
			}
			
			indexInorder++;
		}
		
		TreeNode* treeNode = new TreeNode(rootNode);
		if (s1 <= indexInorder - 1)
		{
			treeNode->left = buildTree(inorder, s1, indexInorder - 1, postorder, s2, s2 + indexInorder - s1 - 1);
		}
		
		if (indexInorder + 1 <= e1)
		{
			treeNode->right = buildTree(inorder, indexInorder + 1, e1, postorder, s2 + indexInorder - s1, e2 - 1);
		}
		
		return treeNode;
	}
public:
    TreeNode* buildTree(vector<int>& inorder, vector<int>& postorder) {
        int len1 = inorder.size(), len2 = postorder.size();
		if (len1 == 0 || len2 == 0 || len1 != len2)
		{
			return NULL;
		}
		
        return buildTree(inorder, 0, len1 - 1, postorder, 0, len1 - 1);
    }
};

/**
test cases:
[]
[]
[2,1,3]
[2,3,1]
[3,2,1]
[3,2,1]
[1,3,2]
[3,2,1]
[1,2,3]
[3,2,1]
[2,1,4,3,5,8,7,12,10,9,11,6]
[2,4,8,12,10,11,9,7,6,5,3,1]
**/
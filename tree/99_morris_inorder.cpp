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
	TreeNode *firstWrong;
	TreeNode *secondWrong;
	TreeNode *currentNode;
	TreeNode *prevNode;
	void visit(TreeNode* node) {
		if (prevNode != NULL && firstWrong == NULL && node->val < prevNode->val)
		{
			firstWrong = prevNode;
		}
		
		if (prevNode != NULL && firstWrong != NULL && node->val < prevNode->val)
		{
			secondWrong = node;
		}
		
		prevNode = node;
	}
	
public:
    void recoverTree(TreeNode* root) {
        currentNode = root;
		while (currentNode != NULL)
		{
			TreeNode *predecessor = currentNode->left;
			if (predecessor == NULL)
			{
				visit(currentNode);
				currentNode = currentNode->right;		
			}
			else
			{
				while (predecessor->right != NULL && predecessor->right != currentNode)
				{
					predecessor = predecessor->right;
				}
				
				if (predecessor->right == NULL)
				{
					predecessor->right = currentNode;
					currentNode = currentNode->left;
				}
				else
				{
					predecessor->right = NULL;
					visit(currentNode);
					currentNode = currentNode->right;
				}
			}
		}
		
		if (firstWrong != NULL && secondWrong != NULL)
		{
			swap(firstWrong->val, secondWrong->val);
		}
    }
};

/**
test cases:
[0,1]
[8,12,10,3,6,9,5]
[8,5,3,10,6,9,12]
[8,5,10,12,6,9,3]
[8,6,10,3,5,9,12]
**/
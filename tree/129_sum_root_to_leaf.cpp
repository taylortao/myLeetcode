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
    int sumNumbers(TreeNode* root) {
        if (root == NULL) return 0;
        sumNumbers(root, 0);
        return sum;
    }

private:
    int sum;
    void sumNumbers(TreeNode* root, int crtSum) {
        int crtVal = crtSum * 10 + root->val;
        if (root->left == NULL && root->right == NULL) { // leaf node
            sum += crtVal;
            return;
        }
        if (root->left != NULL) {
            sumNumbers(root->left, crtVal);
        }
        if (root->right != NULL) {
            sumNumbers(root->right, crtVal);
        }
    }
};
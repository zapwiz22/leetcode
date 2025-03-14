/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left),
 * right(right) {}
 * };
 */
class Solution {
   private:
    // inorder function to carry the traversal using recursion and push the elements in the vector passed as reference
    void inOrder(TreeNode* root, vector<int>& ans) {
        if (root == NULL) {
            return;
        }
        if (root->left != NULL) {
            inOrder(root->left, ans);
        }
        ans.push_back(root->val);
        if (root->right != NULL) {
            inOrder(root->right, ans);
        }
    }

   public:
    vector<int> inorderTraversal(TreeNode* root) {
        // vector to be passed in the function call below
        vector<int> ans;
        inOrder(root, ans);
        return ans;
    }
};

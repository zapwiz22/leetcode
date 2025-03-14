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
    // function to push the preOrder traversal elements in the ans vector which has been passed as reference to reduce the space complexity
    void preOrder(TreeNode* root, vector<int>& ans) {
        if (root == NULL) {
            return;
        }
        ans.push_back(root->val);
        if (root->left != NULL) {
            preOrder(root->left, ans);
        }
        if (root->right != NULL) {
            preOrder(root->right, ans);
        }
    }

   public:
    vector<int> preorderTraversal(TreeNode* root) {
        vector<int> ans;
        // calling the function
        preOrder(root, ans);
        return ans;
    }
};

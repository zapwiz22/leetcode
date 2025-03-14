/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
 * };
 */
class Solution {
private:
    // function of postOrder to help to get the elements in the correct order of left right root in the vector which is then returned in the main function
    void postOrder (TreeNode* root,vector<int> &ans) {
        if (root==NULL) {
            return;
        }
        if (root->left != NULL) {
            postOrder(root->left,ans);
        }
        if (root->right!=NULL) {
            postOrder(root->right,ans);
        }
        ans.push_back(root->val);
    }
public:
    vector<int> postorderTraversal(TreeNode* root) {
        vector<int> ans;
        postOrder(root,ans);
        return ans;
    }
};

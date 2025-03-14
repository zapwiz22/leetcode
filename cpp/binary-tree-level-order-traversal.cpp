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
    // function for level order using a queue which stores the elements level wise and NULL as the separator of this level
    void levelOrderTraversal(TreeNode* root,vector<vector<int>> &ans) {
        if (!root) return;
        queue<TreeNode*> q;
        q.push(root);
        q.push(NULL);
        // vector to store a particular level
        vector<int> part;
        while (!q.empty()) {
            TreeNode* p = q.front();
            q.pop();
            if (p==NULL) {
                ans.push_back(part);
                // this vector is cleared when a level is finished 
                part.clear();
                if (!q.empty()) {
                    q.push(NULL);
                }
            }
            else {
                part.push_back(p->val);
                if (p->left) q.push(p->left);
                if (p->right) q.push(p->right);
            }
        }
    }
public:
    vector<vector<int>> levelOrder(TreeNode* root) {
        vector<vector<int>> ans;
        levelOrderTraversal(root,ans);
        return ans;
    }
};

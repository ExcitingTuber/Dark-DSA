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
public:
    // int getHeight(TreeNode* node) {
    //     if (node == nullptr) {
    //         return 0;
    //     }
    //     return 1 + max(getHeight(node->left), getHeight(node->right));
    // }

    vector<vector<int>> levelOrder(TreeNode* root) {
        vector<vector<int>> ans;
        queue<TreeNode*> q;
        if (!root)
            return ans;
        q.push(root);
        
        while (!q.empty()) {
            int n=q.size();
            vector<int>v;

            for(int i=0;i<n;i++){
                TreeNode* curr = q.front();
                q.pop();
                v.push_back(curr->val);
                if(curr->left) q.push(curr->left); 
                if(curr->right) q.push(curr->right);
            }
            ans.push_back(v);
        }
        return ans;
    }
};
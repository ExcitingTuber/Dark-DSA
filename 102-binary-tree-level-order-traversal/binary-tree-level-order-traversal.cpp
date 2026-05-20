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
    int getHeight(TreeNode* node) {
        // Base case: empty tree has height 0 (or -1 depending on definition)
        if (node == nullptr) {
            return 0;
        }

        // Recursive step: 1 + max height of subtrees
        return 1 + max(getHeight(node->left), getHeight(node->right));
    }

    vector<vector<int>> levelOrder(TreeNode* root) {
        int h = getHeight(root);
        // cout<<h;
        vector<vector<int>> ans(h);
        queue<TreeNode*> q;
        int i = 0, j = 1, k = 0;
        if (!root)
            return {};
        q.push(root);
        // if (root->left != NULL) {
        //     k++;
        // }
        // if (root->right != NULL) {
        //     k++;
        // }
        while (!q.empty()) {
            TreeNode* curr = q.front();
            q.pop();

            ans[i].push_back(curr->val);
            j--;
            

            if (curr->left) {
                q.push(curr->left);
                k++;
            }
            if (curr->right) {
                q.push(curr->right);
                k++;
            }
            if (j == 0) {
                i++;
                j = k;
                k = 0;
            }
        }
        return ans;
    }
};
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
    bool same(TreeNode* r, TreeNode* s) {
    
        if (r == NULL && s == NULL)
            return 1;
        if (r == NULL || s == NULL)
            return 0;
        return (r->val == s->val) && same(r->left, s->left) &&
               same(r->right, s->right);
    }

    bool isSubtree(TreeNode* r, TreeNode* s) {
        if(!r) return false;
        if(!s) return true;
        if (same(r, s)) return 1; 
        return isSubtree(r->left, s) || isSubtree(r->right, s);
    }
};
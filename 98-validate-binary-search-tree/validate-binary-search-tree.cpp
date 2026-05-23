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
public:
    bool check(TreeNode* root,long long l, long long h){
        if(!root) return true;
        if(root->val<=l || root->val>=h) return false;

        return check(root->left,l,root->val)&&check(root->right,root->val,h);
        // if((!root->right && root->val>root->left->val)||(!root->left && root->val<root->right->val))return 1;
        
        // if(!root->left&&!root->right && root->val>root->left->val && root->val<root->right->val) return 1;
        // return 0; 
    }
    bool isValidBST(TreeNode* root) {
        return check(root,LLONG_MIN,LLONG_MAX);
        
        // if(!root) return 1;
        // if(check(root)) return isValidBST(root->left) && isValidBST(root->right);
        // return 0; 
    }
};
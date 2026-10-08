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

    bool helper(TreeNode* root, long long minimum, long long maximum){
        if(root==nullptr) return true;
        if(root->val >= maximum || root->val <=minimum) return false;
        bool l=helper(root->left, minimum, root->val);
        bool r=helper(root->right, root->val, maximum);
        return l&&r;
    }

    bool isValidBST(TreeNode* root) {
        long long minimum = (long long)INT_MIN - 1;
        long long maximum = (long long)INT_MAX + 1;
        return helper(root,minimum,maximum);

    }
};
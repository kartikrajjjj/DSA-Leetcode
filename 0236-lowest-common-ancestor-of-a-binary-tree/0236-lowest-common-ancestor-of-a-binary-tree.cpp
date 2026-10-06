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

    TreeNode* helper(TreeNode* root, TreeNode* p, TreeNode* q){
        if(root==p || root==q || root==nullptr) return root;
        if(root->left == nullptr && root->right == nullptr) return nullptr;
        TreeNode* l= helper(root->left,p,q);
        TreeNode* r=helper(root->right,p,q);
        if(l!=nullptr && r==nullptr) return l;
        if(r!=nullptr && l==nullptr) return r;
        if(l!=nullptr && r!=nullptr) return root;
        return nullptr;

    }

    TreeNode* lowestCommonAncestor(TreeNode* root, TreeNode* p, TreeNode* q) {
        if(p==root || q==root || root==nullptr) return root;
        TreeNode* ans=helper(root,p,q);
        return ans;
    }
};
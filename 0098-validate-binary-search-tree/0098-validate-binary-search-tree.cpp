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

    bool helper(TreeNode* temp, long long minimum, long long maximum){
        if(temp==nullptr) return true;
        if(temp->val >= maximum || temp->val <= minimum) return false;
        bool l =helper(temp->left, minimum, temp->val);
        bool r= helper(temp->right, temp->val, maximum);
        return l && r;
    }

    bool isValidBST(TreeNode* root) {
        if(root==nullptr) return true;
        long long minimum=(long long)INT_MIN -1;
        long long maximum= (long long)INT_MAX +1;
        TreeNode* temp=root;
        return helper(temp, minimum, maximum);
    }
};
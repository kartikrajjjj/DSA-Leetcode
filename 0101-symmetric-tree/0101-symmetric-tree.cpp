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

    bool check(TreeNode* temp1, TreeNode* temp2){
        if(temp1==nullptr || temp2==nullptr) return temp1==temp2;
        if(temp1->val != temp2->val) return false;
        return check(temp1->left, temp2->right) && check(temp2->left, temp1->right);

    }

    bool isSymmetric(TreeNode* root) {
        if(root==nullptr) return true;
        return check(root->left, root->right);

    }
};
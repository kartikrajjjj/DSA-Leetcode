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

    void helper(TreeNode* root, int targetSum, vector<vector<int>> &ans, vector<int> &v){
        if(root==nullptr) return ;
        v.push_back(root->val);
        if(root->left ==nullptr && root->right ==nullptr && root->val==targetSum){
            ans.push_back(v);
        }
        helper(root->left, targetSum-root->val, ans, v);
        helper(root->right, targetSum-root->val, ans,v);
        v.pop_back();
    }

    vector<vector<int>> pathSum(TreeNode* root, int targetSum) {
        vector<vector<int>> ans;
        vector<int> v;
        helper(root,targetSum,ans,v);
        return ans;
    }
};
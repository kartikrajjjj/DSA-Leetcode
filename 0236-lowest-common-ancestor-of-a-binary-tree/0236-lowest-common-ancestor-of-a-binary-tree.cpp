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

    void helper(TreeNode* root, TreeNode* &p, TreeNode* &q,vector<TreeNode*> &v, vector<vector<TreeNode*>> &ans){
        if(root==nullptr) return;
        v.push_back(root);
        
        helper(root->left, p, q, v, ans);
        helper(root->right, p, q, v, ans);

        if(root==p || root==q){
            ans.push_back(v);
        }

        v.pop_back();


    } 

    TreeNode* lowestCommonAncestor(TreeNode* root, TreeNode* p, TreeNode* q) {
        if(root==p || root==q) return root;
        vector<vector<TreeNode*>> ans;
        vector<TreeNode*> v;
        TreeNode* answer=root;
        helper(root, p, q, v, ans);
        int i=0;
        int j=0;
        while(i<ans[0].size() && j< ans[1].size()){
            answer=ans[0][i];
            if(ans[0][i]==ans[1][j]){
                i++;
                j++;
            }
            else{
                answer=ans[0][i-1];
                break;
            }
        }
        return answer;
    }
};
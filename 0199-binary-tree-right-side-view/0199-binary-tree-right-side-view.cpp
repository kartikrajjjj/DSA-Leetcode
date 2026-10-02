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

    //My solution

    vector<int> rightSideView(TreeNode* root) {
        vector<int> ans;
        if(root==nullptr) return ans;
        ans.push_back(root->val);
        queue<TreeNode*> q;
        q.push(root);
        while(!q.empty()){
            int s=q.size();
            int element=INT_MIN;  //if negative number is present in val
            bool found=false;
            for(int i=1;i<=s;i++){
                TreeNode* temp=q.front();
                q.pop();
                if(temp->left != nullptr){
                    q.push(temp->left);
                    found=true;
                    element=temp->left->val;
                }
                if(temp->right != nullptr){
                    q.push(temp->right);
                    found=true;
                    element=temp->right->val;
                }
            }
            if(found) ans.push_back(element);
            
        }
        return ans;
    }

    
    //Striver solution
    // void helper(TreeNode* root, int level, vector<int> &ans){
    //     if(root==nullptr) return;

    //     if(ans.size()==level){
    //         ans.push_back(root->val);
    //     }


    //     helper(root->right, level+1, ans);
    //     helper(root->left, level+1, ans);

    // }

    // vector<int> rightSideView(TreeNode* root) {
    //     vector<int> ans;
    //     helper(root, 0, ans);
    //     return ans;
    // }

};
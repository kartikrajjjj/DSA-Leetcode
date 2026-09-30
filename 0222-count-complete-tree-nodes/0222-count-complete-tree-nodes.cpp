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
    int leftHeight(TreeNode* root){
        int count=1;
        if(root==nullptr) return 0;
        TreeNode* temp=root;
        while(temp->left!=nullptr){
            count++;
            temp=temp->left;
        }
        return count;
    }

    int rightHeight(TreeNode* root){
        int count=1;
        if(root==nullptr) return 0;
        TreeNode* temp=root;
        while(temp->right!=nullptr){
            count++;
            temp=temp->right;
        }
        return count;
    }

    int countNodes(TreeNode* root) {
        if(root==nullptr) return 0;

        int lh=leftHeight(root);
        int rh=rightHeight(root);

        if(lh != rh){
            return 1 + countNodes(root->left) + countNodes(root->right);
            
        }
        return pow(2,rh)-1;
        
        
    }
};
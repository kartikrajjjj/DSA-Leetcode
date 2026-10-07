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
    TreeNode* insertIntoBST(TreeNode* root, int val) {
        if(root==nullptr){
            TreeNode* newNode = new TreeNode(val);
            return newNode;
        }
        TreeNode* temp=root;
        TreeNode* prev=nullptr;
        while(temp!=nullptr){
            if(val > temp->val){
                prev=temp;
                temp=temp->right;
            }
            else if(val < temp->val){
                prev=temp;
                temp=temp->left;
            }
        }
        TreeNode* newNode=new TreeNode(val);
        if(val < prev->val){
            prev->left = newNode;
        }
        else prev->right =newNode;
        return root;
    }
};
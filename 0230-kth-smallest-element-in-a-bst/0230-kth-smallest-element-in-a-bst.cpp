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

    void entry(TreeNode* root, set<int> &st){
        if(root==nullptr) return;
        st.insert(root->val);
        entry(root->left, st);
        entry(root->right, st);
    }

    int kthSmallest(TreeNode* root, int k) {
        if(root == nullptr) return 0;
        set<int> st;
        entry(root, st);
        auto it=st.begin();
        advance(it, k-1);
        return *it;
        
    }
};
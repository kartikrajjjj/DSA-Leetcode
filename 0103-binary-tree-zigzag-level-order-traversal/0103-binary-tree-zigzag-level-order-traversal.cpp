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
    vector<vector<int>> zigzagLevelOrder(TreeNode* root) {
        vector<vector<int>> ans;
        if(root==nullptr) return ans;
        bool flag=true;
        queue<TreeNode* > q;
        q.push(root);
        while(!q.empty()){
            int s=q.size();
            vector<int> v(s);
            for(int i=0;i<s;i++){
                TreeNode* temp=q.front();
                q.pop();
                int index = flag? i: s-i-1;

                if(temp->left != nullptr){
                    q.push(temp->left);
                }
                if(temp->right != nullptr){
                    q.push(temp->right);
                }
                v[index]=temp->val;
            }
            flag=!flag;
            ans.push_back(v);
        }
        return ans;
    }
};
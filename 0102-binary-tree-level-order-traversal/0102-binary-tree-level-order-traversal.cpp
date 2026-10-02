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
    vector<vector<int>> levelOrder(TreeNode* root) {
        vector<vector<int>> answer;
        if(root==nullptr) return answer;
        queue<TreeNode* > q;
        q.push(root);

        while(!q.empty()){
            int n=q.size();
            vector<int> v;

            for(int i=1;i<=n;i++){
                TreeNode* temp=q.front();
                q.pop();
                if(temp->left != nullptr){
                    q.push(temp->left);
                }
                if(temp->right != nullptr){
                    q.push(temp->right);
                }
                v.push_back(temp->val);
            }
            answer.push_back(v);
        }
        return answer;
    }
};
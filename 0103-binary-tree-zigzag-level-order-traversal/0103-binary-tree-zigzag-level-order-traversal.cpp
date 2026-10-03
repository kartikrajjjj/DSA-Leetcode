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
        vector<vector<int>> answer;
        if(root==nullptr) return answer;
        queue<TreeNode* > q;
        q.push(root);
        bool leftToRight=true;
        while(!q.empty()){
            int s=q.size();
            vector<int> v(s);
            for(int i=0;i<s;i++){
                TreeNode* temp=q.front();
                q.pop();

                int index= (leftToRight) ? i : (s-1-i);
                v[index]=temp->val;

                if(temp->left != nullptr){
                    q.push(temp->left);
                }

                if(temp->right != nullptr){
                    q.push(temp->right);
                }

            }
            answer.push_back(v);
            if(leftToRight==true) leftToRight=false;
            else leftToRight = true;
        }
        return answer;
    }
};
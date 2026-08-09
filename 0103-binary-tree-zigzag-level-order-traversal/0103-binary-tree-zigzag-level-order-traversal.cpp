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
    void levelorder(TreeNode* root, vector<vector<int>>& result){
        if(root == NULL) return;

        queue<TreeNode*> q;
        q.push(root);

        int level = 0;

        while(!q.empty()){
            int size = q.size();
            result.push_back(vector<int>());

            for(int i=0; i<size; i++){
                TreeNode* curr = q.front();
                q.pop();

                result.back().push_back(curr->val);
                if(curr->left != NULL){
                    q.push(curr->left);
                }

                if(curr->right != NULL){
                    q.push(curr->right);
                }
            }
            level++;
            if(level % 2 == 0){
                reverse(result.back().begin(), result.back().end());
            }
        }
    }
    vector<vector<int>> zigzagLevelOrder(TreeNode* root) {
        vector<vector<int>> result;
        levelorder(root, result);
        return result;
    }
};
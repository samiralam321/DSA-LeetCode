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
    vector<int> largestValues(TreeNode* root) {
        if(root == NULL) return {};

        queue<TreeNode*> que;
        que.push(root);

        vector<int> result;

        while(!que.empty()){
            int n = que.size();
            int maxEl = INT_MIN;

            while(n--){
                TreeNode* curr = que.front();
                que.pop();

                maxEl = max(maxEl, curr->val);

                if(curr->left != NULL){
                    que.push(curr->left);
                }
                if(curr->right != NULL){
                    que.push(curr->right);
                }
            }
            result.push_back(maxEl);
        }
        return result;  
    }
};
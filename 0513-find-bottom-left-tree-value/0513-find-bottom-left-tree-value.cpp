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
    int findBottomLeftValue(TreeNode* root) {
        int ans;
        queue<TreeNode*> que;
        que.push(root);

        while(!que.empty()){
            int n = que.size();

            while(n--){
                TreeNode* node = que.front();
                que.pop();

                ans = node->val;

                if(node->right){
                    que.push(node->right);
                }
                if(node->left){
                    que.push(node->left);
                }
            }
        }
        return ans;
        
    }
};
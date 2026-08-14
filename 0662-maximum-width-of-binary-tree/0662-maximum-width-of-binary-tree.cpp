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
    typedef unsigned long long ll;
    int widthOfBinaryTree(TreeNode* root) {
        if(root == NULL) return 0;

        queue<pair<TreeNode*, ll>> que;
        que.push({root,0});

        ll maxWidth = 0;

        while(!que.empty()){
            int n = que.size();
            ll L = que.front().second;
            ll R = que.back().second;

            maxWidth = max(maxWidth, R-L+1);

            while(n--){
                TreeNode* curr = que.front().first;
                ll idx = que.front().second;
                que.pop();

                if(curr->left != NULL){
                    que.push({curr->left, 2*idx+1});
                }
                if(curr->right != NULL){
                    que.push({curr->right, 2*idx+2});
                }
            }
        }
        return maxWidth;  
    }
};
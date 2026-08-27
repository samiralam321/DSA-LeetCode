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
    vector<int> ans;

    void solve(TreeNode* root){
        if(root == NULL) return;

        solve(root->left);
        ans.push_back(root->val);
        solve(root->right);
    }

    vector<int> findMode(TreeNode* root) {
        solve(root);

        vector<int> result;

        int maxFreq = 0;
        int freq = 1;

        for(int i=0; i<ans.size(); i++){
            if(i > 0 && ans[i] == ans[i-1]){
                freq++;
            }
            else{
                freq = 1;
            }

            if(freq > maxFreq){
                maxFreq = freq;
                result.clear();
                result.push_back(ans[i]);
            }
            else if(freq == maxFreq){
                result.push_back(ans[i]);
            }
        }
        return result;
    }
};
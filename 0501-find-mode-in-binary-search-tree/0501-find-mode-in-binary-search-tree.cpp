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
        if(root == NULL){
            return;
        }

        solve(root->left);
        ans.push_back(root->val);
        solve(root->right);
    }

    vector<int> findMode(TreeNode* root) {
        solve(root);

        map<int,int> mp;
        for(int i=0; i<ans.size(); i++){
            mp[ans[i]]++;
        }

        int maxFreq = 0;

        for(auto it : mp){
            maxFreq = max(maxFreq, it.second);
        }
        vector<int> result;
        for(auto it : mp){
            if(it.second == maxFreq){
                result.push_back(it.first);
            }
        }
        return result;
    }
};
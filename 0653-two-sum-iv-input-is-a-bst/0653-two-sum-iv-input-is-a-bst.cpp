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
    bool solve(TreeNode* root, int target, unordered_set<int>& seen){
        if(root == NULL) return false;

        int need = target - root->val;

        if(seen.count(need)){
            return true;
        }

        seen.insert(root->val);

        return solve(root->left, target, seen) || solve(root->right, target, seen);
    }
    
    bool findTarget(TreeNode* root, int k) {
        unordered_set<int> seen;
        return solve(root, k, seen);
    }
};
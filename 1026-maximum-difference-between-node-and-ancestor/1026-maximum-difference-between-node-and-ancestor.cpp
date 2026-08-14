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
    int solve(TreeNode* root, int minVal,int maxVal){
        if(root == NULL){
            return abs(minVal - maxVal);
        }

        minVal = min(minVal, root->val);
        maxVal = max(maxVal, root->val);

        int left = solve(root->left, minVal, maxVal);
        int right = solve(root->right, minVal, maxVal);

        return max(left, right);
    }
    int maxAncestorDiff(TreeNode* root) {
        if(root == NULL) return NULL;
        return solve(root, root->val, root->val );  
    }
};
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
    int countNodes(TreeNode* root){
        if(root == NULL) return 0;

        return 1 + countNodes(root->left) + countNodes(root->right);
    }

    bool dfs(TreeNode* root, int idx, int totalNodes){
        if(root == NULL) return true;

        if(idx > totalNodes){
            return false;
        }

        bool left = dfs(root->left, 2*idx, totalNodes);
        bool right = dfs(root->right, 2*idx+1, totalNodes);

        return left && right;

    }

    bool isCompleteTree(TreeNode* root) {
        int totalNodes = countNodes(root);
        int i = 1;
        return dfs(root, i, totalNodes);
    }
};
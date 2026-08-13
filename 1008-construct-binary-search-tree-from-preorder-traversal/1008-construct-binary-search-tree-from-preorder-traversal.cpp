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
    TreeNode* solve(vector<int>& preorder, int start, int end){
        if(start > end) return NULL;

        int rootVal = preorder[start];

        TreeNode* root = new TreeNode(rootVal);

        int pos = start + 1;
        while(pos <= end && preorder[pos] < rootVal){
            pos++;
        }

        root->left = solve(preorder, start+1, pos-1);
        root->right = solve(preorder, pos, end);

        return root;
    }

    TreeNode* bstFromPreorder(vector<int>& preorder) {
        int n = preorder.size();

        return solve(preorder,0,n-1);
    }
};
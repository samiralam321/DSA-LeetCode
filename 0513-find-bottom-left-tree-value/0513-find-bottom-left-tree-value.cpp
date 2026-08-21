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

    int maxDepth = -1;
    vector<int> vec;

    void findDepth(TreeNode* root, int depth){
        if(root == NULL) return;

        maxDepth = max(maxDepth, depth);

        findDepth(root->left, depth+1);
        findDepth(root->right, depth+1);
    }

    void storeNode(TreeNode* root, int depth){
        if(root == NULL) return;

        if(depth == maxDepth){
            vec.push_back(root->val);
            return;
        }
        storeNode(root->left, depth+1);
        storeNode(root->right, depth+1);
    }

    int findBottomLeftValue(TreeNode* root) {
        findDepth(root,0);
        storeNode(root,0);

        return vec[0];
    }
};
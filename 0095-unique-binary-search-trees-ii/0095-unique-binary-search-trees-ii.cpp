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
    vector<TreeNode*> build(int lo, int hi){
        vector<TreeNode*> ans;

        if(lo > hi){
            ans.push_back(NULL);
            return ans;
        }

        for(int i=lo; i<=hi; i++){
            vector<TreeNode*> left = build(lo, i-1);
            vector<TreeNode*> right = build(i+1, hi);

            for(TreeNode* l : left){
                for(TreeNode* r : right){
                    TreeNode* root = new TreeNode(i);

                    root->left = l;
                    root->right = r;

                    ans.push_back(root);
                }
            }
        }
        return ans;
    }
    vector<TreeNode*> generateTrees(int n) {
        return build(1,n);
        
    }
};
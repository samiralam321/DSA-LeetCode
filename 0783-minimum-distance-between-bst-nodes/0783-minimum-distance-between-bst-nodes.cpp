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
    int minDiff = INT_MAX;

    void inorder(TreeNode* root, vector<int>& vec){
        if(root == NULL) return;

        inorder(root->left, vec);
        vec.push_back(root->val);
        inorder(root->right, vec);

        for(int i=1; i<vec.size(); i++){
            minDiff = min(minDiff, vec[i] - vec[i-1]);
        }
    }
    
    int minDiffInBST(TreeNode* root) {
        vector<int> vec;
        inorder(root, vec);
        return minDiff; 
    }
};
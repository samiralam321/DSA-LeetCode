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
    vector<int> arr;

    void inorder(TreeNode* root){
        if(root == NULL) return;

        inorder(root->left);
        arr.push_back(root->val);
        inorder(root->right);
    }

    void update(TreeNode* root){
        if(root == NULL) return;

        update(root->left);

        int sum = 0;

        for(int i=0; i<arr.size(); i++){
            if(arr[i] >= root->val){
                sum += arr[i];
            }
        }
        root->val = sum;
        update(root->right);
    }

    TreeNode* bstToGst(TreeNode* root) {
        inorder(root);
        update(root);
        return root;  
    }
};
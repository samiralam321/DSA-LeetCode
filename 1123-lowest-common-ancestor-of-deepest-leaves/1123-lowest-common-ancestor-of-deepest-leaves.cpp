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
// my approach 

// find maximum depth
// store all nodes at that maximum depth
// fidn the LCA of all those nodes




class Solution {
    public:
    int maxDepth(TreeNode* root){
        if(root == NULL) return 0;

        int left = maxDepth(root->left);
        int right = maxDepth(root->right);

        return 1 + max(left,right);
    }

    // store all nodes having maxium depth
    void findDeepest(TreeNode* root, int depth, int maxD, vector<TreeNode*> &arr) {
        if(root == NULL) return;

        if(depth == maxD){
            arr.push_back(root);
            return;
        }

        findDeepest(root->left, depth+1, maxD, arr);
        findDeepest(root->right, depth+1, maxD, arr);
    }

    TreeNode* LCA(TreeNode* root, TreeNode* p, TreeNode* q) {
        if(root == NULL) return NULL;

        if(root == p || root == q){
            return root;
        }

        TreeNode* left = LCA(root->left, p, q);
        TreeNode* right = LCA(root->right, p ,q);

        if(left != NULL && right != NULL){
            return root;
        }
        if(left != NULL){
            return left;
        }
        return right;
    }

    TreeNode* lcaDeepestLeaves(TreeNode* root){
        // find the maxium depth
        int maxD = maxDepth(root);

        // store deepest nodes
        vector<TreeNode*> arr;

        findDeepest(root,1, maxD, arr);

        // fidn LCA of all deepest nodes
        TreeNode* ans = arr[0];

        for(int i=1; i<arr.size(); i++){
            ans = LCA(root, ans, arr[i]);
        }
        return ans;
    }
};
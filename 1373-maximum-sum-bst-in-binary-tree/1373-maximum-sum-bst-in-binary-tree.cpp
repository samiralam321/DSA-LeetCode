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
    int ans = 0;

    int solve(TreeNode* root, int &mini, int &maxi, int &sum){
        if(root == NULL){
            mini = INT_MAX;
            maxi = INT_MIN;
            
            sum = 0;
            return 1;
        }

        int lmin, lmax, lsum;
        int rmin, rmax, rsum;

        int left = solve(root->left, lmin, lmax, lsum);
        int right = solve(root->right, rmin, rmax, rsum);

        if(left && right && root->val > lmax && root->val < rmin){
            sum = lsum + rsum + root->val;

            mini = min(root->val, lmin);
            maxi = max(root->val, rmax);

            ans = max(ans, sum);

            return 1;
        }
        return 0;
    }
    
    int maxSumBST(TreeNode* root) {
        int mini, maxi, sum;
        solve(root, mini, maxi, sum);
        return ans; 
    }
};